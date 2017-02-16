#include "Thread.h"

void create_threads(int*** state, int max_depth) {
  LetterNotation letter;
  Degrees degree = Degrees.Ninety;
  pthread_t threads[NUM_THREADS];
  int rc;
  long t;
  for (t=0; t<NUM_THREADS; t++) {
    thread_struct *args = malloc(sizeof *args);
    letter = LetterNotation[t];
    args->rotation = letter;
    args->degrees = degree;
    args->state = &state;
    args->max_depth = &max_depth;
    rc = pthread_create(&threads[t], NULL, dfsSolve, args);
    if (rc) {
      free(args);
      fprintf(stderr, "%s\n", "Thread creation failed");
      exit(-1);
    }
  }
  pthread_exit(NULL);
}
