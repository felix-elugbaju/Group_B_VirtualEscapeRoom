#include <stdio.h>
#include <string.h>
#include "arghandling.h"


bool object_has_tag(OBJECT_t *obj, const char *arg){
	return (arg != NULL) && (*arg != '\0') && (strcmp(arg, obj->tag) == 0);
}



OBJECT_t *get_object(const char *arg){
	OBJECT_t *obj, *result = NULL;
	for (obj = objs; obj < end_of_objs; obj++){			// scan through the object list (objs)
		if (object_has_tag(obj, arg)){
			result = obj;			// set result to a pointer to the matching object
		}
	}
	return result;					// If no match was found, return a NULL pointer
}
