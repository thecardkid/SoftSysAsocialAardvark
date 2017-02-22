#ifndef SOFTSYS_ASOCIAL_AARDVARK_DFS_H
#define SOFTSYS_ASOCIAL_AARDVARK_DFS_H

char* dfsSolve(void* args);
char* dfsSolveHelper(char* moves, int depth, int n);
int equalStates(int*** state);

#endif
