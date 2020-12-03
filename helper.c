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