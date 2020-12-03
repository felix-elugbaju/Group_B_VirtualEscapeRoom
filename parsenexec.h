 #ifndef __PARSENEXEC_H__
 #define __PARSENEXEC_H__
 
 /**
  * This function parses the user input and separates the command 
  * and argument part of the input using the space delimiter
  * also calls other execution functions to execute the user command
  * @param[in] input the input captured from the user
  * @return whether the user wants to continue or quit
  */
extern bool parse_and_execute(char *input);

#endif