#include "Thread.h"
#include "dfs.h"

// void *doThread(void *threadid) {
    // long tid;
    // tid = (long)threadid;
    // printf("Hello world! Thread #%ld!\n", tid);
    // pthread_exit(NULL);
// }

void createThread() {
  pthread_t threads[NUM_THREADS];
  int rc;
  long t;
  for (t=0; t<NUM_THREADS; t++) {
    rc = pthread_create(&threads[t], NULL, dfsSolve, (void *)t);
    if (rc) {
      // TODO: @pip error nicely
      exit(-1);
    }
  }
  pthread_exit(NULL);
}
