#makefile
CC= g++ -std=c++11
main: main.o simplevector.h
		$(CC) main.o -o main

main.o: main.cpp simplevector.h
		$(CC) -c main.cpp

clean:
		rm *.o
		rm main
