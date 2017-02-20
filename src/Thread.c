#include "Thread.h"

LetterNotation convertIntToRotation(int x) {
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

void create_threads(int*** state, int max_depth) {
	Degrees degree = Ninety;
	pthread_t threads[NUM_THREADS];

	int copy_of_state[6][3][3];
	size_t destination_size = sizeof (copy_of_state);

	printf("%d\n", copy_of_state[5][2][2]);
	strncpy(copy_of_state, state, destination_size);

	int rc;
	long t;

	for (t=0; t<NUM_THREADS; t++) {
		thread_struct *args = malloc(sizeof *args);
		args->rotation = convertIntToRotation(t);
		args->degrees = degree;
		args->state = copy_of_state;
		args->max_depth = max_depth;
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
