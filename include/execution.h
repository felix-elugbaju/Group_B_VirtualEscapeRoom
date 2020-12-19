/**
 * This header file contains the core execution functions used by parse_and_execute()
 */

#ifndef __EXECUTION_H__
#define __EXECUTION_H__

/**
 * \brief Executed when the player is trying to look around the stage
 * 
 * @param[in] arg Either "around" or "closely"
 */
extern void execute_look(const char *arg);

/**
 * \brief Executed when the player is trying to examine an object to get more detail
 * 
 * @param[in] arg Tag of an object to retrieve and examine
 */
extern void execute_examine(const char *arg);

/**
 * \brief Attempt to "read" an object with a given tag matching `arg`
 * 
 * @param[in] arg Tag of an object to retrieve and read
 */
extern void execute_read(const char *arg);

/**
 * \brief Executed when the player is trying to go to a new stage
 * 
 * @param[in] arg Tag of a location to go to
 */
extern void execute_go(const char *arg);

/**
 * \brief Executed when the player tries to put a usable item into their bag
 * 
 * @param[in] arg Tag of an object to get
 */
extern void execute_get(const char *arg);

/**
 * \brief Attempt to use item with tag `arg`
 * 
 * @param[in] arg TODO
 */
extern void execute_use(const char *arg);

/**
 * \brief Attempt to open door with tag `arg`
 * 
 * @param[in] arg TODO
 */
extern void execute_open(const char *arg);

/**
 * \brief Executed when the player needs directions for common commands
 */
extern void execute_help(void);

/**
 * \brief Executed when player tries to view a map of the world
 */
extern void execute_map(void);

/**
 * \brief TODO
 * 
 * @param[in] arg TODO
 */
extern void execute_call(const char *arg);

/**
 * \brief Executed when the player tries to check what they currently have in their bag
 */
extern void execute_check(void);

#endif//__EXECUTION_H__
