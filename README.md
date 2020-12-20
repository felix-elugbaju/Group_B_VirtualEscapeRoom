# VIRTUAL ESCAPE ROOM

#### Created by: Alvi Jawad, Isaac Wiebe, John Jegede, and Felix Elugbaju
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

/src
- arghandling.c 
- execution.c
- helper.c 
- main.c 
- object.c 
- parsenexec.c 
- puzzle.c

/include 
- arghandling.h
- execution.h
- helper.h
- object.h
- parsenexec.h
- puzzle.h 

/data

/test


# <a name ="install"></a>
### Compilation Instructions

In order to compile the program:
1) Open the command prompt
2) Navigate to the root directory of the project
3) Enter "make executable" or "make all" (without the quotes) into the command line
4) Navigate to the bin directory by entering "cd bin"
5) The application may now be run by entering "./VER.exe" into the command line

6) To clean the automatically created object and binary files, enter "make clean" while inside the root directory


# <a name = "gameplay"></a>
### User Manual

See the [User Manual](https://github.com/felix-elugbaju/Group_B_VirtualEscapeRoom/wiki/User-Manual) in the Wiki. 

# <a name = "development"></a>
### For developers

See the [Developer's Section](https://github.com/felix-elugbaju/Group_B_VirtualEscapeRoom/wiki/Developer-Manual) in the Wiki.

API documentation is hosted on [GitHub pages in the docs branch](https://felix-elugbaju.github.io/Group_B_VirtualEscapeRoom/files.html).
