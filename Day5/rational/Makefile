CC = g++

all: program

program: crational.o program.cpp
	$(CC) -o program program.cpp crational.o

crational.o: crational.cpp crational.hpp
	$(CC) -c -o crational.o crational.cpp

clean:
	rm -f crational.o program