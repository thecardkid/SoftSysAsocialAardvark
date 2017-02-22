#ifndef SOFTSYS_ASOCIAL_AARDVARK_THREAD_H
#define SOFTSYS_ASOCIAL_AARDVARK_THREAD_H

#define NUM_THREADS 9

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "dfs.h"
#include "Enums.h"

void create_threads(int*** state, int max_depth);
LetterNotation convertIntToRotation(int x);

#endif
