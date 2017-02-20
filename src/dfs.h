#ifndef SOFTSYS_ASOCIAL_AARDVARK_DFS_H
#define SOFTSYS_ASOCIAL_AARDVARK_DFS_H

char* dfsSolve(void* args);
void dfsSolveHelper(int*** state, char* moves, int depth, int n, int id);
int equalStates(int*** state);
void printState(int*** state);

#endif
