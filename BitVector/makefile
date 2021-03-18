#makefile bitvector class
CC= g++ -std=c++11
main: main.o bitvector.o
		$(CC) main.o bitvector.o -o bitvectorApp

bitvectorApp.o: main.cpp
		 $(CC) -c main.cpp

bitvector.o: bitvector.h bitvector.cpp
		 $(CC) -c bitvector.h
		 $(CC) -c bitvector.cpp

clean:
		rm -rf *o bitvector
