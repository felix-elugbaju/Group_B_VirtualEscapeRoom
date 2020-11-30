/**
 * This header file contains the core execution functions used by parse_and_execute()
 * void execute_look(): executed when the player is trying to look around the stage
 * void execute_examine(): executed when the player is trying to examine an object to get more detail
 * void execute_go(): executed when the player is trying to go to a new stage
 * void execute_help(): executed when the player needs directions for common commands
 * void execute_get(): executed when the player tries to put a usable item into their bag
 * void execute_check(): executed when the player tries to check what they currently have in their bag
 */

extern void execute_look(const char *arg);

extern void execute_examine(const char *arg);

extern void execute_read(const char *arg);

extern void execute_go(const char *arg);

extern void execute_get(const char *arg);

extern void execute_use(const char *arg);

extern void execute_open(const char *arg);

extern void execute_help(void);

extern void execute_check(void);