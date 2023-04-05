# Compiler
CC=g++

# Compiler flags
CFLAGS=-c -Wall

# Directories
SRC_DIR=./src
BIN_DIR=./bin

# Targets
MAIN_TARGET=$(BIN_DIR)/neural_network
TEST_TARGET=$(BIN_DIR)/test_neural_network

# Source files
MAIN_SRC=$(SRC_DIR)/main.cpp
TEST_SRC=$(SRC_DIR)/test.cpp

# Object files
MAIN_OBJ=$(BIN_DIR)/main.o
TEST_OBJ=$(BIN_DIR)/test.o
PARSER_OBJ=$(BIN_DIR)/emnist_parser.o

# Libraries
LIBS=-larmadillo

all: $(MAIN_TARGET) $(TEST_TARGET)

$(MAIN_TARGET): $(MAIN_OBJ) $(PARSER_OBJ)
	$(CC) $(LIBS) $(MAIN_OBJ) $(PARSER_OBJ) -o $(MAIN_TARGET)

$(TEST_TARGET): $(TEST_OBJ) $(PARSER_OBJ)
	$(CC) $(LIBS) $(TEST_OBJ) $(PARSER_OBJ) -o $(TEST_TARGET)

$(MAIN_OBJ): $(MAIN_SRC)
	$(CC) $(CFLAGS) $(MAIN_SRC) -o $(MAIN_OBJ)

$(TEST_OBJ): $(TEST_SRC)
	$(CC) $(CFLAGS) $(TEST_SRC) -o $(TEST_OBJ)

$(PARSER_OBJ): $(SRC_DIR)/emnist_parser.cpp $(SRC_DIR)/emnist_parser.h
	$(CC) $(CFLAGS) $(SRC_DIR)/emnist_parser.cpp -o $(PARSER_OBJ)

clean:
	rm -f $(MAIN_OBJ) $(TEST_OBJ) $(PARSER_OBJ) $(MAIN_TARGET) $(TEST_TARGET)
