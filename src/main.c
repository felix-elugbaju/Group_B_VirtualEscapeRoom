#include <stdio.h>
#include <stdbool.h>
#include "parsenexec.h"
#include "object.h"
#include "execution.h"

/** 
 * Maximum size of input buffer is 100
 * Initialize the array to "look around" so it can be the default 
 * command that is executed whenever we enter a new stage.
 */
static char input[100] = "look around";
 

/**
 * @brief A function to get user inputs from the stdin stream
 * @return 1 if input captured properly, 0 in case of a Null
 */
static bool get_input(void){
	// Prompt the user to enter a command using "> ".
	printf("\nWhat would you like to do?");
	printf("\n> ");
	bool input_captured = fgets(input, sizeof(input), stdin) != NULL;
	printf("\n");
	return input_captured;
}




/**
 * @brief The main function that continuously calls the three major functions to keep the game going
 * @return 0 always
 */
int main (){
	printf("WELCOME to our VIRTUAL ESCAPE ROOM!\n\n");
	execute_help();
	printf("\n");
	
	while (parse_and_execute(input) && get_input());
	printf("Thanks for playing the game!\n\n");
	
	return 0;
}
