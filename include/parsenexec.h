/**
 * @file parsenexec.h
 * This header file contains the function to parse the user input and execute different execution function based on the input
 */
 
#ifndef __PARSENEXEC_H__
#define __PARSENEXEC_H__
 
/**
 * @brief parses and executes the user input
 * 
 * This function parses the user input and separates the command 
 * and argument part of the input using the space delimiter.
 * Also, calls other execution functions to execute the user command
 * 
 * @param[in] input the input captured from the user
 * @return 1 in case of any input, 0 if user enters the command "quit"
 */
extern bool parse_and_execute(char *input);

#endif