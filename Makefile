CC = gcc
INCLUDE_DIR = -I include 


#CREATE BIN AND BUILD FOLDERS TO SAVE THE COMPILED FILES DURING RUNTIME IF THEY DO NOT EXIST

bin_folder := $(shell mkdir -p bin)
build_folder := $(shell mkdir -p build)
results_folder := $(shell mkdir -p program_output)


#TARGETS TO GENERATE THE OBJECT FILES

arghandling.o: source/arghandling.c
	$(CC) -g -c $(INCLUDE_DIR) source/arghandling.c -o build/arghandling.o 

execution.o: source/execution.c
	$(CC) -g -c $(INCLUDE_DIR) source/execution.c -o build/execution.o 

helper.o: source/helper.c
	$(CC) -g -c $(INCLUDE_DIR) source/helper.c -o build/helper.o

main.o: source/main.c
	$(CC) -g -c $(INCLUDE_DIR) source/main.c -o build/main.o

object.o: source/object.c
	$(CC) -g -c $(INCLUDE_DIR) source/object.c -o build/object.o

parsenexec.o: source/parsenexec.c
	$(CC) -g -c $(INCLUDE_DIR) source/parsenexec.c -o build/parsenexec.o

puzzle.o: source/puzzle.c
	$(CC) -g -c $(INCLUDE_DIR) source/puzzle.c -o build/puzzle.o

#TARGET TO GENERATE THE EXECUTABLE OF THE PROGRAM
main:  execution.o arghandling.o helper.o main.o object.o parsenexec.o puzzle.o 
	$(CC) -g build/execution.o build/arghandling.o build/helper.o build/main.o \
                 build/object.o build/parsenexec.o build/puzzle.o -o bin/Application.OUT

#TARGET TO GENERATE ALL THE EXECUTABLES
all: main

#CLEAN COMMANDS
clean:
	rm -f bin/* build/*

