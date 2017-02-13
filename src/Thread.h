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

void *doThread(void *threadid);
void createThread();

#endif
