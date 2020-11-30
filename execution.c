#include <stdio.h>
#include <string.h>
#include "arghandling.h"
#include "object.h"
#include "helper.h"


void execute_read(const char *arg){
	if ((arg != NULL)){
		OBJECT_t *obj = get_object(arg);
		if (obj == NULL){
			/* When the examination target doesn't match any object */
			printf("Unfortunately, no new information was found\n");
		} else if (!(obj->type == hidden_object)){
			/* When the examination is not possible because of type restrictions */
			printf("This does not seem to be readable\n");
		} else {
			/* Show detailed description of the object */
			printf("You read the contents of the %s\n", obj->tag);
			printf("%s\n", obj->detailed_description);
		}
	} else {
		/* When there's no examination target */
		printf("Maybe you should decide what to read first\n");
	}
}


void execute_get(const char *arg){
	if (arg == NULL){
		printf("Maybe you should decide what to get first\n");	
		return;
	}
	OBJECT_t *obj = get_object(arg);
	if (obj == NULL){
		printf("%s does not exist in this world!!\n", arg);		// if no such object exists
	} else if (obj->type != usable_object){
		printf("%s is too large to fit in your bag\n", arg);	
	} else if (obj->location == player){					
		printf("You already have %s\n", arg);
	} else if (obj->location != player->location){			// player and object are not in the same location
		printf("You don't see any %s in here\n", arg);		// player might try to get key2 while in stage1
	} else {
		if (strcmp(arg, "key1") == 0){
			/** Conditions for getting key1 **/
			if (puzzle1->state == solved){
				obj->location = player;				
				printf("You moved %s to your bag\n", arg);
			} else {
				printf("You have not found %s yet\n", arg);
			}
		} else if (strcmp(arg, "key2") == 0){
			/** Conditions for getting key2 **/
			obj->location = player;				
			printf("You moved %s to your bag\n", arg);
		} else if (strcmp(arg, "key3") == 0){
			/** Conditions for getting key3 **/
			obj->location = player;				
			printf("You moved %s to your bag\n", arg);
		}
	}
}
}