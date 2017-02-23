#include "Thread.h"

int max_dfs_depth;
int*** scrambled_state;

LetterNotation convert_int_to_rotation(int x) {
    switch (x) {
        case 0: return U;
        case 1: return L;
        case 2: return F;
        case 3: return R;
        case 4: return B;
        case 5: return D;
        case 6: return M;
        case 7: return E;
        case 8: return S;
    }
}

thread_struct *create_args(int t) {
	thread_struct *args = malloc(sizeof *args);
	args->rotation = convert_int_to_rotation(t);
	args->degrees = Ninety;
	args->state = scrambled_state;
	args->max_depth = max_dfs_depth;
	return args;
}

void create_threads(int*** state, int max_depth) {
	pthread_t threads[NUM_THREADS];

	int copy_of_state[6][3][3];
	size_t destination_size = sizeof (copy_of_state);

	printf("%d\n", copy_of_state[5][2][2]);
	strncpy(copy_of_state, state, destination_size);

	int rc;
	long t;
	thread_struct *args;

	for (t=0; t<NUM_THREADS; t++) {
		args = create_args(t);
		rc = pthread_create(&threads[t], NULL, dfsSolve, args);
		if (rc) {
			free(args);
			fprintf(stderr, "%s\n", "Thread creation failed");
			exit(-1);
		}
	}

	for (t=0; t<NUM_THREADS; t++) {
		pthread_join(threads[t], NULL);
		free(args);
	}
}

