#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "parsenexec.h"
#include "puzzle.h"

bool parse_and_execute(char *input){
	/* Use the space delimiter to separate the command and argument */
	char *command = strtok(input, " \n");
	char *arg = strtok (NULL, " \n");
	
	/* Act based on the command */
	if (command != NULL){
		/* User enters "quit" */
		if (strcmp(command, "quit") == 0){
			return false;
		} else if (strcmp(command, "look") == 0){			// User enters "look <arg>"
			execute_look(arg);					// Show different information based on the current stage
		} else if (strcmp(command, "examine") == 0){		// User enters "examine <arg>"
			execute_examine(arg);				// Show detailed info about the object
		} else if (strcmp(command, "go") == 0){			// User enters "go <arg>"
			execute_go(arg);
		} else if (strcmp(command, "get") == 0){			// User enters "get <arg>"
			execute_get(arg);
		} else if (strcmp(command, "bag") == 0){			// User enters "bag"
			execute_check();
		} else if (strcmp(command, "use") == 0){			// User enters "use <arg>"
			execute_use(arg);
		} else if (strcmp(command, "open") == 0){			// User enters "open <arg>"
			execute_open(arg);
		} else if (strcmp(command, "read") == 0){			// User enters "read <arg>"
			execute_read(arg);
		} else if (strcmp(command, "ask") == 0){			// User enters "ask <arg>"
			if (strcmp (arg, "hint") == 0){				// User asks for hint
//				execute_hint();
			} else if (strcmp (arg, "help") == 0){
				execute_help();							// show a list of helpful common commands
			} else {
				printf("I don't know how to answer that.\n"
				"There are so many things to learn in this world!\n");
			}
		} else if (strcmp(command, "help") == 0){
			execute_help();
		} else if (strcmp(command, "hint") == 0){
//			execute_hint();
		}else {
			/* Add an interesting messsage if the user tries to do something absurd */
			printf("You tried to %s\n", command);
			printf("Turns out, %sing is impossible right now!!\n", command, arg);
		}
	}
	return true;
}