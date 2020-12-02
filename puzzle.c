#include <stdio.h>
#include "object.h"
#include "ctype.h"

/**
 * The first puzzle triggered from the clock
 */
void trigger_puzzle1(){
	printf("Do you want to manually set the time? y/n\n");
	char user_intent = fgetc(stdin);
	printf("\n");
	
	if(tolower(user_intent) == 'n'){
		return;
	} else if (tolower(user_intent) == 'y'){
		do {
			int hour_hand, minute_hand = 0;
			printf("Set hour hand to: ");
			scanf("%d", &hour_hand);
			printf("Set minute hand to: ");
			scanf("%d", &minute_hand);
			if (hour_hand>=1 && hour_hand<=12 && minute_hand>=0 && minute_hand<=59){
//				printf("\nThe time is now  %d:%d\n", hour_hand, minute_hand);
				if (hour_hand==7 && minute_hand==12){
					puzzle1->state = solved;
					printf("Suddenly, the clock starts to tick!\n"
					"There seems to be a different energy source somewhere.\n"
					"But that doesn't seem to be quite enough as the clock stops again.\n"
					"Congrats! You have solved this puzzle!\n\n");
					return;
				} else {
					printf("Nothing else happened!\n\n");
				}
			} else {
				printf("\nI'm not sure what you're trying to do.\n"
				"You must have never seen a real clock!\n\n");
			}
			printf("Do you want to try again? y/n\n");
			user_intent = fgetc(stdin);
		} while(tolower(user_intent) == 'y');
	} else {
		printf("It seems you want to do neither!\n");
	}
}