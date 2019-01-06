CC=g++
CFLAGS=-O2 -march=native -Wall -fomit-frame-pointer -g
compile: libro.cc
	${CC} ${CFLAGS} libro.cc -o libro.exe
	@echo "Compilation finished"
