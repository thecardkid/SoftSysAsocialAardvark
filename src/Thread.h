// rotateXLeft
// rotateXRight
// rotateYTop
// rotateYBottom
// rotateZFront
// rotateZBack
// rotateXSlice
// rotateYSlice
// rotateZSlice

#ifndef SOFTSYS_ASOCIAL_AARDVARK_THREAD_H
#define SOFTSYS_ASOCIAL_AARDVARK_THREAD_H

#define NUM_THREADS 9

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "Enums.h"

typedef struct {
  LetterNotation rotation;
  Degrees degrees;
  int*** state;
  int max_depth;
} thread_struct;

void create_threads(int*** state, int max_depth);

#endif
