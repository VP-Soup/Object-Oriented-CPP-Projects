#makefile
CC= g++ -std=c++11
main: main.o linklist.o
		$(CC) main.o linklist.o -o main

main.o: main.cpp linklist.h
		$(CC) -c main.cpp

linklist.o: linklist.h linklist.cpp
		$(CC) -c linklist.cpp

clean:
		rm *.o
		rm main
