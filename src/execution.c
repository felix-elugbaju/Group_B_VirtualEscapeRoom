#include <stdio.h>
#include <string.h>
#include "arghandling.h"
#include "object.h"
#include "helper.h"
#include "puzzle.h"


bool execute_leave()
{
	if (stage1->state == unrestricted && stage2->state == unrestricted && stage3->state == unrestricted){
		printf("CONGRATS!!\n"
		"You have just cleared the game!\n");
		printf("I wish you well on your next adventure!\n");
		printf("Farewell!\n");
		return false;
	}
	printf("You must solve all three rooms before you win the game\n");
	return true;
}


void execute_look(const char *arg){
	if (arg != NULL){
		if ((strcmp(arg, "around") == 0)){
			printf("You are in %s.\n", player->location->description);
			list_objects_at_location(player->location, visible_object);
		} else if (strcmp(arg, "closely") == 0){
			if(player->location == graffiti_puzzle->location){
				trigger_puzzle4();
			} else {
				printf("There's nothing here that warrants that much attention!");
			}
		} else {
			/* Another witty message dictating what the user sees when he tries to look at something weird */
			printf("Even you're not sure what you want to see.\n");
		}
	} else {
		printf("Do you even want to see anything?.\n");
	}
}

void execute_examine(const char *arg){
	if ((arg != NULL)){
		OBJECT_t *obj = get_object(arg);
		if (obj == NULL){
			/* When the examination target doesn't match any object */
			printf("Unfortunately, you couldn't find anything new\n");
		} else if (!(obj->type == visible_object || obj->type == usable_object)){
			/* When the examination is not possible because of type restrictions */
			printf("Maybe you should try to examine something different\n");
		} else {
			/* Show detailed description of the object */
			printf("You carefully examine the %s\n", obj->tag);
			printf("%s\n", obj->detailed_description);
			/** Trigger puzzle1 **/
			if (strcmp(arg, "clock") == 0 && player->location == stage1){
				trigger_puzzle1();
			} else if (strcmp(arg, "manual") == 0 && player->location == stage3){
				trigger_puzzle7();
			}
            if (strcmp(arg, "jigsaw_puzzle") == 0 && player->location == stage1) {
                trigger_puzzle2();
            }

            if (strcmp(arg, "treasure_bag") == 0 && player->location == stage1) {
                trigger_puzzle3();
            }
            if (strcmp(arg, "old_piano") == 0 && player->location == stage2)
            {
            	trigger_puzzle5();
            }

            if (strcmp(arg, "pirate_chest") == 0 && player->location == stage2) {
                trigger_puzzle6();
            }

            if (strcmp(arg, "cupboard") == 0 && player->location == stage3) {
                trigger_puzzle9();
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
		"You should look for a way to open doors\n");
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
		printf("You don't see any %s in here\n", arg);		// player might try to get gold_key while in stage1
	} else {
		if (strcmp(arg, "silver_key") == 0){
			/** Conditions for getting silver_key **/
			if (silver_key->state == revealed){
				obj->location = player;
				printf("You moved %s to your bag\n", arg);
			} else {
				printf("You have not found %s yet\n", arg);
			}
		} else if (strcmp(arg, "gold_key") == 0){
			/** Conditions for getting gold_key **/
			obj->location = player;
			printf("You moved %s to your bag\n", arg);
		} else if (strcmp(arg, "ruby_key") == 0){
			/** Conditions for getting ruby_key **/
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
		if (strcmp(obj->tag,"silver_key")==0 && strcmp(player->location->tag,"stage1")==0)	{
			if (silver_door->state == open){
				printf("The silver door seems to be already open\n");
			} else {
				silver_door->state = open;
				printf("You used %s on the silver door\nThe door can now be opened\n", arg);
			}
		} else if (strcmp(obj->tag,"gold_key")==0 && strcmp(player->location->tag,"stage2")==0)	{
			if (gold_door->state == open){
				printf("The gold door seems to be already open\n");
			} else {
				gold_door->state = open;
				printf("You used %s on the gold door\nThe door can now be opened\n", arg);
			}
		} else if (strcmp(obj->tag,"ruby_key")==0 && strcmp(player->location->tag,"stage3")==0)	{
			if (ruby_door->state == open){
				printf("The ruby door seems to be already open\n");
			} else {
				ruby_door->state = open;
				printf("You used %s on the ruby door\nThe door can now be opened\n", arg);
			}
		} else {
			printf("Nothing happened!\n");
		}
	} else {
		printf("Nothing happened!\n");
	}
}

bool execute_open(const char *arg){
	if (arg == NULL){
		printf("Maybe you should find something to open first\n");
		return true;
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
		return execute_leave();
	}
	return true;
}

void execute_map(){
	printf("\n"
"**********                 \n" 
"*        *<********        \n"
"* stage1 *        *        \n"
"*        *******  *        \n"
"**********     *  *        \n"
"  *	^      V  *        \n"
"  *     *    **********     \n"
"  *	*    *        *     \n"
"  *	*    * stage2 *     \n"
"  *	*    *        *     \n"
"  *	*    **********     \n"
"  V	*      ^  *        \n"
"**********     *  *        \n"
"*        *******  *        \n"
"* stage3 *        *        \n"
"*        *<********        \n"
"**********\n");
}

void execute_call(const char *arg)
{
	char user_response[10];
	if(player->location != phone->location)
	{
		printf("You call out, but no one answers!\n");
		return;
	}
	
	if (strcmp(arg, "friend") == 0)
	{
		printf("*Ring Ring*\n");
		printf("*Ring Ring*\n");
		printf("Friend:Hello player! This is your best friend! How've you been?\n");
		printf("Oh, you're stuck in an escape room?\n");
		printf("Well let me tell you a story, if you have time that is.\n");
		printf("\n");
		printf("Do you want to here your friend's story?(y/n)");
		scanf("%s", user_response);
		
		if (strcmp(user_response, "y") == 0){
			trigger_puzzle8();
		}
		else
		{
			printf("Friend: No worries! Just call me again if you have time\n");
			printf("Goodbye!\n");
			printf("*Click*\n");
		
		}
	
	
	}
	else
	{
		printf("You should probably find someone to call. A friend perhaps?\n");
		return;
	}
	fflush(stdin);

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
	"*  8. help:             get a list of helpful common commands                *\n"
	"*  9. map:              display a map showing this world                     *\n"
    "* 10. quit:             exit the program gracefully                          *\n"
	"******************************************************************************\n");
}
