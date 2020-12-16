#include <stdio.h>
#include "object.h"
#include "helper.h"


int list_objects_at_location(OBJECT_t *location, type_t type){
	int count = 0;
	OBJECT_t *obj;
	for (obj = objs; obj < end_of_objs; obj++){		// scan through the object list (objs)
		if (obj->location == location && obj != player && obj->type == type){	// No point in the player seeing himself
			if (count == 0){
				printf("You see: \n");			// Print this only at the beginning of every list
				count++;
			}
			printf("%s\n", obj->description);
		}
	}
	return count;		// return the number of OBJECTS in the list
}


void check_solved_stage1(){
	if (clock_puzzle->state == solved && sliding_puzzle->state == solved && paper_puzzle->state = solved){
		silver_key->state = revealed;		//reveal the first key
		printf("\nYou hear a clank!\n"
		"Suddenly, out of nowhere, a silver key falls in front of you.\n"
		"The color of the key seems to resemble that of the door.\n"
		"You might be able to pick up (get) the silver_key.\n");
		return;
	}
}

void check_solved_stage2(){
	if (piano_puzzle->state == solved && graffiti_puzzle->state == solved && riddle_puzzle->state = solved){
		gold_key->state = revealed;		//reveal the second key
		printf("\nYou hear a clank!\n"
		"Suddenly, out of nowhere, a gold key falls in front of you.\n"
		"The color of the key seems to resemble that of the door.\n"
		"You might be able to pick up (get) the gold_key.\n");
		return;
	}


}
