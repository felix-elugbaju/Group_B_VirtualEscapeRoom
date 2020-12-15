#include <stdio.h>
#include "object.h"

/************************* Object Descriptions *************************/
OBJECT_t objs[] = {
	/***** stages *****/
	{"a bright white room", "stage1", location, confined, NULL, NULL},	// NULL: stages aren't visible and part of any location
	{"a dark yellow room", "stage2", location, confined, NULL, NULL},
	{"a crimson red room", "stage3", location, confined, NULL, NULL},
	/***** Actors *****/
	{"yourself", "yourself", actor, regular, NULL, stage1},				// player starts in stage 1

	/******************** stage 1 objects ********************/
	/** Table with a letter **/
	{"a wooden table", "table", visible_object, regular,
	"The table seems strudy at first glance\n"
	"You tried to sit down\n"
	"You immediately stand up as it creaks under your weight\n"
	"There is also a letter on the table\n"
	"Some parts of the letter seems to be legible\n"
	"Reading the Letter might give you a better idea about its contents\n", stage1},
	/** A letter **/
	{"a dusty letter", "letter", hidden_object, regular,
	"dear ashford,\n"
	"it has been a LONG time since i wrote a letter to you. the weather is\n"
	"getting pretty cold right now, enough to freeze my HAND. i bought a\n"
	"cheap sweater for TWELVE dollars, and it's better now.\n"
	"the farmers' market is a SHORT walk from where i live. i remember how\n"
	"i injured my left HAND once while trying to ride a bicycle there. The\n"
	"vendors are preparing their stalls for christmas which is only SEVEN \n"
	"days away.\n"
	"i really wish you could be here with all of us during the holiday. we..\n"
	"............................\n"
	"The rest of the letter is illegible", stage1},
	/** A clock **/
	{"a broken clock", "clock", visible_object, regular,
	"The clock hands are not moving.\n"
	"You check the battery, only to find that it's long dead\n"
	"The hand for seconds is missing.\n"
	"You might be able to move the hour and minute hand.\n", stage1},
    /** A jigsaw puzzle **/
    { "a jigsaw_puzzle", "jigsaw_puzzle", visible_object, regular,
        "It looks like a piece is missing.\n"
        "You might be able to slide the pieces around\n", stage1},
    /** A treasure_bag **/
     { "a treasure_bag", "treasure_bag", visible_object, regular,
        "Look inside the treasure_bag.\n"
        "There is a paper with a with a drawing examine the paper_puzzle\n"
        "Figure out the interpretation of the drawing\n", stage1},

    /************************* Objects Visible in Stage 2 *************************/
    {"Some sheet_music", "sheet_music", visible_object, regular,
      "It reads 'Eine Kleine Nachtmusik en C MAJOR' by J.S. Bach\n"
      "CGCGCG??? there appears to be a massive blot of ink spilled on the page\n"
      "Looking further down the page yields 'C Major Triad'\n"
      "Followed by another massive blot of ink, followed by a note: \n"
      "My apologies for ruining Bach's work. In Unix: FILE DESCRIPTOR,"
      "FILE DESCRIPTOR, FILE DESCRIPTOR, for debugging use GDB. However a BROKEN TRIAD"
      " IN G MAJOR might work a bit better.\n", stage2},

    {"An old_piano", "old_piano", visible_object, regular,
    "This piano is grossly out of tune!\n"
    "And to make matters worse, someone tore off the sharps and flats!\n"
    "This crime couldn't be... accidental?! Ha! \n", stage2},

    /** A pirate chest **/
     { "a pirate_chest of gold ", "pirate_chest", visible_object, regular,
        "Here is a pirates chest.\n"
        "open it and there is a riddle inside it examine the riddle_puzzle\n"
        "solve the riddle\n", stage2},
    /************************* Doors and Keys *************************/
	{"a silver_key", "silver_key", usable_object, hidden,
	"The key glows with a bright silver color\n"
	"It might be useful in opening a door of some kind.\n", stage1},
	{"a silver_door", "silver_door", visible_object, closed,
	"It seems like there is only one lock on the door.\n"
	"The lock requires a matching key to open.\n", stage1},
    {"a gold_key", "gold_key", usable_object, hidden,
    "The key glows with a dazzling golden shine.\n"
    "It might be useful in opening a door of some kind.\n", stage2},
    {"a gold_door", "gold_door", visible_object, closed,
    "It seems like there is only one lock on the door.\n"
    "The lock requires a matching key to open.\n", stage2},
    {"a ruby_key", "ruby_key", usable_object, hidden,
    "The key draws your attention to its blood-like appearance.\n"
    "It might be useful in opening a door of some kind.\n", stage3},
    {"a ruby_door", "ruby_door", visible_object, closed,
    "You find two locks on the door.\n"
    "One colored red and the other blue.\n"
    "The red_lock seems to require a matching key.\n"
    "The blue_lock can be opened with a code.\n"
    "The blue_lock seems to have something attached to it.\n"
    "You should examine it further.\n", stage3},

    /************************* Puzzles *************************/
	{"a clock_puzzle", "clock_puzzle", puzzle, unsolved, NULL , stage1},
	{"a sliding_puzzle", "sliding_puzzle", puzzle, unsolved, NULL, stage1},
    {"a paper_puzzle", "paper_puzzle", puzzle, unsolved, NULL, stage1},
    {"a piano_puzzle", "piano_puzzle", puzzle, unsolved, NULL, stage2},
    {"a riddle_puzzle", "riddle_puzzle", puzzle, unsolved, NULL, stage2},

	/********************  Hints ********************/
    {"a hint for the clock_puzzle", "clock_hint", hint, unused,
	"hands of the clock..\n"
	"dance as they flock...\n"
	"towards the writings of the old....\n"
	"CAPITAL of wishes manifold.\n", clock_puzzle},

    /* paper puzzle hint the 3rd puzzle*/
    {"a hint for the paper_puzzle", "paper_hint", hint, unused,
	"Each of the section forms a shape that encloses an alphabet in the image\n"
	"example\n"
	"|   |\n"
	"| _ |\n"
    "the shape above is letter B in the diagram", paper_puzzle},


	/* the graffiti and the 4th puzzle */
	{"a hand-drawn graffiti", "graffiti", visible_object, regular,
	"You see a carefully curved garffiti with fine knifework\n"
	"The design seems to match that of several criss-crossing lines\n"
	"Looking Closely might lead to some interesting patterns\n", stage2},
	{"a graffiti_puzzle", "graffiti_puzzle", puzzle, unsolved, NULL, stage2},
	{"a hint for the graffiti_puzzle", "graffiti_hint", hint, unused,
	"Intertwined fates connect the occult...\n"
	"the connections define the ultimate result.\n" , graffiti_puzzle},

	    /* riddle puzzle hint the 6th puzzle */
    {"a hint for the riddle_puzzle", "riddle_hint", hint, unused,
	"Look for the alphabet that appears frequently in each month\n", riddle_puzzle},

    	/* the blue_lock and the 7th puzzle */
	{"a blue_lock", "blue_lock", usable_object, closed,
	"You find a small piece of paper attached to the lock\n"
	"It seems to be some sort of instruction manual\n"
	"You should try to Examine the Manual for further information\n", stage3},
	{"an instruction manual", "manual", usable_object, regular,
	"The manual contains a long series of instructions.\n"
	"You skipped over some stuff to find any relevant information.\n"
	"... ... ...\n", stage3},
	{"an code_puzzle", "code_puzzle", puzzle, unsolved, NULL , stage3},
	{"a hint for the code_puzzle", "code_hint", hint, unused,
	"One bird, two wings, seven feathers, solved riddles\n" , code_puzzle}
};
