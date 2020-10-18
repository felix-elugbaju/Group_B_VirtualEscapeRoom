# Requirements
* Complete
* Precise
* Prioritized
* Measurable
* Verifiable

Proposal Title: Virtual Escape Room

We are thinking of developing a word-based adventure game in the form of an escape room. The player is initially confined in a. Room with distinct objects to interact with. The goal is to find clues from the objects, decipher hidden messages, and solve a collection of puzzles in hopes of finding the necessary keys/codes to escape from the room.
We would have the player interact with the escape room in the same way in which you would interact with a command prompt or shell. The player would enter <command> <arg>, and the software would respond to their input.  We would develop our own commands such as “Examine” “Listen” “Watch” “Use”, etc. to simulate actions done in a real-life escape room. 
A list of common commands will be provided whereas the player would need to find additional unique commands from the hints given when they perform any action.
We are still exploring possible extensions. If feasible, we are thinking of creating multiple connected locked rooms. Escaping from one room (one stage) leads to a different locked room (a different stage) with its own set of objects and puzzles to solve, and the difficulty of the riddles increases with each passing stage. , which is most difficult stage. 

## Goal: 
The game is completed when the player solves all the puzzles and escapes from the final room.

## Problem Statement
[To be written]

## Release 1
* The game shall be playable by a single player/user <critical>
* The software shall be able to take any command from the user in the form of <command> <arg> <critical>
* Every room will contain a fixed number of objects <high>
* Users will be able to interact with objects <critical>
* The user shall be able to interact with the objects using the terminal. <critical>
* The command "ask help" will display a list of common commands <high>
* "ask hint" will give a hint towards the probable solution <medium>
* Examining an object will give further information that may lead to unique commands <high>
* The first room will have 3 riddles <critical>
* Solving puzzles/deciphering messages will give access to a key or a code <critical>
* Getting the key/code to the lock on the door will open that door <critical>

## Release 2	
* Opening the door of one stage will give access to the next stage <high>
* Each stage will be harder than the next one <medium>
* Each room will have an exit which will be connected to the next locked room <low>


# Deliverable 2
## Design
---------

## GitHub
---------



## Ideas - Alvi
1. Taking input
---------------
* bool get_input () 
--> uses fgets to read the user input from the stdin stream and store into a pre-defined string.

2. Parsing the input strings
----------------------------
* bool parse_and_execute (char *input) 
--> takes the string which is a pointer to an array of characters as input and returns true as long as the input is not "quit <arg>"
	* Also resposible for separating the input string into <commands> and <arguments> and
	* calling all the execute functions based on the <command> part*

3. The main function
--------------------
* int main () 
--> repeatedly calls the get_input() and parse_and_execute() functions until the user decides to <quit>

4. Object Creation
------------------
structs that define different objects.
--> each object has its own "description", "type", and "location"
	* the field "type" determines the objects type and what commands are allowed to be performed on them

5. Execution of commands
------------------------
Common commands:
	* look <stage>, examine <object>, get <object>, read <writing>, ask <help/hint>, use <key/code>, move <next_stage>, check <bag>
Unique commands:
	* hidden, can only be deciphered from solving riddles, puzzles, or hidden information in object descriptions

Common Commands:
----------------
* void execute_look (char *arg)
look <stage> / look around / look room
--> Allows the user to identify all visible objects in the room*
	* might use a function like [list_all_objects(OBJECT *location)] to list all objects*

* void execute_examine(char *arg)
examine <object>
--> Allows the user to examine an object and derive more details about it (may lead to unique commands)*
	* if object->location matches player->location	

* read <object> (e.g., letter, grafitti)
--> Allows the user to read letters (may contain hidden messages/codes, and lead to unique commands)

* get <object>
--> Allows the user to hold/carry small objects (e.g., keys, puzzle pieces)

* Ask <help/hint>
--> Allows the user to view a list of common commands

* check <bag>
--> Check all the items that the user has

* Use <key/code>
--> Opens the lock(s) in a room

* move <next_stage>
--> Allows the user to move to the next stage if the door is unlocked
*** strcmp(arg, locs[i].type) == 0 && strcmp(locs[i].state, "unlocked") == 0
** if move is successful, execute <look around>

6. Dealing with Objects
-----------------------
* bool object_has_tag(OBJECT *obj, char *arg)
--> if the <arg> has a tag, return true* (user might not enter a <arg>)

* OBJECT *get_object(char arg)
--> scans through the entire object list and returns the OBJECT when the <arg> matches a OBJECT'S tag*

7. Moving between stages --> Passages
-------------------------------------
* Passages connect different stages



