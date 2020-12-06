/**
 * This header file contains functions that define how to deal with user input <arg>
 * bool objectHasTag(): whether user input <arg> matches any OBJECT tag
 * OBJECT getObject(): get a valid pointer (match) to an OBJECT, or a NULL pointer (failure)
 */
 
#ifndef __ARGHANDLING_H__
#define __ARGHANDLING_H__
#include <stdbool.h>
#include "object.h"


/**
 * @brief a function to return whether the user's argument has a matching tag
 * @param[in] obj an stored object
 * @param[in] arg the argument value provided by the user
 * @return 1 in case of a match, 0 otherwise
 */
extern bool object_has_tag(OBJECT_t *obj, const char *arg);

/**
 * @brief a function to scan through the object list to find a matching object
 * @param[in] arg the argument value provided by the user
 * @return the pointer to a matching object, NULL if no match found
 */
extern OBJECT_t *get_object(const char *arg);


#endif