# Compiler
CC=g++

# Compiler flags
CFLAGS=-c -Wall

# Directories
SRC_DIR=.
BIN_DIR=../bin

# Targets
TARGET=$(BIN_DIR)/emnist_parser

# Source files
SRC=$(SRC_DIR)/emnist_parser.cpp

# Object files
OBJ=$(BIN_DIR)/emnist_parser.o

# Libraries
LIBS=-larmadillo

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(LIBS) $(OBJ) -o $(TARGET)

$(OBJ): $(SRC_DIR)/emnist_parser.cpp $(SRC_DIR)/emnist_parser.h
	$(CC) $(CFLAGS) $(SRC_DIR)/emnist_parser.cpp -o $(OBJ)

clean:
	rm -f $(OBJ) $(TARGET)
