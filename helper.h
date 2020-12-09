/**
 * This header file contains some helper functions
 * int list_objects_at_location(): lists all objects in a given location
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


#endif