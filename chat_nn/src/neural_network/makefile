CC = g++
CFLAGS = -Wall -std=c++11 -O3
LIBS = -Lsrc/neural_network -lneural_network

all: main

main: src/main.cpp src/neural_network/neural_network.h
	$(CC) $(CFLAGS) -o main src/main.cpp $(LIBS)

neural_network: src/neural_network/neural_network.cpp src/neural_network/layer.h src/neural_network/neural_network.h
	$(CC) $(CFLAGS) -c src/neural_network/neural_network.cpp -o src/neural_network/neural_network.o
	$(CC) $(CFLAGS) -c src/neural_network/layer.cpp -o src/neural_network/layer.o
	ar rcs src/neural_network/libneural_network.a src/neural_network/neural_network.o src/neural_network/layer.o

emnist_parser: src/neural_network/emnist_parser.cpp src/neural_network/layer.h
	$(CC) $(CFLAGS) -o emnist_parser src/neural_network/emnist_parser.cpp

clean:
	rm -f src/neural_network/*.o src/neural_network/*.a main emnist_parser
