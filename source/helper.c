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
	if (puzzle1->state == solved && puzzle2->state == solved){
		key1->state = revealed;		//reveal the first key
		printf("\nYou hear a clank!\n"
		"Suddently, out of nowhere, a silver key falls in front of you.\n"
		"The color of the key seems to resemble that of the door.\n");
		return;
	}
}