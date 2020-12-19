/**
 * @file arghandling.h
 * @brief Utility functions to manipulate objects
 * 
 * This header file contains functions that define how to deal with user input `arg`.
 */
 
#ifndef __ARGHANDLING_H__
#define __ARGHANDLING_H__

#include <stdbool.h>
#include "object.h"

/**
 * @brief A function to return whether the user's argument has a matching tag
 * 
 * This function will check whether \p arg matches the tag
 * on the supplied object \p obj
 * 
 * @param[in] obj an stored object
 * @param[in] arg the argument value provided by the user
 * @return 1 in case of a match, 0 otherwise
 */
extern bool object_has_tag(OBJECT_t *obj, const char *arg);

/**
 * @brief A function to scan through the object list to find a matching object
 * 
 * This function scans through the entire object list and returns a pointer to
 * the object when @p arg matches an object’s `tag`
 * 
 * @param[in] arg the argument value provided by the user
 * @return the pointer to a matching object, NULL if no match found
 */
extern OBJECT_t *get_object(const char *arg);


#endif