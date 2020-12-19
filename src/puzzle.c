#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"
#include "ctype.h"
#include "helper.h"
#include "puzzle.h"
#include "object.h"

void trigger_puzzle1(){
	printf("\nYou found a clock-puzzle!\n");
	/********** Instructions for puzzle 1 **********/
	instructions:
		printf("\nInstructions:\n"
		"********************************************************************\n"
		"*  c. continue:     continue solving the puzzle                    *\n"
		"*  h. hint:         get a hint about the puzzle (reduced reward)   *\n"
		"*  i. instructions: see instructions for this puzzle               *\n"
		"*  q. quit:         quit solving the puzzle and do something else  *\n"
		"********************************************************************\n");
	/********** Start of the puzzle **********/
	puzzle:
		printf("\nWhat would you like to do? c/h/i/q\n");
		char user_intent = fgetc(stdin);
		fflush(stdin);		// flush the input buffer

		if(tolower(user_intent) == 'q'){		// user wants to quit the puzzle
			return;
		} else if (tolower(user_intent) == 'i'){
			goto instructions;
		} else if (tolower(user_intent) == 'h'){
			printf("\n%s\n", clock_hint->detailed_description); 	//show hint for the clock_puzzle
			clock_hint->state = used;
			goto puzzle;
		} else if (tolower(user_intent) == 'c'){
			int hour_hand, minute_hand = 0;
			printf("\nYou try to rotate the clock hands using your fingers.\n"
			"Years of dust seems to have made that impossible.\n"
			"You try the knob at the back.\n"
			"It rotates...\n");
			printf("\nSet hour hand to: ");
			scanf("%d", &hour_hand);
			printf("Set minute hand to: ");
			scanf("%d", &minute_hand);
			fflush(stdin);
			printf("\nYou turned the clock hands using the knobs at the back.\n");
			if (hour_hand>=1 && hour_hand<=12 && minute_hand>=0 && minute_hand<=59){
				if (hour_hand==7 && minute_hand==12){
					clock_puzzle->state = solved;
					printf("Suddenly, the clock starts to tick!\n"
					"There seems to be a different energy source somewhere.\n"
					"But that doesn't seem to be quite enough as the clock stops again.\n"
					"Congrats! You have solved this puzzle!\n");
					check_solved_stage1();		// check if all puzzles have been solved
					return;
				} else {
					printf("But nothing happened!\n");
				}
			} else {
				printf("\nI'm not sure what you're trying to do.\n"
				"You must have never seen a real clock!\n");
			}
			goto puzzle;
		} else {
			printf("It seems you don't want to do anything at all!\n");
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
        printf("Enter 'h' for a hint, but be careful! Your prize will be affected!\n");
        printf("Type in enter to confirm your selection\n");
        printf("The '?' is a free space to slide tiles in\n");
        printf("\n");


        int cursX = 1;
        int cursY = 0;
        int toggle_screen = 0;
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
                fflush(stdin);
                return;
            }

            if (input_char == 104)
            {
            	printf("HINT\n");
            	printf("%s", slider_hint->detailed_description);
            	printf("Press the ENTER key to continue...\n");
            	fflush(stdin);
            	getchar();
            	slider_hint->state = used;
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
                printf("Enter 'h' for a hint, but be careful! Your prize will be affected!\n");
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

void trigger_puzzle3()
{

    printf("This a paper puzzle and it requires a THREE letter word \n");
    printf("To quit press q \nTo get a hint press h \n");
    printf("Do you want to start y/n \n");

    char user_input = fgetc(stdin);
    fflush(stdin);


    if( tolower(user_input) == 'n')
    {
        return;
    }else {
        int done = 0;
        char *answer = "AEF";

        printf("A | B | C \n");
        printf("_ | _ | _ \n");
        printf("D | E | T \n");
        printf("_ | _ | _ \n");
        printf("I | O | U \n");

        printf("\n");

        printf(" \\  N  / \n");
        printf("  \\ _ /  \n");
        printf("Q | P | F \n");
        printf("  / _ \\  \n");
        printf(" / Y   \\ \n");

        printf("With the above information solve this puzzle \n");

        printf("  | \n");
        printf(" _| \n");


        printf("\n");

        printf("  _    \n");
        printf("|   |  \n");
        printf("| _ |  \n");

        printf("\n");

        printf("  /  \n");
        printf(" /   \n");
        printf("|    \n");
        printf(" \\  \n");
        printf("  \\ \n");

        while(!done)
        {
            char word[4];
            scanf("%3s", word);
            capitalize(word);


            if(strcmp(word,"Q") == 0)
            {
                fflush(stdin);
                return;
            }else if(strcmp(word,"H") == 0 )
            {
                fflush(stdin);
                printf("\n%s\n",paper_hint->detailed_description);
                paper_hint->state = used;
            }else if (strcmp(word,answer) == 0){
                done = 1;
                printf("The puzzle has been solved \n");
                paper_puzzle->state = solved;
                check_solved_stage1();

            }else {

                printf("You fail please check the hint \n");
                printf("Please examine object again \n");
                printf("TRY AGAIN or q to quit \n");

            }
        }

    }
	fflush(stdin);        // flush the input buffer
    return;

}

void trigger_puzzle4(){
	printf("You look closely at the lines\n"
	"It seems like a lot of effort was put into the carvings\n"
	"The carvings are traceable.\n");

	printf("\nYou found a graffiti-puzzle!\n");
	/********** Instructions for puzzle 4 **********/
	instructions:
		printf("\nInstructions:\n"
		"********************************************************************\n"
		"*  c. continue:     continue solving the puzzle                    *\n"
		"*  k. keypad:       start using the keypad again                   *\n"
		"*  p. pattern:      watch the puzzle pattern again                 *\n"
		"*  h. hint:         get a hint about the puzzle (reduced reward)   *\n"
		"*  i. instructions: see instructions for this puzzle               *\n"
		"*  q. quit:         quit solving the puzzle and do something else  *\n"
		"********************************************************************\n");
	/********** Start of the puzzle **********/
	puzzle:
		printf("\nWhat would you like to do? c/k/p/h/i/q\n");
		char user_intent = fgetc(stdin);
		fflush(stdin);		// flush the input buffer

		if(tolower(user_intent) == 'q'){		// user wants to quit the puzzle
			return;
		} else if (tolower(user_intent) == 'i'){
			goto instructions;
		} else if (tolower(user_intent) == 'h'){
			printf("\n%s\n", graffiti_hint->detailed_description); 	//show hint for the graffiti_puzzle
			graffiti_hint->state = used;
			goto puzzle;
		} else if (tolower(user_intent) == 'k'){
			goto keypad;
		} else if (tolower(user_intent) == 'p'){
			goto pattern;
		} else if (tolower(user_intent) == 'c'){
			/***** Watch the pattern *****/
			pattern:
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
			/***** start pressing the keypad *****/
			keypad:
				printf("\nWhich key would you like to press?\n");
				int user_result = 10;	// initialize with an invalid keypad number
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
					"\n", user_result);

					if (user_result == 4){
						graffiti_puzzle->state = solved;
						printf("Suddenly, all the slots light up!\n"
						"In place of the question mark, you now see a 4.\n"
						"The keypad doesn't respond to your presses anymore.\n"
						"Congrats! You have solved this puzzle!\n");
						check_solved_stage2();		// check if all puzzles have been solved
						return;
					} else {
						printf("But nothing happened!\n");
					}
				} else {
					printf("\nI'm not sure what you're trying to do.\n"
					"Even elementary kids know what a single-digit number is!\n");
				}
				goto puzzle;
		} else {
			printf("It seems you don't want to do anything at all!\n");
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
    		printf("Enter h for a hint, but be careful! Your prize will be affected\n");
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
    		else if (strcmp(noteString, "h") == 0) {
    			fflush(stdin);
    			printf("%s", piano_hint->detailed_description);
    			printf("Press the ENTER key to continue\n");
    			piano_hint->state = used;
    			getchar();
    		}
    		else {
    			printf("\n");
    			printf("The out of tune piano is ghastly to listen to.\n");
    			printf("This string of notes doesn't sound like a song at all\n");
    			printf("Maybe there is sheet music nearby?\n");
    		}
    	}
		
		printf("\n");
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
    		printf("Enter h for a hint, but be careful! Your prize will be affected\n");
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
    		else if (strcmp(noteString, "h") == 0) {
    			fflush(stdin);
    			printf("%s", piano_hint->detailed_description);
    			piano_hint->state = used;
    			printf("Press the ENTER key to continue\n");
    			getchar();
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
      fflush(stdin);        // flush the input buffer
}

void trigger_puzzle6(){



    printf("This a riddle and it requires ONE letter \n");
    printf("To quit press q \nTo get a hint press h \n");
    printf("Do you want to start y/n \n");

    char user_input = fgetc(stdin);
    fflush(stdin);


    if(tolower(user_input) == 'n')
    {
        return;
    }else {
        int done = 0;
        char *answer = "E";

        printf("I APPEAR 3 TIMES IN SEPTEMBER 2 TIMES IN NOVEMBER 1 TIME IN FEBURARY BUT NEVER IN JULY \n");
        printf(" WHAT AM I \n");

        while(!done)
        {
            char word[2];
            scanf("%1s", word);

            capitalize(word);

            if(strcmp(word,"Q") == 0)
            {
                fflush(stdin);
                return;
            }else if(strcmp(word,"H") == 0 )
            {
                fflush(stdin);
                printf("\n%s\n",riddle_hint->detailed_description);
                riddle_hint->state = used;
            }else if (strcmp(word,answer) == 0){
                done = 1;
                printf("This riddle has been solved hurray \n");
                riddle_puzzle->state = solved;
                check_solved_stage2();

            }else {

                printf("You failed please check the hint \n");
                printf("Please examine object again \n");
                printf("TRY AGAIN or q to quit \n");

            }
        }
    }
	fflush(stdin);        // flush the input buffer
    return;
}



void trigger_puzzle7(){

	printf("\nYou found a code-puzzle!\n");
	/********** Instructions for puzzle 7 **********/
	instructions:
		printf("\nInstructions:\n"
		"********************************************************************\n"
		"*  c. continue:     continue solving the puzzle                    *\n"
		"*  k. keypad:       start using the keypad of the blue_lock        *\n"
		"*  v. view:         view the clues in the manual again             *\n"
		"*  h. hint:         get a hint about the puzzle (reduced reward)   *\n"
		"*  i. instructions: see instructions for this puzzle               *\n"
		"*  q. quit:         quit solving the puzzle and do something else  *\n"
		"********************************************************************\n");
	/********** Start of the puzzle **********/
	puzzle:
		printf("\nWhat would you like to do? c/k/v/h/i/q\n");
		char user_intent = fgetc(stdin);
		fflush(stdin);		// flush the input buffer

		if(tolower(user_intent) == 'q'){		// user wants to quit the puzzle
			return;
		} else if (tolower(user_intent) == 'i'){
			goto instructions;
		} else if (tolower(user_intent) == 'h'){
			printf("\n%s\n", code_hint->detailed_description); 	//show hint for the code_puzzle
			code_hint->state = used;
			goto puzzle;
		} else if (tolower(user_intent) == 'k'){
			goto keypad;
		} else if (tolower(user_intent) == 'v'){
			goto clues;
		} else if (tolower(user_intent) == 'c'){
			printf("\n... ... ...\n"
			"\nFinally, you find five sentences that seems to relate to a hidden code.\n");
		/***** View the relevant clues *****/
			clues:
				printf("\nYou carefully explore the relevant pages...\n\n"
				"manual page 47\n"
				"---------------\n"
				"[7] [8] [2]\n"
				"clue: one number is correct\n"
				"and well placed.\n\n");

				printf("manual page 132\n"
				"---------------\n"
				"[7] [0] [4]\n"
				"clue: one number is correct\n"
				"but wrongly placed.\n\n");

				printf("manual page 139\n"
				"---------------\n"
				"[4] [8] [1]\n"
				"clue: nothing is correct.\n\n");

				printf("manual page 241\n"
				"---------------\n"
				"[2] [1] [7]\n"
				"clue: two numbers are correct\n"
				"but wrongly placed.\n\n");

				printf("manual page 438\n"
				"---------------\n"
				"[8] [2] [1]\n"
				"clue: one number is correct\n"
				"but wrongly placed.\n\n");

				printf("With these hints you might be able to figure out\n"
				"the code of the blue_lock!\n");
				goto puzzle;

			keypad:
				printf("\nYou check the keypad of the blue_lock.\n"
				"it seems you will need a 3-digit key to open it.\n");

				printf("\nWhich keys would you like to press?\n");
					int user_result = 0;		// initialize with an invalid keypad number
					scanf("%d", &user_result);
					fflush(stdin);
					if (user_result >= 100 && user_result <= 999){
						printf("\nYou entered [%d].\n", user_result);

						if (user_result == 372){
							code_puzzle->state = solved;
							blue_lock->state = open;
							printf("You hear a mechanized sound!\n"
							"The blue_lock unlocks in front of your eyes.\n"
							"The keypad doesn't respond to your presses anymore.\n"
							"Congrats! You have found the hidden code and solved this puzzle!\n");
							check_solved_stage3();		// check if all puzzles have been solved
							return;
						} else {
							printf("But nothing happened!\n");
						}
					} else {
						printf("\nI'm not sure what you're trying to do.\n"
						"You should go back to school and learn about three-digit numbers first!\n");
					}
					goto puzzle;
		} else {
			printf("It seems you don't want to do anything at all!\n");
		}
}


void trigger_puzzle8()
{
 	char * telephone_num = "3210225";
 	char makes_call[10];
	printf("Friend: Alright, listen closely, I have a story to tell.\n");
	printf("\n");
	printf("So I started running again, I went to the gym and I haven't\n");
	printf("ran since September. I'm really out of shape, I'll tell you\n");
	printf("I ran three laps, and I was gasping for air at the end of it\n");
	printf("I decided to see the Parliament Building to sort of cool down, but I was stuck\n");
	printf("in this roundabout, so many pedestrians, it took me two times to get out of there.\n");
	printf("When I finally got there, I managed to count the provinces on a monument, all ten of them.\n");
	printf("I realized I can't keep this fitness charade up for long,\n");
	printf("So I drove to pizza pizza, and its so nice, I had two slices.\n");
	printf("After that, I listened to 'It takes two to tango' by Louis Armstrong\n");
	printf("In the car on the ride home. I am really looking forward to a five\n");
	printf("O'Clock dinner tonight with our families\n");
	printf("\n");
	printf("Say, can you call your mother and tell her you won't make it?\n");
	printf("You should know her number by heart, and if not\n");
	printf("I've told what it is earlier in my story\n");
	printf("\n");
	printf("Your friend has hung up.\n");
	printf("Do you call your mother? (y/n) ");
	scanf("%s", makes_call);
	if (strcmp(makes_call, "y") == 0)
	{
		int done = 0;
		while (!done) {
			printf("Enter a telephone number to dial. No area code, just a seven digit number\n");
			printf("Enter h for a hint, however be warned, using hints affects your score!\n");
			printf("Enter q to quit: ");
			scanf("%s", makes_call);

			if (strcmp(makes_call, "q") == 0){
				return;
			}
			if (strcmp(makes_call, "h") == 0){
				phone_hint->state = used;
				printf("%s", phone_hint->detailed_description);
			}
			if (strcmp(makes_call, telephone_num) == 0)
			{
				printf("You have dialed your mother!\n");
				printf("Puzzle is solved\n");
				done  = 1;
			}
			else
			{
				printf("Stranger: Sorry, I think this is the wrong number!\n");

			}

		}
		phone_puzzle->state = solved;
		check_solved_stage3();
		

	}
	fflush(stdin);
}

void trigger_puzzle9(){


    printf("This is a riddle and it requires a THREE letter word \n");
    printf("To quit press q \nTo get a hint press h \n");
    printf("Do you want to start y/n \n");


    char user_input = fgetc(stdin);
    fflush(stdin);

    if( tolower(user_input) == 'n')
    {
        return;
    }else {

        int done = 0;
        char *answer = "AGE";

        printf(" I GOES UP BUT DOESN'T COME DOWN \n");
        printf(" WHAT AM I \n");

        while(!done)
        {
            char word[4];
            scanf("%3s", word);
            capitalize(word);

            if(strcmp(word,"Q") == 0)
            {
                fflush(stdin);
                return;
            }else if(strcmp(word,"H") == 0 )

            {
                fflush(stdin);
                printf("\n%s\n",cupboard_hint->detailed_description);
                cupboard_hint->state = used;
            }else if (strcmp(word,answer) == 0){
                done = 1;
                printf("Hurray the riddle in the cupboard has been solved \n");
                cupboard_puzzle->state = solved;
                check_solved_stage3();


            }else {

                printf("The riddle is not yet solved you can use the hint \n");
                printf("Please examine object again \n");
                printf("TRY AGAIN or q to quit \n");

            }
        }
    }
	fflush(stdin);
    return;

}

