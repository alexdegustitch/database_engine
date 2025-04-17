#ifndef BPLUSTREE_H
#define BPLUSTREE_H

#include "IndexManager.h"
#include "FreeListManager.h"
#include "LeafNode.h"
#include "InternalNode.h"

#include <iostream>
#include <math.h>
#include <queue>
#include "../query/condition/ConditionTree.h"

class BPlusTree
{
private:
    int maxKeys;
    uint64_t rootOffset;
    std::fstream file;

    LeafNode *findLeaf(int key)
    {
        std::cout << "Find Leaf method" << std::endl;
        // std::cout << rootOffset << std::endl;
        Node *curr = IndexManager::readNode(file, rootOffset, maxKeys);
        while (!curr->isLeaf)
        {
            int idx = std::upper_bound(curr->keys.begin(), curr->keys.end(), key - 1) - curr->keys.begin();
            curr = IndexManager::readNode(file, static_cast<InternalNode *>(curr)->children[idx], maxKeys);
        }
        return static_cast<LeafNode *>(curr);
    }

    LeafNode *findLeftmostLeaf()
    {
        std::cout << "Find Leftmost Leaf method" << std::endl;
        Node *curr = IndexManager::readNode(file, rootOffset, maxKeys);
        while (!curr->isLeaf)
        {
            curr = IndexManager::readNode(file, static_cast<InternalNode *>(curr)->children.front(), maxKeys);
        }
        return static_cast<LeafNode *>(curr);
    }

    void splitLeaf(uint64_t leafOffset)
    {
        std::cout << "Split Leaf method" << std::endl;
        LeafNode *leaf = static_cast<LeafNode *>(IndexManager::readNode(file, leafOffset, maxKeys));
        int mid = leaf->keys.size() / 2;

        LeafNode *newLeaf = new LeafNode(FreeListManager::allocateNode(file));

        newLeaf->keys.assign(leaf->keys.begin() + mid, leaf->keys.end());
        leaf->keys.resize(mid);

        newLeaf->dataReference.assign(leaf->dataReference.begin() + mid, leaf->dataReference.end());
        leaf->dataReference.resize(mid);

        newLeaf->next = leaf->next;
        leaf->next = newLeaf->offset;

        newLeaf->parent = leaf->parent;

        // std::cout << "Leaf offsets ares: Leaf: " << leafOffset << "New leaf: " << newLeaf->offset << std::endl;
        IndexManager::writeNode(file, leafOffset, leaf, maxKeys);
        IndexManager::writeNode(file, newLeaf->offset, newLeaf, maxKeys);
        insertIntoParent(leafOffset, leaf->keys.back(), newLeaf->offset);
    }

    void splitInternalNode(uint64_t nodeOffset)
    {
        std::cout << "Split Internal Node method" << std::endl;
        InternalNode *node = static_cast<InternalNode *>(IndexManager::readNode(file, nodeOffset, maxKeys));

        int mid = node->keys.size() / 2;

        uint64_t newNodeOffset = FreeListManager::allocateNode(file);
        InternalNode *newNode = new InternalNode(newNodeOffset);

        newNode->keys.assign(node->keys.begin() + mid + 1, node->keys.end());
        newNode->children.assign(node->children.begin() + mid + 1, node->children.end());

        int key = node->keys[mid];
        node->keys.resize(mid);
        node->children.resize(mid + 1);

        for (uint64_t childOffset : newNode->children)
        {
            Node *child = IndexManager::readNode(file, childOffset, maxKeys);
            child->parent = newNode->offset;
            IndexManager::writeNode(file, childOffset, child, maxKeys);
        }
        newNode->parent = node->parent;

        IndexManager::writeNode(file, nodeOffset, node, maxKeys);
        IndexManager::writeNode(file, newNodeOffset, newNode, maxKeys);

        insertIntoParent(nodeOffset, key, newNodeOffset);
    }

    void insertIntoParent(uint64_t leafOffset, int key, uint64_t newLeafOffset)
    {
        std::cout << "Insert Into Parent method" << std::endl;
        LeafNode *leaf = static_cast<LeafNode *>(IndexManager::readNode(file, leafOffset, maxKeys));
        LeafNode *newLeaf = static_cast<LeafNode *>(IndexManager::readNode(file, newLeafOffset, maxKeys));

        if (leafOffset == rootOffset)
        {
            std::cout << "Old root: " << rootOffset << ", and new root: ";
            rootOffset = FreeListManager::allocateNode(file);
            std::cout << rootOffset << " and after the change it is: ";
            IndexManager::writeRootOffset(file, rootOffset);
            std::cout << IndexManager::readRootOffset(file) << std::endl;
            // InternalNode *root = static_cast<InternalNode *>(IndexManager::readNode(file, rootOffset, maxKeys));
            InternalNode *root = new InternalNode(rootOffset);
            root->keys.push_back(key);
            root->children.push_back(leafOffset);
            root->children.push_back(newLeafOffset);
            root->offset = rootOffset;
            leaf->parent = rootOffset;
            newLeaf->parent = rootOffset;
            IndexManager::writeNode(file, rootOffset, root, maxKeys);
            IndexManager::writeNode(file, leafOffset, leaf, maxKeys);
            IndexManager::writeNode(file, newLeafOffset, newLeaf, maxKeys);

            InternalNode *newRoot = static_cast<InternalNode *>(IndexManager::readNode(file, rootOffset, maxKeys));
            for (uint64_t child : newRoot->children)
            {
                std::cout << "Child: " << child << ", ";
            }
            std::cout << std::endl;
            return;
        }

        InternalNode *parent = static_cast<InternalNode *>(IndexManager::readNode(file, leaf->parent, maxKeys));
        int idx = std::lower_bound(parent->keys.begin(), parent->keys.end(), key) - parent->keys.begin();
        parent->keys.insert(parent->keys.begin() + idx, key);
        parent->children.insert(parent->children.begin() + idx + 1, newLeafOffset);
        IndexManager::writeNode(file, leaf->parent, parent, maxKeys);

        if (parent->keys.size() > maxKeys)
        {
            splitInternalNode(parent->offset);
        }
    }

    uint64_t findLeftSibling(uint64_t currOffset)
    {
        std::cout << "FindLeftSibling method" << std::endl;
        Node *curr = IndexManager::readNode(file, currOffset, maxKeys);
        InternalNode *parent = static_cast<InternalNode *>(IndexManager::readNode(file, curr->parent, maxKeys));
        if (!parent)
        {
            return 0;
        }
        int idx = std::find(parent->children.begin(), parent->children.end(), currOffset) - parent->children.begin();
        // int idx = std::lower_bound(parent->keys.begin(), parent->keys.end(), curr->keys.back()) - parent->keys.begin();
        if (idx == 0)
        {
            return 0;
        }
        return parent->children[idx - 1];
    }

    uint64_t findRightSibling(uint64_t currOffset)
    {
        std::cout << "FindRightSibling method" << std::endl;
        Node *curr = IndexManager::readNode(file, currOffset, maxKeys);
        InternalNode *parent = static_cast<InternalNode *>(IndexManager::readNode(file, curr->parent, maxKeys));

        auto it = std::find(parent->children.begin(), parent->children.end(), currOffset);
        if (it != parent->children.end())
        {
            int idx = it - parent->children.begin();
            if (idx < parent->children.size() - 1)
            {
                return parent->children[idx + 1];
            }
        }

        return 0;
    }

    void handleUnderflow(uint64_t nodeOffset)
    {
        std::cout << "HandleUnderflow method" << std::endl;

        Node *node = IndexManager::readNode(file, nodeOffset, maxKeys);
        if (nodeOffset == rootOffset)
        {
            if (!node->isLeaf && static_cast<InternalNode *>(node)->children.size() == 1)
            {
                FreeListManager::freeNode(file, rootOffset);
                std::cout << "Old root value: " << rootOffset << " and new root value is: ";
                rootOffset = static_cast<InternalNode *>(node)->children[0];
                std::cout << rootOffset << " and after the change it is: ";
                IndexManager::writeRootOffset(file, rootOffset);
                std::cout << IndexManager::readRootOffset(file) << std::endl;
                InternalNode *root = static_cast<InternalNode *>(IndexManager::readNode(file, rootOffset, maxKeys));

                root->parent = 0;
                root->offset = rootOffset;
                // root->isLeaf = true;
                static_cast<InternalNode *>(node)->children.clear();

                IndexManager::writeNode(file, rootOffset, root, maxKeys);
                IndexManager::writeNode(file, nodeOffset, node, maxKeys);
                delete node;
            }
            return;
        }

        u_int64_t leftSiblingOffset = findLeftSibling(nodeOffset);

        if (leftSiblingOffset != 0)
        {
            Node *leftSibling = IndexManager::readNode(file, leftSiblingOffset, maxKeys);
            if (node->isLeaf && leftSibling->keys.size() > ceil(maxKeys / 2.0))
            {
                borrowFromLeftSibling(nodeOffset, leftSiblingOffset);
                return;
            }
            else if (!node->isLeaf && leftSibling->keys.size() > (ceil((maxKeys + 1) / 2.0) - 1))
            {
                borrowFromLeftInternalSibling(nodeOffset, leftSiblingOffset);
                return;
            }
        }
        uint64_t rightSiblingOffset = findRightSibling(nodeOffset);

        if (rightSiblingOffset != 0)
        {
            Node *rightSibling = IndexManager::readNode(file, rightSiblingOffset, maxKeys);

            if (node->isLeaf && rightSibling->keys.size() > ceil(maxKeys / 2.0))
            {
                borrowFromRightSibling(nodeOffset, rightSiblingOffset);
                return;
            }
            else if (!node->isLeaf && rightSibling->keys.size() > (ceil((maxKeys + 1) / 2.0) - 1))
            {
                borrowFromRightInternalSibling(nodeOffset, rightSiblingOffset);
                return;
            }
        }

        if (leftSiblingOffset == 0)
        {
            leftSiblingOffset = nodeOffset;
            nodeOffset = rightSiblingOffset;
        }
        if (node->isLeaf)
        {
            mergeLeafNodes(nodeOffset, leftSiblingOffset);
        }
        else
        {
            mergeInternalNodes(nodeOffset, leftSiblingOffset);
        }
    }

    void borrowFromLeftSibling(uint64_t currOffset, uint64_t leftSiblingOffset)
    {
        std::cout << "BorrowFromLeftSibling method" << std::endl;
        LeafNode *curr = static_cast<LeafNode *>(IndexManager::readNode(file, currOffset, maxKeys));
        LeafNode *leftSibling = static_cast<LeafNode *>(IndexManager::readNode(file, leftSiblingOffset, maxKeys));

        uint64_t parentOffset = curr->parent;
        InternalNode *parent = static_cast<InternalNode *>(IndexManager::readNode(file, parentOffset, maxKeys));

        int key = leftSibling->keys.back();
        int idx = std::lower_bound(parent->keys.begin(), parent->keys.end(), key) - parent->keys.begin();

        curr->keys.insert(curr->keys.begin(), key);
        curr->dataReference.insert(curr->dataReference.begin(), {key, key});

        leftSibling->keys.pop_back();
        leftSibling->dataReference.pop_back();

        parent->keys[idx] = leftSibling->keys.back();

        std::cout << "Parent key: " << std::endl;
        for (auto c : parent->keys)
        {
            std::cout << c << " ";
        }
        std::cout << std::endl;
        std::cout << "Left Sibling key: " << std::endl;
        for (auto c : leftSibling->keys)
        {
            std::cout << c << " ";
        }
        std::cout << std::endl;
        std::cout << "Curr Node key: " << std::endl;
        for (auto c : curr->keys)
        {
            std::cout << c << " ";
        }
        std::cout << std::endl;
        IndexManager::writeNode(file, currOffset, curr, maxKeys);
        IndexManager::writeNode(file, leftSiblingOffset, leftSibling, maxKeys);
        IndexManager::writeNode(file, parentOffset, parent, maxKeys);
    }

    void borrowFromLeftInternalSibling(uint64_t currOffset, uint64_t leftSiblingOffset)
    {
        std::cout << "BorromFromLeftInternalSibling method" << std::endl;

        InternalNode *curr = static_cast<InternalNode *>(IndexManager::readNode(file, currOffset, maxKeys));
        InternalNode *leftSibling = static_cast<InternalNode *>(IndexManager::readNode(file, leftSiblingOffset, maxKeys));
        Node *parent = IndexManager::readNode(file, curr->parent, maxKeys);
        int idx = std::upper_bound(parent->keys.begin(), parent->keys.end(), leftSibling->keys.back()) - parent->keys.begin();

        curr->keys.insert(curr->keys.begin(), parent->keys[idx]);
        parent->keys[idx] = leftSibling->keys.back();

        /*if (!IndexManager::readNode(file, leftSibling->children.back(), maxKeys)->isLeaf)
        {
            for (uint64_t childOffset : static_cast<InternalNode *>(IndexManager::readNode(file, leftSibling->children.back(), maxKeys))->children)
            {
                Node *child = IndexManager::readNode(file, childOffset, maxKeys);
                child->parent = currOffset;
                IndexManager::writeNode(file, childOffset, child, maxKeys);
            }
        }*/

        Node *backChild = IndexManager::readNode(file, leftSibling->children.back(), maxKeys);
        backChild->parent = currOffset;
        IndexManager::writeNode(file, backChild->offset, backChild, maxKeys);

        curr->children.insert(curr->children.begin(), leftSibling->children.back());
        leftSibling->children.pop_back();
        leftSibling->keys.pop_back();

        IndexManager::writeNode(file, currOffset, curr, maxKeys);
        IndexManager::writeNode(file, leftSiblingOffset, leftSibling, maxKeys);
        IndexManager::writeNode(file, parent->offset, parent, maxKeys);
    }

    void borrowFromRightSibling(uint64_t currOffset, uint64_t rightSiblingOffset)
    {
        std::cout << "BorrowFromRightSibling method" << std::endl;

        LeafNode *rightSibling = static_cast<LeafNode *>(IndexManager::readNode(file, rightSiblingOffset, maxKeys));
        LeafNode *curr = static_cast<LeafNode *>(IndexManager::readNode(file, currOffset, maxKeys));
        Node *parent = IndexManager::readNode(file, curr->parent, maxKeys);

        int key = curr->keys.back();
        int idx = std::lower_bound(parent->keys.begin(), parent->keys.end(), key) - parent->keys.begin();

        curr->keys.push_back(rightSibling->keys.front());
        curr->dataReference.push_back(rightSibling->dataReference.front());

        rightSibling->keys.erase(rightSibling->keys.begin());
        rightSibling->dataReference.erase(rightSibling->dataReference.begin());

        parent->keys[idx] = curr->keys.back();

        IndexManager::writeNode(file, currOffset, curr, maxKeys);
        IndexManager::writeNode(file, rightSiblingOffset, rightSibling, maxKeys);
        IndexManager::writeNode(file, parent->offset, parent, maxKeys);
    }

    void borrowFromRightInternalSibling(uint64_t currOffset, uint64_t rightSiblingOffset)
    {
        std::cout << "BorrowFromRightInternalSibling method" << std::endl;

        InternalNode *curr = static_cast<InternalNode *>(IndexManager::readNode(file, currOffset, maxKeys));
        InternalNode *rightSibling = static_cast<InternalNode *>(IndexManager::readNode(file, rightSiblingOffset, maxKeys));
        InternalNode *parent = static_cast<InternalNode *>(IndexManager::readNode(file, curr->parent, maxKeys));

        std::cout << "RIGHT SIBLING: ";
        for (auto c : rightSibling->keys)
        {
            std::cout << c << " ";
        }
        std::cout << std::endl;
        std::cout << "NODE: ";
        for (auto c : curr->keys)
        {
            std::cout << c << " ";
        }
        std::cout << std::endl;
        std::cout << "PARENT: ";
        for (auto c : parent->keys)
        {
            std::cout << c << " ";
        }
        std::cout << std::endl;
        int idx = std::upper_bound(parent->keys.begin(), parent->keys.end(), curr->keys.back()) - parent->keys.begin();

        /*if (!IndexManager::readNode(file, rightSibling->children.front(), maxKeys)->isLeaf)
        {
            for (uint64_t childOffset : static_cast<InternalNode *>(IndexManager::readNode(file, rightSibling->children.front(), maxKeys))->children)
            {
                Node *child = IndexManager::readNode(file, childOffset, maxKeys);
                child->parent = currOffset;
                IndexManager::writeNode(file, childOffset, child, maxKeys);
            }
        }*/

        Node *frontChild = IndexManager::readNode(file, rightSibling->children[0], maxKeys);
        frontChild->parent = currOffset;
        IndexManager::writeNode(file, frontChild->offset, frontChild, maxKeys);
        curr->children.push_back(rightSibling->children[0]);
        curr->keys.push_back(parent->keys[idx]);

        parent->keys[idx] = rightSibling->keys[0];
        rightSibling->keys.erase(rightSibling->keys.begin());
        rightSibling->children.erase(rightSibling->children.begin());

        IndexManager::writeNode(file, currOffset, curr, maxKeys);
        IndexManager::writeNode(file, rightSiblingOffset, rightSibling, maxKeys);
        IndexManager::writeNode(file, parent->offset, parent, maxKeys);
    }

    void mergeLeafNodes(uint64_t nodeOffset, uint64_t leftSiblingOffset)
    {
        std::cout << "MergeLeafNodes method" << std::endl;

        LeafNode *node = static_cast<LeafNode *>(IndexManager::readNode(file, nodeOffset, maxKeys));
        LeafNode *leftSibling = static_cast<LeafNode *>(IndexManager::readNode(file, leftSiblingOffset, maxKeys));
        InternalNode *parent = static_cast<InternalNode *>(IndexManager::readNode(file, node->parent, maxKeys));

        if (leftSiblingOffset != 0)
        {
            auto it = std::lower_bound(parent->keys.begin(), parent->keys.end(), leftSibling->keys.back());
            parent->keys.erase(it);
            leftSibling->keys.insert(leftSibling->keys.end(), node->keys.begin(), node->keys.end());
            leftSibling->dataReference.insert(leftSibling->dataReference.end(), node->dataReference.begin(), node->dataReference.end());
            auto itChild = std::find(parent->children.begin(), parent->children.end(), nodeOffset);
            if (itChild != parent->children.end())
            {
                parent->children.erase(itChild);
            }
            else
            {
                std::cout << "No child found!" << std::endl;
            }

            leftSibling->next = node->next;
            node->next = 0;
            delete node;
            // IndexManager::writeNode(file, nodeOffset, node, maxKeys);
            FreeListManager::freeNode(file, nodeOffset);
            IndexManager::writeNode(file, leftSiblingOffset, leftSibling, maxKeys);
            IndexManager::writeNode(file, parent->offset, parent, maxKeys);
            // FreeListManager::freeNode(file, nodeOffset);
        }

        if (parent->keys.size() < (ceil((maxKeys + 1) / 2.0) - 1))
        {
            handleUnderflow(parent->offset);
        }
    }

    void mergeInternalNodes(uint64_t nodeOffset, uint64_t leftSiblingOffset)
    {
        std::cout << "MergeInternalNodes method" << std::endl;

        InternalNode *node = static_cast<InternalNode *>(IndexManager::readNode(file, nodeOffset, maxKeys));
        InternalNode *leftSibling = static_cast<InternalNode *>(IndexManager::readNode(file, leftSiblingOffset, maxKeys));
        InternalNode *parent = static_cast<InternalNode *>(IndexManager::readNode(file, node->parent, maxKeys));

        auto it = std::upper_bound(parent->keys.begin(), parent->keys.end(), leftSibling->keys.back());
        int idx = it - parent->keys.begin();
        int key = parent->keys[idx];

        leftSibling->keys.push_back(key);
        leftSibling->keys.insert(leftSibling->keys.end(), node->keys.begin(), node->keys.end());
        for (uint64_t childOffset : node->children)
        {
            Node *child = IndexManager::readNode(file, childOffset, maxKeys);
            child->parent = leftSiblingOffset;
            IndexManager::writeNode(file, childOffset, child, maxKeys);

            /*for (auto k : child->keys)
            {
                std::cout << "Key in node: " << k << " ";
            }
            std::cout << std::endl;*/
        }

        leftSibling->children.insert(leftSibling->children.end(), node->children.begin(), node->children.end());
        // std::cout << "NUM CHILDREN:" << leftSibling->children.size() << std::endl;

        parent->keys.erase(it);
        auto itChild = std::find(parent->children.begin(), parent->children.end(), nodeOffset);
        if (itChild != parent->children.end())
        {
            parent->children.erase(itChild);
        }
        else
        {
            std::cout << "No child found!" << std::endl;
        }
        /*for (auto c : leftSibling->children)
        {
            std::cout << "Printing keys!" << std::endl;
            for (auto k : c->keys)
            {
                std::cout << "Key: " << k << " ";
            }
            std::cout << std::endl;
        }*/
        // node->children.clear();
        // leftSibling->next = node->next;
        // node->next = nullptr;
        node->children.clear();
        delete node;
        IndexManager::writeNode(file, nodeOffset, node, maxKeys);
        IndexManager::writeNode(file, leftSiblingOffset, leftSibling, maxKeys);
        IndexManager::writeNode(file, parent->offset, parent, maxKeys);
        FreeListManager::freeNode(file, nodeOffset);

        if (parent->keys.size() < (ceil((maxKeys + 1) / 2.0) - 1))
        {
            handleUnderflow(parent->offset);
        }
    }

public:
    BPlusTree(const std::string &filePath, int maxKeys = 3) : maxKeys(maxKeys)
    {
        file.open(filePath, std::ios::in | std::ios::out | std::ios::binary);
        if (!file)
        {
            file.open(filePath, std::ios::trunc | std::ios::out | std::ios::binary);
            // std::cout << "File is opened!" << std::endl;
            IndexManager::initializeIndexFile(file, maxKeys);
            file.close();

            file.open(filePath, std::ios::in | std::ios::out | std::ios::binary);

            if (!file)
            {
                std::cout << "File not opened!" << std::endl;
            }
            else
            {
                std::cout << IndexManager::readRootOffset(file) << std::endl;
            }
            rootOffset = FreeListManager::allocateNode(file);
            std::cout << rootOffset << std::endl;
            LeafNode *root = new LeafNode(rootOffset);
            root->isLeaf = true;
            root->offset = rootOffset;
            IndexManager::writeNode(file, rootOffset, root, maxKeys);
            IndexManager::writeRootOffset(file, rootOffset);
            delete root;
        }
        else
        {
            IndexFileHeader header = IndexManager::readIndexHeader(file);
            maxKeys = header.maxKeys;
            rootOffset = IndexManager::readRootOffset(file);
            std::cout << "ROOT JE: " << rootOffset << std::endl;
        }
        // std::filesystem::path absPath = std::filesystem::absolute(filePath);
        // std::cout << absPath << std::endl;
        // file.close();
    }

    ~BPlusTree()
    {
        file.close();
    }

    int getMaxKeys()
    {
        return maxKeys;
    }

    std::vector<std::pair<uint64_t, uint64_t>> search(int key)
    {
        std::cout << "Search method" << std::endl;
        LeafNode *leaf = findLeaf(key);

        std::vector<std::pair<uint64_t, uint64_t>> res;
        int idx = std::lower_bound(leaf->keys.begin(), leaf->keys.end(), key) - leaf->keys.begin();
        while (idx < leaf->keys.size() && leaf->keys[idx] == key)
        {
            res.push_back(leaf->dataReference[idx]);
            ++idx;
            if (idx == leaf->keys.size())
            {
                leaf = static_cast<LeafNode *>(IndexManager::readNode(file, leaf->next, maxKeys));
                if (leaf == 0)
                {
                    break;
                }
                idx = 0;
            }
        }

        return res;
    }

    std::vector<std::pair<uint64_t, uint64_t>> searchRangeStartEnd(int keyStart, COMPARISON_OP startOp, int keyEnd, COMPARISON_OP endOp)
    {
        std::cout << "Search Range Start End method" << std::endl;
        LeafNode *leaf = findLeaf(keyStart);

        std::vector<std::pair<uint64_t, uint64_t>> res;
        int idx = std::lower_bound(leaf->keys.begin(), leaf->keys.end(), keyStart) - leaf->keys.begin();
        while (idx < leaf->keys.size() && leaf->keys[idx] >= keyStart && leaf->keys[idx] <= keyEnd)
        {
            if (((startOp == COMPARISON_OP::GE && leaf->keys[idx] >= keyStart) || (startOp == COMPARISON_OP::GT && leaf->keys[idx] > keyStart)) &&
                ((endOp == COMPARISON_OP::LE && leaf->keys[idx] <= keyEnd) || (endOp == COMPARISON_OP::LT && leaf->keys[idx] < keyEnd)))
            {
                res.push_back(leaf->dataReference[idx]);
            }
            ++idx;
            if (idx == leaf->keys.size())
            {
                leaf = static_cast<LeafNode *>(IndexManager::readNode(file, leaf->next, maxKeys));
                if (leaf == 0)
                {
                    break;
                }
                idx = 0;
            }
        }

        return res;
    }

    std::vector<std::pair<uint64_t, uint64_t>> searchRangeStart(int keyStart, COMPARISON_OP startOp)
    {

        std::cout << "Search Range Start method" << std::endl;
        LeafNode *leaf = findLeaf(keyStart);

        std::vector<std::pair<uint64_t, uint64_t>> res;
        int idx = std::lower_bound(leaf->keys.begin(), leaf->keys.end(), keyStart) - leaf->keys.begin();
        while (idx < leaf->keys.size() && leaf->keys[idx] >= keyStart)
        {
            if ((startOp == COMPARISON_OP::GE && leaf->keys[idx] >= keyStart) || (startOp == COMPARISON_OP::GT && leaf->keys[idx] > keyStart))
            {
                res.push_back(leaf->dataReference[idx]);
            }
            ++idx;
            if (idx == leaf->keys.size())
            {
                leaf = static_cast<LeafNode *>(IndexManager::readNode(file, leaf->next, maxKeys));
                if (leaf == 0)
                {
                    break;
                }
                idx = 0;
            }
        }

        return res;
    }

    std::vector<std::pair<uint64_t, uint64_t>> searchRangeEnd(int keyEnd, COMPARISON_OP endOp)
    {
        std::cout << "Search Range End method" << std::endl;
        LeafNode *leaf = findLeftmostLeaf();

        std::vector<std::pair<uint64_t, uint64_t>> res;
        int idx = 0;
        while (idx < leaf->keys.size() && leaf->keys[idx] <= keyEnd)
        {
            if ((endOp == COMPARISON_OP::LE && leaf->keys[idx] <= keyEnd) || (endOp == COMPARISON_OP::LT && leaf->keys[idx] < keyEnd))
            {
                res.push_back(leaf->dataReference[idx]);
            }
            ++idx;
            if (idx == leaf->keys.size())
            {
                leaf = static_cast<LeafNode *>(IndexManager::readNode(file, leaf->next, maxKeys));
                if (leaf == 0)
                {
                    break;
                }
                idx = 0;
            }
        }

        return res;
    }

    void insert(int key, uint64_t pageId, uint64_t slotIdx)
    {
        std::cout << "Insert method" << std::endl;
        std::cout << "Key: " << key << ", pageId: " << pageId << ", offset: " << slotIdx << std::endl;
        LeafNode *leaf = findLeaf(key);
        auto it = std::lower_bound(leaf->keys.begin(), leaf->keys.end(), key);
        leaf->keys.insert(it, key);
        leaf->dataReference.push_back({pageId, slotIdx});
        IndexManager::writeNode(file, leaf->offset, leaf, maxKeys);
        if (leaf->keys.size() > maxKeys)
        {
            splitLeaf(leaf->offset);
        }
        std::cout << "Insert method done" << std::endl;
    }

    int deleteKey(int key)
    {
        std::cout << "DeleteKey method" << std::endl;
        LeafNode *leaf = findLeaf(key);

        auto it = std::find(leaf->keys.begin(), leaf->keys.end(), key);
        if (it == leaf->keys.end())
        {
            std::cout << "Key not found" << std::endl;
            return 0;
        }
        int idx = it - leaf->keys.begin();
        Node *parent = IndexManager::readNode(file, leaf->parent, maxKeys);
        // the rightmost in the leaf
        if (parent != nullptr && idx > 0 && idx == leaf->keys.size() - 1)
        {
            auto itPar = std::lower_bound(parent->keys.begin(), parent->keys.end(), key);
            if (itPar != parent->keys.end())
            {
                int idx_parent = itPar - parent->keys.begin();
                parent->keys[idx_parent] = leaf->keys[idx - 1];
            }
        }

        leaf->keys.erase(it);
        leaf->dataReference.erase(leaf->dataReference.begin() + idx);
        /*for (int c : leaf->keys)
        {
            std::cout << c << std::endl;
        }
        for (int c : leaf->parent->keys)
        {
            std::cout << c << std::endl;
        }*/

        IndexManager::writeNode(file, leaf->offset, leaf, maxKeys);
        if (parent != nullptr)
        {
            IndexManager::writeNode(file, parent->offset, parent, maxKeys);
        }
        if (leaf->keys.size() < ceil(maxKeys / 2.0))
        {
            handleUnderflow(leaf->offset);
        }
        int numDeleted = 1;
        numDeleted += deleteKey(key);
        return numDeleted;
    }

    int deleteKey(int key, uint64_t pageId, uint64_t slotIdx)
    {
        std::cout << "DeleteKey method" << std::endl;
        LeafNode *leaf = findLeaf(key);

        auto it = std::find(leaf->keys.begin(), leaf->keys.end(), key);
        int idx = it - leaf->keys.begin();
        bool found = false;
        while (!found && leaf)
        {
            for (int i = idx; i < leaf->keys.size(); ++i, ++it)
            {
                if (leaf->dataReference[i].first == pageId && leaf->dataReference[i].second == slotIdx)
                {
                    found = true;
                    idx = i;
                    break;
                }
            }
            if (found)
            {
                break;
            }
            found = false;
            idx = 0;
            leaf = static_cast<LeafNode *>(IndexManager::readNode(file, leaf->next, maxKeys));
            if (leaf)
            {
                it = leaf->keys.begin();
            }
        }
        if (!found)
        {
            std::cout << "Key not found Error!! key = " << key << std::endl;
            return 0;
        }
        std::cout << "Key found!!! -> key: " << leaf->keys[idx] << " page id: " << leaf->dataReference[idx].first << " slot idx: " << leaf->dataReference[idx].second << " *it = " << *it << std::endl;
        // int idx = it - leaf->keys.begin();
        Node *parent = IndexManager::readNode(file, leaf->parent, maxKeys);
        // the rightmost in the leaf
        if (parent != nullptr && idx > 0 && idx == leaf->keys.size() - 1)
        {
            auto itPar = std::lower_bound(parent->keys.begin(), parent->keys.end(), key);
            if (itPar != parent->keys.end())
            {
                int idx_parent = itPar - parent->keys.begin();
                parent->keys[idx_parent] = leaf->keys[idx - 1];
            }
        }

        leaf->keys.erase(it);
        leaf->dataReference.erase(leaf->dataReference.begin() + idx);
        /*for (int c : leaf->keys)
        {
            std::cout << c << std::endl;
        }
        for (int c : leaf->parent->keys)
        {
            std::cout << c << std::endl;
        }*/

        IndexManager::writeNode(file, leaf->offset, leaf, maxKeys);
        if (parent != nullptr)
        {
            IndexManager::writeNode(file, parent->offset, parent, maxKeys);
        }
        if (leaf->keys.size() < ceil(maxKeys / 2.0))
        {
            handleUnderflow(leaf->offset);
        }
        int numDeleted = 1;
        return numDeleted;
    }

    int deleteRangeOfKeys(int keyStart, int keyEnd)
    {
        std::cout << "DeleteRangeOfKeys method" << std::endl;

        int nextKey = keyStart;
        int currKey;
        bool nextLess = true;
        int numDeleted = 0;
        while (nextLess)
        {
            currKey = nextKey;
            LeafNode *leaf = findLeaf(currKey);
            auto it = std::lower_bound(leaf->keys.begin(), leaf->keys.end(), currKey);
            if (it == leaf->keys.end())
            {
                return numDeleted;
            }
            int idx = it - leaf->keys.begin();
            currKey = leaf->keys[idx];
            if (currKey > keyEnd)
            {
                return numDeleted;
            }
            if (idx + 1 < leaf->keys.size())
            {
                nextKey = leaf->keys[idx + 1];
            }
            else if (leaf->next != 0)
            {
                nextKey = IndexManager::readNode(file, leaf->next, maxKeys)->keys[0];
            }
            else
            {
                nextLess = false;
            }
            Node *parent = IndexManager::readNode(file, leaf->parent, maxKeys);
            // the rightmost in the leaf
            if (parent != nullptr && idx > 0 && idx == leaf->keys.size() - 1)
            {
                auto itPar = std::lower_bound(parent->keys.begin(), parent->keys.end(), currKey);
                if (itPar != parent->keys.end())
                {
                    int idx_parent = itPar - parent->keys.begin();
                    parent->keys[idx_parent] = leaf->keys[idx - 1];
                }
            }

            leaf->keys.erase(it);
            leaf->dataReference.erase(leaf->dataReference.begin() + idx);
            numDeleted++;
            IndexManager::writeNode(file, leaf->offset, leaf, maxKeys);
            if (parent != nullptr)
            {
                IndexManager::writeNode(file, parent->offset, parent, maxKeys);
            }
            if (leaf->keys.size() < ceil(maxKeys / 2.0))
            {
                handleUnderflow(leaf->offset);
            }
            // delete_key(key);
        }
        return numDeleted;
    }

    void printLeaves()
    {
        Node *curr = IndexManager::readNode(file, rootOffset, maxKeys);
        while (!curr->isLeaf)
        {
            curr = IndexManager::readNode(file, static_cast<InternalNode *>(curr)->children.front(), maxKeys);
        }
        std::cout << "[ ";
        while (curr != 0)
        {
            for (int key : curr->keys)
            {
                std::cout << key << " ";
            }
            curr = IndexManager::readNode(file, static_cast<LeafNode *>(curr)->next, maxKeys);
        }
        std::cout << "]" << std::endl;
    }

    std::vector<std::pair<uint64_t, uint64_t>> getAllLeaves()
    {
        Node *curr = IndexManager::readNode(file, rootOffset, maxKeys);
        while (!curr->isLeaf)
        {
            curr = IndexManager::readNode(file, static_cast<InternalNode *>(curr)->children.front(), maxKeys);
        }
        // std::cout << "[ ";
        std::vector<std::pair<uint64_t, uint64_t>> res;
        LeafNode *leafNode = static_cast<LeafNode *>(curr);
        while (leafNode != 0)
        {
            for (auto p : leafNode->dataReference)
            {
                // std::cout << key << " ";
                res.push_back(p);
            }
            leafNode = static_cast<LeafNode *>(IndexManager::readNode(file, leafNode->next, maxKeys));
        }
        // std::cout << "]" << std::endl;
        return res;
    }

    void eraseTree()
    {
        IndexFileHeader header = IndexManager::readIndexHeader(file);
        FreeList list = FreeListManager::readFreeList(file, header.freeListOffset);
        list.freeNodeCount = 0;
        FreeListManager::writeFreeList(file, list, header.freeListOffset);

        rootOffset = FreeListManager::allocateNode(file);
        std::cout << rootOffset << std::endl;
        LeafNode *root = new LeafNode(rootOffset);
        root->isLeaf = true;
        root->offset = rootOffset;
        IndexManager::writeNode(file, rootOffset, root, maxKeys);
        IndexManager::writeRootOffset(file, rootOffset);
        delete root;
    }

    void printBPlusTree()
    {
        if (rootOffset == 0)
            return;

        std::queue<uint64_t> q;
        q.push(rootOffset);

        while (!q.empty())
        {
            int levelSize = q.size();

            // Print all nodes at the current level
            for (int i = 0; i < levelSize; i++)
            {
                uint64_t nodeOffset = q.front();
                Node *node = IndexManager::readNode(file, nodeOffset, maxKeys);
                q.pop();

                // Print keys of the current node
                std::cout << "[ ";
                for (int key : node->keys)
                    std::cout << key << " ";
                std::cout << "]  ";

                // Add children to queue if it's an internal node
                if (!node->isLeaf)
                {
                    for (uint64_t child : static_cast<InternalNode *>(node)->children)
                        q.push(child);
                }
            }
            std::cout << std::endl; // Move to next level
        }
    }
};

#endif