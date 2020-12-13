# VIRTUAL ESCAPE ROOM

#### Created by: Alvi Jawad, Felix Elugbaju, John Jegede, and Isaac Wiebe
#### Carleton University

# Table of Contents
1. [Description](#Description)
2. [Source File Organization](#dirstructure)
3. [Installation Instructions](#install)
4. [Game Play](#gameplay)
5. [For Developers](#development)

# <a name="Description"></a>
## Description

The software will allow users to take the role of an imprisoned player and dive into an exciting
and challenging adventure in a text-based interactive environment.

The user plays as a person locked in a room filled with interesting objects (tables, letters, clocks,
graffiti, etc.) that he/she can freely interact with. Each object and its distinct features conceal
puzzles, riddles, and hidden messages in the room. The user will have to examine objects, gather
hints, and piece the clues together in order to gain access to a key or code that will open the lock
on the door. The key objective of the game is to overcome diverse challenges in order to leave
the room through an unlocked door.

Opening one door will lead to a different room with a distinctively different set of objects,
interactions, and challenges. Challenges in each room are more difficult than the previously
cleared rooms. The game will end when the user solves all the mysteries in all rooms and leaves
through the grand door of the final room.

# <a name ="dirstructure"></a>
## Source File Organization

The complete file structure is as follows: 


/bin

/build
- arghandling.o
- execution.o
- helper.o
- main.o
- object.o
- parsenexec.o
- puzzle.o

/include 
- arghandling.h
- execution.h
- helper.h
- object.h
- parsenexec.h
- puzzle.h 

/src
- arghandling.c 
- execution.c
- helper.c 
- main.c 
- object.c 
- parsenexec.c 
- puzzle.c

/test

# <a name ="install"></a>
### Compilation Instructions

In order to compile the program:
1) Open the command prompt
2) Navigate to the root directory of the project
3) Enter ""make all"" into the command line
4) The application may now be run by entering ""./bin/Application.OUT""" into the command line


# <a name = "gameplay"></a>
### Gameplay 

# <a name = "development"></a>
### For developers
