/**
 * This header file contains some helper functions
 * int list_objects_at_location(): lists all objects in a given location
 * void check_solved_stage1(): checks whether all puzzles in stage 1 has been solved
 * void check_solved_stage2(): checks whether all puzzles in stage 2 has been solved
 */
 
#ifndef __HELPER_H__
#define __HELPER_H__

/**
 * @brief lists all objects of a certain type in a given location
 * @param[in] location the specific stage or location
 * @param[in] type the type of objects to show
 * @return the count of listed object, 0 in case of no list
 */
extern int list_objects_at_location(OBJECT_t *location, type_t type);

/**
 * @brief checks whether all puzzles in stage 1 has been solved
 */
extern void check_solved_stage1();


/**
 * @brief checks whether all puzzles in stage 2 has been solved
 */
extern void check_solved_stage2();



/**
 * @brief checks whether all puzzles in stage 3 has been solved
 */
extern void check_solved_stage3();



/**
 * @brief calculates the amount of hints used in that particular stage, and prints a reward
 */
extern void get_reward(int stage);

#endif

