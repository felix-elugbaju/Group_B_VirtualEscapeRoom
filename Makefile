CC = gcc
INCLUDE_DIR = -I include 


#CREATE BIN AND BUILD FOLDERS TO SAVE THE COMPILED FILES DURING RUNTIME IF THEY DO NOT EXIST

bin_folder := $(shell mkdir -p bin)
build_folder := $(shell mkdir -p build)
results_folder := $(shell mkdir -p program_output)


#TARGETS TO GENERATE THE OBJECT FILES
build/arghandling.o: src/arghandling.c
	$(CC) -g -c $(INCLUDE_DIR) src/arghandling.c -o build/arghandling.o 

build/execution.o: src/execution.c
	$(CC) -g -c $(INCLUDE_DIR) src/execution.c -o build/execution.o 

build/helper.o: src/helper.c
	$(CC) -g -c $(INCLUDE_DIR) src/helper.c -o build/helper.o

build/main.o: src/main.c
	$(CC) -g -c $(INCLUDE_DIR) src/main.c -o build/main.o

build/object.o: src/object.c
	$(CC) -g -c $(INCLUDE_DIR) src/object.c -o build/object.o

build/parsenexec.o: src/parsenexec.c
	$(CC) -g -c $(INCLUDE_DIR) src/parsenexec.c -o build/parsenexec.o

build/puzzle.o: src/puzzle.c
	$(CC) -g -c $(INCLUDE_DIR) src/puzzle.c -o build/puzzle.o
	
#TARGET TO GENERATE THE EXECUTABLE OF THE PROGRAM
executable:  build/execution.o build/arghandling.o build/helper.o build/main.o build/object.o build/parsenexec.o build/puzzle.o 
	$(CC) -g build/execution.o build/arghandling.o build/helper.o build/main.o \
                 build/object.o build/parsenexec.o build/puzzle.o -o bin/VER.exe


#TARGET TO GENERATE ALL THE EXECUTABLES
.PHONY: all
all: executable

#CLEAN COMMANDS
.PHONY: clean
clean:
	rm -f bin/* build/*
=======
CC = gcc
INCLUDE_DIR = -I include 


#CREATE BIN AND BUILD FOLDERS TO SAVE THE COMPILED FILES DURING RUNTIME IF THEY DO NOT EXIST

bin_folder := $(shell mkdir -p bin)
build_folder := $(shell mkdir -p build)
results_folder := $(shell mkdir -p program_output)


#TARGET TO GENERATE ALL THE EXECUTABLES
.PHONY: all
all: bin/Application.OUT

#TARGETS TO GENERATE THE OBJECT FILES

build/arghandling.o: src/arghandling.c
	$(CC) -g -c $(INCLUDE_DIR) src/arghandling.c -o build/arghandling.o 

build/execution.o: src/execution.c
	$(CC) -g -c $(INCLUDE_DIR) src/execution.c -o build/execution.o 

build/helper.o: src/helper.c
	$(CC) -g -c $(INCLUDE_DIR) src/helper.c -o build/helper.o

build/main.o: src/main.c
	$(CC) -g -c $(INCLUDE_DIR) src/main.c -o build/main.o

build/object.o: src/object.c
	$(CC) -g -c $(INCLUDE_DIR) src/object.c -o build/object.o

build/parsenexec.o: src/parsenexec.c
	$(CC) -g -c $(INCLUDE_DIR) src/parsenexec.c -o build/parsenexec.o

build/puzzle.o: src/puzzle.c
	$(CC) -g -c $(INCLUDE_DIR) src/puzzle.c -o build/puzzle.o
	
#TARGET TO GENERATE THE EXECUTABLE OF THE PROGRAM
bin/Application.OUT:  build/execution.o build/arghandling.o build/helper.o build/main.o build/object.o build/parsenexec.o build/puzzle.o 
	$(CC) -g build/execution.o build/arghandling.o build/helper.o build/main.o \
                 build/object.o build/parsenexec.o build/puzzle.o -o bin/Application.OUT

#CLEAN COMMANDS
.PHONY: clean
clean:
	rm -f bin/* build/*