# Compiler
CC = g++

# Compiler flags
FLAGS = -std=c++11

# Name of the executable
EXE = main

all: $(EXE)

$(EXE): main.o
	$(CC) $(FLAGS) main.o -o $(EXE)

main.o: main.cpp Final.h
	$(CC) $(FLAGS) -c main.cpp -o main.o

clean:
	rm -f *.o $(EXE)
