# Compiler and Flags
CXX = g++
CXXFLAGS = -std=c++20 -I/usr/local/include/antlr4-runtime
LDFLAGS = -L/usr/local/lib -lantlr4-runtime

# ANTLR Variables
ANTLR_JAR = ~/Desktop/cppApps/antlr/antlr-4.13.2-complete.jar
ANTLR_GEN_DIR = src/antlr
ANTLR_FILES = $(ANTLR_GEN_DIR)/SQLLexer.cpp $(ANTLR_GEN_DIR)/SQLParser.cpp $(ANTLR_GEN_DIR)/SQLBaseVisitor.cpp

# Source Files
SRC_DIR = src
SRC_FILES = $(SRC_DIR)/main.cpp $(SRC_DIR)/QueryEngine.cpp $(SRC_DIR)/TableHandler.cpp $(SRC_DIR)/SQLQueryVisitor.cpp $(ANTLR_FILES)

# Executable
TARGET = mini-db

# Generate ANTLR Parser Files
$(ANTLR_FILES): SQL.g4
	java -jar $(ANTLR_JAR) -Dlanguage=Cpp -visitor -o $(ANTLR_GEN_DIR) SQL.g4

# Compile the Project
$(TARGET): $(SRC_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Run the Database Engine
run: $(TARGET)
	./$(TARGET)

# Clean Build Files
clean:
	rm -f $(TARGET) $(ANTLR_FILES) $(ANTLR_GEN_DIR)/*.h
	rm -rf build
