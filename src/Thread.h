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

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

class Thread {
    void *createThread(void *threadid);
};

#endif
