#ifndef SOFTSYS_ASOCIAL_AARDVARK_DFS_H
#define SOFTSYS_ASOCIAL_AARDVARK_DFS_H

#include <string.h>
#include <pthread.h>
#include "Shared.h"

void* dfs_solve(void* args);
int dfs_solve_helper(int*** state, LetterNotation* moves, int depth, int id);
int is_solved(int*** state);

#endif
