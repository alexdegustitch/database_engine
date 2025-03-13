# Compiler and Flags
CXX = g++
CXXFLAGS = -std=c++20 -I/usr/local/include/antlr4-runtime -MMD -MP
LDFLAGS = -L/usr/local/lib -lantlr4-runtime

# ANTLR Variables
ANTLR_JAR = ~/Desktop/cppApps/antlr/antlr-4.13.2-complete.jar
ANTLR_GEN_DIR = src/antlr
ANTLR_FILES = $(ANTLR_GEN_DIR)/SQLLexer.cpp $(ANTLR_GEN_DIR)/SQLParser.cpp $(ANTLR_GEN_DIR)/SQLBaseVisitor.cpp

# B Plus Tree Files
BTREE_DIR = src/bplustree
BTREE_FILES = $(BTREE_DIR)/BPlusTree.cpp $(BTREE_DIR)/FreeListManager.cpp $(BTREE_DIR)/IndexManager.cpp

# Source Files
SRC_DIR = src
SRC_FILES = $(SRC_DIR)/main.cpp $(SRC_DIR)/QueryEngine.cpp $(SRC_DIR)/TableHandler.cpp $(SRC_DIR)/SQLQueryVisitor.cpp $(ANTLR_FILES) $(BTREE_FILES)

# Object Files
OBJ_FILES = $(SRC_FILES:.cpp=.o)

# Executable
TARGET = mini-db

# Generate ANTLR Parser Files
$(ANTLR_FILES): SQL.g4
	java -jar $(ANTLR_JAR) -Dlanguage=Cpp -visitor -o $(ANTLR_GEN_DIR) SQL.g4

# Compile Object Files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile the Project
$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Include dependencies
-include $(OBJ_FILES:.o=.d)

# Run the Database Engine
run: $(TARGET)
	./$(TARGET)

# Clean Build Files
clean:
	rm -f $(TARGET) $(OBJ_FILES) $(OBJ_FILES:.o=.d) $(ANTLR_FILES) $(ANTLR_GEN_DIR)/*.h
	rm -rf build
