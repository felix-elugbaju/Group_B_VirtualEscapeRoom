/**
 * @file puzzle.h
 * @brief Functions for executing puzzles
 */

#ifndef __PUZZLE_H__
#define __PUZZLE_H__

#define PUZZLE_LENGTH 3

/**
 * @brief A function that is triggered when the first puzzle is activated
 * 
 * Enters a mini-game which involves solving a puzzle involving a clock.
 */
extern void trigger_puzzle1();

/**
 * @brief A function that is triggered when the second puzzle is activated
 * 
 * Enters a mini-game which involves solving a puzzle involving a sliding puzzle pices.
 */
extern void trigger_puzzle2();

/**
 * @brief A function that triggered the third puzzle which is the paper puzzle
 * 
 * Enters a mini-game which involves solving a puzzle involving a piece of paper.
 */
extern void trigger_puzzle3();

/**
 * @brief A function that is triggered when the fourth graffiti_puzzle is activated
 * 
 * Enters a mini-game which involves solving a puzzle involving graffiti.
 */
extern void trigger_puzzle4();

/**
 * @brief A function that is triggered when the fifth piano_puzzle is activated
 * 
 * Enters a mini-game which involves solving a puzzle involving a piano.
 */
extern void trigger_puzzle5();

/**
 * @brief A function that triggers the sixth puzzle which is the riddle puzzle
 * 
 * Enters a mini-game which involves solving a puzzle involving a riddle.
 */
extern void trigger_puzzle6();

/**
 * @brief A function that is triggered when the seventh code_puzzle is activated
 * 
 * Enters a mini-game which involves solving a puzzle involving guessing a 3 digit
 * code based on clues.
 */
extern void trigger_puzzle7();

/**
 * @brief A function that is triggered when the eighth phone_puzzle is activated
 * 
 * Enters a mini-game which involves solving a puzzle involving calling someone.
 */
extern void trigger_puzzle8();

/**
 * @brief A function that triggers the ninth puzzle which is the cupboard puzzle
 * 
 * Enters a mini-game which involves solving a puzzle involving a cupboard.
 */
extern void trigger_puzzle9();

#endif//__PUZZLE_H__
