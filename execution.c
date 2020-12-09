#include <stdio.h>
#include <string.h>
#include "arghandling.h"
#include "object.h"
#include "helper.h"


void execute_look(const char *arg){
	if ((arg != NULL) && (strcmp(arg, "around") == 0)){
		printf("You are in %s.\n", player->location->description);
		list_objects_at_location(player->location, visible_object);
	}
	else {
		/* Another witty message dictating what the user sees when he tries to look at something weird */
		printf("Even you're not sure what you want to see.\n");
	}
}

void execute_examine(const char *arg){
	if ((arg != NULL)){
		OBJECT_t *obj = get_object(arg);
		if (obj == NULL){
			/* When the examination target doesn't match any object */
			printf("Unfortunately, you couldn't find anything new\n");
		} else if (!(obj->type == visible_object)){
			/* When the examination is not possible because of type restrictions */
			printf("Maybe you should try to examine something different\n");
		} else {
			/* Show detailed description of the object */
			printf("You carefully examine the %s\n", obj->tag);
			printf("%s\n", obj->detailed_description);
			/** Trigger puzzle1 **/
			if (strcmp(arg, "clock") == 0 && player->location == stage1){
				trigger_puzzle1();
			}
		}
	} else {
		/* When there's no examination target */
		printf("Maybe you should decide what you want to examine first\n");
	}
}

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

void execute_go(const char *arg){
	if (arg == NULL){
		printf("Maybe you should decide where to go first\n");	
		return;
	}
	OBJECT_t *obj = get_object(arg);
	if (obj == NULL){
		printf("%s does not exist in this world!!\n", arg);		// if no such place exists
	} else if (obj == player->location){			// player is trying to move to where he already is
		printf("You're already in %s\n", arg);	
	} else if (obj->type != location){			// trying to move to a non-location
		printf("%s is not a location\n", arg);
	} else if (player->location->state == confined){			// trying to move from a confined loaction
		printf("It seems that all exits from this room are sealed\n"
		"You should look for a way to open doors\n", arg);
	} else if (player->location->state == unrestricted){			// move from an unrestricted area
		printf("Moving...\n");
		printf("... ... ...\n");
		player->location = obj;					// player is in a new location now, update his location
		execute_look("around");					// look around to see the new place
	} else {
		printf("You're really don't want to move to %s right now, it's dangerous!\n", arg);
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
			if (puzzle1->state == solved && puzzle2->state == solved){
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

void execute_check(void){
	if (list_objects_at_location(player, usable_object) == 0){
		printf("You couldn't find anything of importance\n");
	}
}

void execute_use(const char *arg){
	if (arg == NULL){
		printf("Maybe you should decide what you want to use first\n");	
		return;
	}
	OBJECT_t *obj = get_object(arg);
	if (obj == NULL){
		printf("%s does not exist in this world!!\n", arg);		// if no such object exists
	} else if (obj->type != usable_object){
		printf("%s is not usable\n", arg);	
	} else if (obj->location != player){					// player does not have object yet
		printf("You have not found %s yet\n", arg);	
	} else if (obj->location == player){					
		if (strcmp(obj->tag,"key1")==0 && strcmp(player->location->tag,"stage1")==0)	{
			if (door1->state == open){
				printf("The silver door seems to be already open\n");
			} else {
				door1->state = open;
				printf("You used %s on the silver door\nThe door can now be opened\n", arg);
			}
		} else if (strcmp(obj->tag,"key2")==0 && strcmp(player->location->tag,"stage2")==0)	{
			if (door2->state == open){
				printf("The gold door seems to be already open\n");
			} else {
				door2->state = open;
				printf("You used %s on the gold door\nThe door can now be opened\n", arg);
			}
		} else if (strcmp(obj->tag,"key3")==0 && strcmp(player->location->tag,"stage3")==0)	{
			if (door3->state == open){
				printf("The ruby door seems to be already open\n");
			} else {
				door3->state = open;
				printf("You used %s on the ruby door\nThe door can now be opened\n", arg);
			}
		} else {
			printf("Nothing happened!\n", arg);
		}
	} else {	
		printf("Nothing happened!\n", arg);
	}
}

void execute_open(const char *arg){
	if (arg == NULL){
		printf("Maybe you should find something to open first\n");	
		return;
	}
	OBJECT_t *obj = get_object(arg);
	if (obj == NULL){
		printf("%s does not exist in this world!!\n", arg);		// if no such object exists
	} else if (obj->location != player->location){				// door and player not in the same room
		printf("You don't see any %s in here\n", arg);	
	} else if (obj->state == closed){					
		printf("It seems that %s is locked\n"
		"You should find something that can open it\n", arg);				
	} else {			// Push and open the door
		player->location->state = unrestricted;
		printf("The door opens with a loud creak!\n"
		"You see two dark passages lighting up\n"
		"You are now able to move from this place\n");
	}
}

void execute_help(){
	printf("Helpful Common Commands:\n"
	"******************************************************************************\n"
	"*  1. look around:      look around to find interactive objects              *\n"
	"*  2. examine <object>: examine to get detailed information about an object  *\n"
	"*  3. go <stage>:       go to a different stage                              *\n"
	"*  4. get <object>:     put a usable object in your bag for later use        *\n"
	"*  5. use <object>:     try to make use of an object in your bag             *\n"
	"*  6. open <door>:      try to open a door                                   *\n"
	"*  7. bag:              check your bag to see what you can find              *\n"
	"*  8. hint:             get a hint if you are stuck                          *\n"
	"*  9. help:             get a list of helpful common commands                *\n"
	"******************************************************************************\n");
}