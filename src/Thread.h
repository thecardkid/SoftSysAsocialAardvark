#ifndef SOFTSYS_ASOCIAL_AARDVARK_THREAD_H
#define SOFTSYS_ASOCIAL_AARDVARK_THREAD_H

#define NUM_THREADS 9

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dfs.h"
#include "Shared.h"
;
//LetterNotation convert_int_to_rotation(int x);
thread_struct *create_args(int t);
void create_threads(int state[6][3][3], int max_depth);

#endif