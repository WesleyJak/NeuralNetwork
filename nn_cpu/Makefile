main: main.o layer.o
	g++ -o main main.o layer.o

main.o: main.cpp
	g++ -c main.cpp -std=c++20

layer.o: layer.cpp
	g++ -c layer.cpp

clean:
	rm -f *.o
	rm -f main