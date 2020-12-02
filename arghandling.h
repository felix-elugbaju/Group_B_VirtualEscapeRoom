#ifndef __ARGHANDLING_H__
#define __ARGHANDLING_H__
#include <stdbool.h>
#include "object.h"

/**
 * This header file contains functions that define how to deal with user input <arg>
 * bool objectHasTag(): whether user input <arg> matches any OBJECT tag
 * OBJECT getObject(): get a valid pointer (match) to an OBJECT, or a NULL pointer (failure)
 */

/**
 * A function that returns whether the <arg> provided by the user has a valid object target/tag or not 
 */
extern bool object_has_tag(OBJECT_t *obj, const char *arg);

/**
 * Get the pointer to a valid OBJECT or a NULL pointer (objectHasTag returns false)
 */ 
extern OBJECT_t *get_object(const char *arg);


#endif