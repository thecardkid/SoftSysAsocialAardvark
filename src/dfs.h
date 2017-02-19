#ifndef SOFTSYS_ASOCIAL_AARDVARK_DFS_H
#define SOFTSYS_ASOCIAL_AARDVARK_DFS_H

#include "Enums.h"

char* dfsSolve(thread_struct args);
char* dfsSolveHelper(int*** state, int*** solution, char* moves, int depth, int n);
int equalStates(int*** state, int*** solution);
void rotate(int*** state, char movement);

#endif
