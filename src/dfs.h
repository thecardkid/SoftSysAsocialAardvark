#ifndef SOFTSYS_ASOCIAL_AARDVARK_DFS_H
#define SOFTSYS_ASOCIAL_AARDVARK_DFS_H

#include "Shared.h"

/*
This is the function that should be called from each thread.  Returns a struct 
containing an array of LetterNotation enums representing the moves required
to solve the cube. This is then used by graphics to visually show the solution.
*/
void* dfs_solve(void* args);

/*
Recursively checks whether there is a solution from the given state to the solved
state in some number of moves. This function is called by dfsSolve().
*/
int dfs_solve_helper(int*** state, LetterNotation* moves, int depth, int id);

/*
Checks whether a given state is equal to the solved state. Function takes
a state represented by a triple pointer and compares it with a global. Returns
1 if the two states are equal and 0 otherwise.
*/
int is_solved(int*** state);

#endif
