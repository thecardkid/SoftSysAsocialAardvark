#ifndef SOFTSYS_ASOCIAL_AARDVARK_DFS_H
#define SOFTSYS_ASOCIAL_AARDVARK_DFS_H

#include "Shared.h"

void* dfsSolve(void* args);
int dfsSolveHelper(int*** state, LetterNotation* moves, int depth, int id);
int equalStates(int*** state);

#endif
