# Group_B_VirtualEscapeRoom

### Organization: Carleton University

## Authors

- Felix Elugbaju

- John Jegede

- Alvi Jawad

- Isaac Wiebe

## Description

The software will allow users to take the role of an imprisoned player and dive into an exciting and challenging adventure in a text-based interactive environment.

The user plays as a person locked in a room filled with interesting objects (tables, letters, clocks, graffiti, etc.) that he/she can freely interact with. Each object and its distinct features conceal puzzles, riddles, and hidden messages in the room. The user will have to examine objects, gather hints, and piece the clues together in order to gain access to a key or code that will open the lock on the door. The key objective of the game is to overcome diverse challenges in order to leave the room through an unlocked door.

Opening one door will lead to a different room with a distinctively different set of objects, interactions, and challenges. Challenges in each room are more difficult than the previously cleared rooms. The game will end when the user solves all the mysteries in all rooms and leaves through the grand door of the final room.

## Source Files

    makefile
    arghandling.c
    arghandling.h
    execution.c
    execution.h
    helper.c
    helper.h
    main.c
    object.c
    object.h
    parsenexec.c
    parsenexec.h
    puzzle.c
    puzzle.h

## Building the project

1. Make sure you're in the project folder

2. *(optional)* Clean the project by calling

        make clean

3. Call make by typing

        make

4. The program will be built into `build/VirtualEscapeRoom`, so you can run the program by

        ./build/VirtualEscapeRoom
