#include <stdio.h>
#include <string.h>
#include "arghandling.h"

OBJECT_t *get_object(const char *arg){
	OBJECT_t *obj, *result = NULL;
	for (obj = objs; obj < end_of_objs; obj++){			// scan through the object list (objs)
		if (object_has_tag(obj, arg)){
			result = obj;			// set result to a pointer to the matching object
		}
	}
	return result;			// return the result. If no match was found, return a NULL pointer
}