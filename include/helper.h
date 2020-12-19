/**
 * This header file contains some helper functions
 */

#ifndef __HELPER_H__
#define __HELPER_H__

/**
 * @brief Lists all objects of a certain type in a given location
 * 
 * @param[in] location The specific stage or location
 * @param[in] type The type of objects to show
 * @return The count of listed object, 0 in case of no list
 */
extern int list_objects_at_location(OBJECT_t *location, type_t type);

/**
 * @brief Checks whether all puzzles in stage 1 has been solved
 */
extern void check_solved_stage1();

/**
 * @brief Checks whether all puzzles in stage 2 has been solved
 */
extern void check_solved_stage2();

/**
 * @brief Checks whether all puzzles in stage 3 has been solved
 */
extern void check_solved_stage3();

/**
 * @brief Calculates the amount of hints used in that particular stage, and prints a reward
 * 
 * @param[in] stage Stage number
 */
extern void get_reward(int stage);

/**
 * @brief Capitalize a string
 * 
 * Modifies input by capitalizing each character
 * 
 * @param[in,out] word String to capitalize
 */
extern void capitalize(char *word);

#endif//__HELPER_H__
