#include "Thread.h"

void create_threads(int state[6][3][3], int max_depth) {
	pthread_t threads[NUM_THREADS];
	int rc;
	long t;
	thread_struct *args;

	for (t=0; t<NUM_THREADS; t++) {
		thread_struct *args = malloc(sizeof *args);
		args->rotation = convert_int_to_rotation(t);
		args->degrees = Ninety;
		memcpy(args->state, state, sizeof(state));
		args->max_depth = max_depth;
		printf("Starting thread #%d\n", t);

		rc = pthread_create(&threads[t], NULL, dfsSolve, args);
		if (rc) {
			free(args);
			fprintf(stderr, "%s\n", "Thread creation failed");
			exit(-1);
		}
	}

	for (t=0; t<NUM_THREADS; t++) {
		pthread_join(threads[t], NULL);
	}
}

