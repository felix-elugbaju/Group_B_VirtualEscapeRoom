#ifndef __OBJECT_H__
#define __OBJECT_H__



/***** OBJECT Types and States *****/
typedef enum type{
	location = 0,
	visible_object = 1,
	hidden_object = 2,
	usable_object = 3,
	puzzle = 4,
	hint = 5,
	actor = 6
} type_t;

typedef enum state{
	closed = 0, open = 1,				// For doors and locks
	confined = 2, unrestricted = 3,		// For stages
	unsolved = 4, solved = 5,			// For puzzles
	hidden = 6, revealed = 7,			// For keys
	used = 8, unused =9,				// For hints
	regular = 10						// generic state
} state_t;


/***** OBJECT Structure *****/
typedef struct object{
	const char *description;
	const char *tag;
	type_t type;
	state_t state;
	const char *detailed_description;
	struct object *location;
} OBJECT_t;
extern OBJECT_t objs[];


/***** Object References using symbolic names *****/
/* Stages */
#define stage1 			(objs + 0)
#define stage2 			(objs + 1)
#define stage3 			(objs + 2)
/* Actors */
#define player 			(objs + 3)
/* Objects Visible in Stage 1 */
#define table 			(objs + 4)
#define letter			(objs + 5)
#define clock 			(objs + 6)
#define jigsaw_puzzle (objs + 7)
/* Objects Visible in Stage 2 */
#define sheet_musc 		(objs + 8)
#define old_piano    		(objs + 9)
/* Doors and Keys */
#define silver_key 		(objs + 10)
#define silver_door 		(objs + 11)
#define gold_key 		(objs + 12)
#define gold_door 		(objs + 13)
#define ruby_key 		(objs + 14)
#define ruby_door 		(objs + 15)
/* Puzzles */
#define clock_puzzle 		(objs + 16)
#define sliding_puzzle 		(objs + 17)
#define piano_puzzle    	(objs + 18)
/* Hints */
#define clock_hint		(objs + 19)
#define graffiti 		(objs + 20)
#define graffiti_puzzle 	(objs + 21)
#define graffiti_hint		(objs + 22)
/* Lock with code */
#define blue_lock 		(objs + 23)
#define manual 			(objs + 24)
#define code_puzzle		(objs + 25)
#define code_hint 		(objs + 26)

/* End: always update this! */
#define end_of_objs 		(objs + 27)



#endif
