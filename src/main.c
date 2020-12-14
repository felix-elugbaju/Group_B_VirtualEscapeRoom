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
 * @brief A function to check whether all three stages were cleared
 * @return 1 if all three stages are cleared, 0 otherwise
 */
static bool game_cleared(void){
	if (stage1->state == unrestricted && stage2->state == unrestricted && stage3->state == unrestricted){
		printf("CONGRATS!!\n"
		"You have just cleared the game!\n"
		"You get a GRANDPRIZEXYZ!!!\n");
		return true;
	} else {
		return false;
	}
}


/**
 * @brief The main function that continuously calls the three major functions to keep the game going
 * @return 0 always
 */
int main (){
	printf("WELCOME to our VIRTUAL ESCAPE ROOM!\n\n");
	execute_help();
	printf("\n");
	
	while (parse_and_execute(input) && get_input() && !game_cleared());
	printf("\nByeBye!\n");
	
	return 0;
}
