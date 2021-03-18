#makefile
CC= g++ -std=c++11
main: main.o triangle.o circle.o rectangle.o square.o shape.o
		$(CC) main.o triangle.o circle.o rectangle.o square.o shape.o -o Main

main.o: main.cpp shape.h square.h rectangle.h circle.h triangle.h
		 $(CC) -c main.cpp

triangle.o: shape.h triangle.h triangle.cpp
		 $(CC) -c triangle.cpp

circle.o: shape.h circle.h circle.cpp
		 $(CC) -c circle.cpp

rectangle.o: shape.h rectangle.h rectangle.cpp
		 $(CC) -c rectangle.cpp

square.o: shape.h square.h square.cpp
		 $(CC) -c square.cpp

shape.o: shape.h shape.cpp
		 $(CC) -c shape.cpp


clean:
		rm *.o
		rm main
