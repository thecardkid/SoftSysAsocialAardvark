#include "Thread.h"

int start = 0;
int end = 6;

void create_threads(int state[6][3][3], int max_depth) {
	pthread_t threads[NUM_THREADS];
	int rc;
	long t;
	thread_struct *args;
	thread_return_struct *return_struct;

	for (t=start; t<end; t++) {
		thread_struct *args = malloc(sizeof *args);
		args->rotation = convert_int_to_rotation(t);
		args->degrees = Ninety;
		memcpy(args->state, state, 27*sizeof(state));
		args->max_depth = max_depth;
		printf("Starting thread #%d\n", t);

        rc = pthread_create(&threads[t], NULL, dfsSolve, args);
        if (rc) {
            free(args);
            fprintf(stderr, "%s\n", "Thread creation failed");
            exit(-1);
        }
    }

	for (t=start; t<end; t++) {
		pthread_join(threads[t], &return_struct);
		printf("Thread %d worked %d\n", t, return_struct->status);
		printMoves(return_struct->solveMoves, max_depth);
	}
}

