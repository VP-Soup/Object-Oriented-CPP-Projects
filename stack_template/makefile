#makefile
CC= g++ -std=c++11
main: main.o stack.o
		$(CC) main.o -stack.o -o main

main.o: main.cpp stack.o
		$(CC) -c main.cpp

stack.o: stack.cpp
		$(CC) -c stack.cpp

clean:
		rm *.o
		rm main
