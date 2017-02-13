#include "Thread.h"

void *createThread(void *threadid) {
    long tid;
    tid = (long)threadid;
    printf("Hello world! Thread #%ld!\n", tid);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    pthread_t threads[5];
    int rc;
    long t;
    for (t=0; t<5; t++) {
        printf("In main: creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, createThread, (void *)t);
        if (rc) {
            exit(-1);
        }
    }

    pthread_exit(NULL);
}
