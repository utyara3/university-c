.PHONY: all run clean

# Detect c++, otherwise c
SRC_CPP = $(wildcard main.cpp)

ifneq ($(SRC_CPP),)
	SRC = main.cpp
	CC = g++
else
	SRC = main.c
	CC = gcc
endif

all:
	$(CC) $(SRC) -o main

run: all
	./main

clean:
	rm main
