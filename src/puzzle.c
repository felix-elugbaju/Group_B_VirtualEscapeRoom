#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"
#include "ctype.h"
#include "helper.h"
#include "puzzle.h"
#include "object.h"

/**
 * The first puzzle triggered from the clock
 */
void trigger_puzzle1(){
	printf("\nYou found a clock-puzzle!\n");
	printf("Do you want to manually set the time? y/n\n");
	char user_intent = fgetc(stdin);
	fflush(stdin);		// flush the input buffer
	
	if(tolower(user_intent) == 'n'){
		return;
	} else if (tolower(user_intent) == 'y'){
		do {
			int hour_hand, minute_hand = 0;
			printf("\nSet hour hand to: ");
			scanf("%d", &hour_hand);
			printf("Set minute hand to: ");
			scanf("%d", &minute_hand);
			fflush(stdin);
			printf("\nYou turned the clock hands using the knobs at the back.\n");
			if (hour_hand>=1 && hour_hand<=12 && minute_hand>=0 && minute_hand<=59){
//				printf("\nThe time is now  %d:%d\n", hour_hand, minute_hand);
				if (hour_hand==7 && minute_hand==12){
					clock_puzzle->state = solved;
					printf("Suddenly, the clock starts to tick!\n"
					"There seems to be a different energy source somewhere.\n"
					"But that doesn't seem to be quite enough as the clock stops again.\n"
					"Congrats! You have solved this puzzle!\n\n");
					check_solved_stage1();		// check if all puzzles have been solved
					return;
				} else {
					printf("But nothing happened!\n\n");
				}
			} else {
				printf("\nI'm not sure what you're trying to do.\n"
				"You must have never seen a real clock!\n\n");
			}
			printf("Do you want to try again? y/n\n");
			user_intent = fgetc(stdin);
			fflush(stdin);
		} while(tolower(user_intent) == 'y');
	} else {
		printf("It seems you want to do neither!\n");
	}
}





void trigger_puzzle2()
{
    printf("Do you want to attempt sliding the pieces around? (y/n)");
    char user_intent = fgetc(stdin);
    fflush(stdin);        // flush the input buffer
    if(tolower(user_intent) == 'n'){
        return;
    }
    else
    { 
    

        char puzzle[PUZZLE_LENGTH][PUZZLE_LENGTH] = {
            {'\\', '0', '/'},
            {'.', '|', '.'},
            {'/', '.', '\\'}
            };
        char puzzletwo[PUZZLE_LENGTH][PUZZLE_LENGTH];
        for (int i = 0; i < PUZZLE_LENGTH; i++)
        {
            for (int j = 0; j < PUZZLE_LENGTH; j++)
            {
                if (puzzle[i][j] == '0')
                    puzzletwo[i][j] = '?';
                else
                    puzzletwo[i][j] = puzzle[i][j];
            }
        }

        printf("\n");

        printf("Use the WASD keys to rearrange the puzzle!\n");
        printf("W => up\n");
        printf("A => left\n");
        printf("S => down\n");
        printf("D => right\n");
        printf("Enter 'q' to quit, or reset the puzzle\n");
        printf("Type in enter to confirm your selection\n");
        printf("The '?' is a free space to slide tiles in\n");
        printf("\n");


        int cursX = 1;
        int cursY = 0;
        for (int k = 0; k < 100; k++)
        {
            int choice = rand() % 4;

            switch (choice)
            {
                case 0:
                    if (cursY != PUZZLE_LENGTH - 1)
                    {
                        char temp = puzzletwo[cursY + 1][cursX];
                        puzzletwo[cursY + 1][cursX] = puzzletwo[cursY][cursX];
                        puzzletwo[cursY][cursX] = temp;
                        cursY++;

                    }
                    break;
                case 1:
                    if (cursX != PUZZLE_LENGTH - 1)
                    {
                        char temp = puzzletwo[cursY][cursX + 1];
                        puzzletwo[cursY][cursX + 1] = puzzletwo[cursY][cursX];
                        puzzletwo[cursY][cursX] = temp;
                        cursX++;

                    }
                    break;
                case 2:
                    if (cursY != 0)
                    {
                        char temp = puzzletwo[cursY - 1][cursX];
                        puzzletwo[cursY - 1][cursX] = puzzletwo[cursY][cursX];
                        puzzletwo[cursY][cursX] = temp;
                        cursY--;

                    }
                    break;
                case 3:
                    if (cursX != 0)
                    {
                        char temp = puzzletwo[cursY][cursX - 1];
                        puzzletwo[cursY][cursX - 1] = puzzletwo[cursY][cursX];
                        puzzletwo[cursY][cursX] = temp;
                        cursX--;

                    }
                    break;
                default:
                    break;


            }


        }

        printf("TARGET\n");
        printf("\n");


        for (int i = 0; i < PUZZLE_LENGTH; i++)
        {
            for (int j = 0; j < PUZZLE_LENGTH; j++)
            {
                printf("%c", puzzle[i][j]);

            }
            printf("\n");
        }

        printf("\n");
        printf("\n");
        printf("YOUR PUZZLE\n");
        for (int i = 0; i < PUZZLE_LENGTH; i++)
        {
            for (int j = 0; j < PUZZLE_LENGTH; j++)
            {
                printf("%c", puzzletwo[i][j]);

            }
            printf("\n");
        }


        int done = 0;


        while (!done)
        {
            int flag1 = 1;

            int input_char;
            input_char = fgetc(stdin);
            

            if (input_char == 119)
            {
                if (cursY != PUZZLE_LENGTH - 1)
                {
                    char temp = puzzletwo[cursY + 1][cursX];
                    puzzletwo[cursY + 1][cursX] = puzzletwo[cursY][cursX];
                    puzzletwo[cursY][cursX] = temp;
                    cursY++;

                }

            }
            if (input_char == 97)
            {
                if (cursX != PUZZLE_LENGTH - 1)
                {
                    char temp = puzzletwo[cursY][cursX + 1];
                    puzzletwo[cursY][cursX + 1] = puzzletwo[cursY][cursX];
                    puzzletwo[cursY][cursX] = temp;
                    cursX++;

                }
            }

            if (input_char == 115)
            {
                if (cursY != 0)
                {
                    char temp = puzzletwo[cursY - 1][cursX];
                    puzzletwo[cursY - 1][cursX] = puzzletwo[cursY][cursX];
                    puzzletwo[cursY][cursX] = temp;
                    cursY--;

                }
            }

            if(input_char == 100)
            {
                if (cursX != 0)
                {
                    char temp = puzzletwo[cursY][cursX - 1];
                    puzzletwo[cursY][cursX - 1] = puzzletwo[cursY][cursX];
                    puzzletwo[cursY][cursX] = temp;
                    cursX--;

                }
            }

            if (input_char == 113)
            {
                printf("Resetting the puzzle\n");
                return;
            }
            

            printf("\n");
            printf("\n");

            if (input_char != 10)
            {
                printf("Use the WASD keys to rearrange the puzzle!\n");
                printf("W => up\n");
                printf("A => left\n");
                printf("S => down\n");
                printf("D => right\n");
                printf("Enter 'q' to quit, or reset the puzzle\n");
                printf("Type in enter to confirm your selection\n");
                printf("The '?' is a free space\n");
                printf("\n");

                printf("TARGET\n");
                printf("\n");
                for (int i2 = 0; i2 < PUZZLE_LENGTH; i2++)
                {
                    for (int j2 = 0; j2 < PUZZLE_LENGTH; j2++)
                    {
                    printf("%c", puzzle[i2][j2]);
                    }
                    printf("\n");
                }
                printf("\n");
                printf("\n");
                printf("YOUR PUZZLE\n");
                for (int i2 = 0; i2 < PUZZLE_LENGTH; i2++)
                {
                    for (int j2 = 0; j2 < PUZZLE_LENGTH; j2++)
                    {
                        printf("%c", puzzletwo[i2][j2]);
                    }
                    printf("\n");
                }
            }




            for (int i = 0; i < PUZZLE_LENGTH; i++)
            {
                for (int j = 0; j < PUZZLE_LENGTH; j++)
                {
                    if (puzzletwo[i][j] != puzzle[i][j])
                    {
                        if (!(puzzletwo[i][j] == '?' && puzzle[i][j] == '0'))
                        {
                            flag1 = 0;
                        }
                    }
                }

            }
            if (flag1)
                done = 1;
        }
        printf("TARGET\n");
        printf("\n");
        for (int i2 = 0; i2 < PUZZLE_LENGTH; i2++)
        {
            for (int j2 = 0; j2 < PUZZLE_LENGTH; j2++)
            {
                printf("%c", puzzle[i2][j2]);
            }
            printf("\n");
        }
        printf("\n");
        printf("\n");
        printf("YOUR PUZZLE\n");
        for (int i2 = 0; i2 < PUZZLE_LENGTH; i2++)
        {
            for (int j2 = 0; j2 < PUZZLE_LENGTH; j2++)
            {
                if (puzzletwo[i2][j2] == '?')
                        puzzletwo[i2][j2] = '0';
                printf("%c", puzzletwo[i2][j2]);
            }
            printf("\n");
        }
        printf("The puzzle has been solved!\n");
        sliding_puzzle->state = solved;
        check_solved_stage1();
        
        
        fflush(stdin);        // flush the input buffer
        return;
    }
}


void trigger_puzzle4(){
	printf("You look closely at the lines\n"
	"This seems like a lot of effort was put into the carving\n"
	"The carvings are traceable.\n");
	
	printf("\nYou found a graffiti-puzzle!\n"
	"Do you trace the lines? y/n\n");
	char user_intent = fgetc(stdin);
	fflush(stdin);		// flush the input buffer
	
	if(tolower(user_intent) == 'n'){
		return;
	} else if (tolower(user_intent) == 'y'){
		/* Show the graffiti puzzle */
		printf("\nAs you trace your finger through the lines...\n"
		"you start to see some common alignments.\n"
		"You find: \n"
		"\n"
		"        |        |        |        \n"
		"        |        |        |        \n"
		"        |        |        |        \n"
		"________|________|________|________\n"
		"        |        |        |        \n"
		"        |        |        |        \n"
		"        |        |        |        \n"
		"________|________|________|________\n"
		"        |        |        |        \n"
		"        |        |        |        \n"
		"        |        |        |        \n"
		"________|________|________|________\n"
		"        |        |        |        \n"
		"        |        |        |        \n"
		"        |        |        |        \n"
		"        |        |        |        \n"
		"\n"
		"and\n"
		"\n"
		"        |       \n"
		"        |       \n"
		"        |       \n"
		"________|_______\n"
		"        |       \n"
		"        |       \n"
		"        |       \n"
		"        |       \n"
		"\n"
		"and\n"
		"\n"
		"        |        |        \n"
		"        |        |        \n"
		"        |        |        \n"
		"________|________|________\n"
		"        |        |        \n"
		"        |        |        \n"
		"        |        |        \n"
		"________|________|________\n"
		"        |        |        \n"
		"        |        |        \n"
		"        |        |        \n"
		"        |        |        \n"
		"\n");
		
		
		printf("You also find three bright red number slots.\n"
		"\n"
		"[9] [1] [?]\n"
		"\n"
		"The [?] slot is accompanied by a keypad containing single-digit keys\n"
		"you might be able to press the keys and see what happens.\n\n");
		
		printf("Do you use the keypad? y/n\n");
		user_intent = fgetc(stdin);
		fflush(stdin);		// flush the input buffer

		if(tolower(user_intent) == 'n'){
			return;
		} else if (tolower(user_intent) == 'y'){
			int user_result = 0;
			do{ 
				printf("\nWhich key would you like to press?\n");
				scanf("%d", &user_result);
				fflush(stdin);
				if (user_result == 0 
					|| user_result == 1 || user_result == 2 || user_result == 3
					|| user_result == 4 || user_result == 5 || user_result == 6
					|| user_result == 7 || user_result == 8 || user_result == 9){
						
					printf("\nYou pressed %d.\n", user_result);
					printf("\nThe slots now read:\n"
					"\n"
					"[9] [1] [%d]\n"
					"\n"
					, user_result);
					
					if (user_result == 4){
						graffiti_puzzle->state = solved;
						printf("Suddenly, all the slots light up!\n"
						"In place of the question mark, you now see a 4.\n"
						"The keypad doesn't respond to your presses anymore.\n"
						"Congrats! You have solved this puzzle!\n\n");
						check_solved_stage2();		// check if all puzzles have been solved
						return;
					} else {
						printf("But nothing happened!\n\n");
					}
				} else {
					printf("\nI'm not sure what you're trying to do.\n"
					"Even elementary kids know what single-digit means!\n\n");
				}
				printf("Do you want to try again? y/n\n");
				user_intent = fgetc(stdin);
				fflush(stdin);
			} while(tolower(user_intent) == 'y');
		} else {
		printf("It seems you want to do neither!\n");
		}
	} else {
		printf("It seems you want to do neither!\n");
	}
}

void trigger_puzzle5()
{
	printf("This piano is grossly out of tune!\n");
	printf("Do you play it anyways?\n");
	char user_intent = fgetc(stdin);
    fflush(stdin);        // flush the input buffer
    if(tolower(user_intent) == 'n'){
        return;
    }
    else {
    	int done = 0;
    	char * firstVerse = "CGCGCGCEG";
    	char * quit = "q";
    	while (!done) {
    		char noteString[10];
    		printf("What string of notes do you play on the piano? (For simplicity, assume"
    		" that the only valid notes are any combination of (notes may repeat) "
    		"of 'A', 'B', 'C', 'D', 'E', 'F', 'G' \n");
    		printf("Enter 'q' to quit\n");
    		scanf("%s", noteString);

    		if (strcmp(noteString, firstVerse) == 0) {
    			printf("An amazing first verse, albeit out of tune\n");
    			done = 1;
    		}
    		else if (strcmp(noteString, "q") == 0) {
    			fflush(stdin); 
    			return;
    		}
    		else {
    			printf("The out of tune piano is ghastly to listen to.\n");
    			printf("This string of notes doesn't sound like a song at all\n");
    			printf("Maybe there is sheet music nearby?\n");
    		}
    	}
    	
    	printf("An internal mechanism clinks around in the piano.\n");
    	printf("However, it stopped! It looks like another combination\n");
    	printf("Of notes is needed. A second verse if you will.\n");
    	printf("\n");
    	
    	done = 0;
    	char * secondVerse = "FDFDFDBDG";
    	while (!done) {
    		char noteString[10];
    		printf("It is time to enter the second verse\n");
    		printf("What string of notes do you play on the piano? (For simplicity, assume"
    		"that the only valid notes are any combination of (notes may repeat) "
    		"of 'A', 'B', 'C', 'D', 'E', 'F', 'G' \n");
    		printf("Enter 'q' to quit\n");
    		scanf("%s", noteString);

    		if (strcmp(noteString, secondVerse) == 0) {
    			printf("An amazing first verse, albeit out of tune\n");
    			done = 1;
    		}
    		else if (strcmp(noteString, "q") == 0) {
    			fflush(stdin); 
    			return;
    		}
    		else {
    			printf("The out of tune piano is ghastly to listen to.\n");
    			printf("This string of notes doesn't sound like a song at all\n");
    			printf("Maybe there is sheet music nearby?\n");
    		}
    	}
    	printf("The piano's internal mechanism rotates again\n");
    	printf("It appears you have solved the puzzle!\n");
    	fflush(stdin);        // flush the input buffer
    	piano_puzzle->state = solved;
    	check_solved_stage2();
    }
} 




