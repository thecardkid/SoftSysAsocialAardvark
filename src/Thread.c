#include "Thread.h"
#include "Shared.h"

LetterNotation* create_threads(int state[6][3][3], int max_depth) {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    thread_struct *args;
    thread_return_struct *return_struct;
    clock_t begin, end;

    for (t=0; t<NUM_THREADS; t++) {
        thread_struct *args = malloc(sizeof *args);
        args->rotation = convert_int_to_rotation(t);
        args->degrees = Ninety;
        memcpy(args->state, state, 6*3*3*sizeof(int));
        args->max_depth = max_depth;
        printf("Starting thread #%d\n", t);

        begin = clock();
        rc = pthread_create(&threads[t], NULL, dfs_solve, args);
        if (rc) {
            free(args);
            fprintf(stderr, "Failed to create thread #%d\n", t);
            exit(-1);
        }
        end = clock();
        double time_spent = ((double)(end - begin)) / CLOCKS_PER_SEC;
        printf("Thread #%d completed in %.6f seconds\n", t, time_spent);
    }

    LetterNotation* moves;
    for (t=0; t<NUM_THREADS; t++) {
        pthread_join(threads[t], &return_struct);
        printf("Thread %d worked %d\n", t, return_struct->status);
        print_moves(return_struct->solveMoves, max_depth);

        if (return_struct->status == 1) {
            moves = return_struct->solveMoves;
        }
    }

    return moves;
}
