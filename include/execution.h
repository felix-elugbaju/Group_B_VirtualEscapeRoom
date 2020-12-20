/**
 * @file execution.h
 * @brief Core execution functions used by parse_and_execute()
 */

#ifndef __EXECUTION_H__
#define __EXECUTION_H__

/**
 * @brief Executed when the player is trying to look around the stage
 * 
 * Gives some details about the current stage, by either specifying \p arg
 * as "around" or "closely". Does nothing useful when another string is passed.
 * 
 * @param[in] arg Either "around" or "closely"
 */
extern void execute_look(const char *arg);

/**
 * @brief Executed when the player is trying to examine an object to get more detail
 * 
 * Gives more detail about a specific object. Objects are looked up by tag and matched against
 * \p arg .
 * 
 * @param[in] arg Tag of an object to retrieve and examine
 */
extern void execute_examine(const char *arg);

/**
 * @brief Attempt to "read" an object with a given tag matching `arg`
 * 
 * Read is performed by printing out the object's detailed information,
 * if the object is not hidden or otherwise inaccessible.
 * 
 * @param[in] arg Tag of an object to retrieve and read
 */
extern void execute_read(const char *arg);

/**
 * @brief Executed when the player is trying to go to a new stage
 * 
 * Attempts to move to a location specified by \p arg . The location is looked up
 * by tag value.
 * 
 * @param[in] arg Tag of a location to go to
 */
extern void execute_go(const char *arg);

/**
 * @brief Executed when the player tries to put a usable item into their bag
 * 
 * Attempts to put an item referred to by tag value \p arg into the player's bag.
 * 
 * @param[in] arg Tag of an object to get
 */
extern void execute_get(const char *arg);

/**
 * @brief Executed when the player tries to use an item
 * 
 * Attempt to use item with tag \p arg . Does nothing useful if the item cannot be used.
 * 
 * @param[in] arg Tag of item to use
 */
extern void execute_use(const char *arg);

/**
 * @brief Executed when the player tries to open a door
 * 
 *  Attempt to open door with tag `arg`. This may do nothing useful if the door is locked.
 * 
 * @param[in] arg Tag of item to open
 */
bool execute_open(const char *arg);

/**
 * @brief Executed when the player needs directions for common commands
 * 
 * Prints information on available commands.
 */
extern void execute_help(void);

/**
 * @brief Executed when player tries to view a map of the world
 * 
 * Print out a textual representation of the game map, which lays out where
 * stages are relative to eachother.
 */
extern void execute_map(void);

/**
 * @brief Executed when the player attempst to make a call (mostly used for calling a friend)
 * 
 * Attempts a call. If \p arg is "friend", triggers the start of puzzle 8, otherwise,
 * prints an error message.
 * 
 * @param[in] arg Name to call.
 */
extern void execute_call(const char *arg);

/**
 * @brief Executed when the player tries to check what they currently have in their bag
 * 
 * Prints a list of usable items in the current stage.
 */
extern void execute_check(void);

/**
 * @brief Executed when the player tries to leave the final stage
 * 
 * Prints a congratulatory message if all three stages have been cleared.
 * Otherwise, prints an error message.
 */
bool execute_leave(void);

#endif//__EXECUTION_H__
