CC = g++

all: program.bin

program.bin: namen.o vlist.o program.cpp
	$(CC) -g -o program.bin namen.o vlist.o program.cpp

namen.o: namen.hpp namen.cpp
	$(CC) -c -o namen.o namen.cpp

vlist.o: vlist.hpp vlist.cpp namen.hpp
	$(CC) -c -o vlist.o vlist.cpp

clean:
	rm -f namen.o vlist.o program.bin 
