#include "Thread.h"
#include "Shared.h"

LetterNotation* create_threads(int state[6][3][3], int max_depth) {
    pthread_t threads[NUM_THREADS];
    clock_t begin[NUM_THREADS];
    clock_t end[NUM_THREADS];
    int rc;
    long t;
    thread_struct *args;
    void *received_return_struct;
    thread_return_struct *return_struct;

    for (t=0; t<NUM_THREADS; t++) {
        thread_struct *args = malloc(sizeof *args);
        args->rotation = convert_int_to_rotation(t);
        args->degrees = Ninety;
        memcpy(args->state, state, 6*3*3*sizeof(int));
        args->max_depth = max_depth;
        printf("Starting thread #%ld\n", t);

        begin[t] = clock();
        rc = pthread_create(&threads[t], NULL, dfs_solve, args);
        if (rc) {
            free(args);
            fprintf(stderr, "Failed to create thread #%ld\n", t);
            exit(-1);
        }
    }

    LetterNotation* moves;
    for (t=0; t<NUM_THREADS; t++) {
        pthread_join(threads[t], &received_return_struct);
        end[t] = clock();
        return_struct = received_return_struct;

        double time_spent = ((double)(end[t] - begin[t])) / CLOCKS_PER_SEC;
        printf("Thread #%ld completed in %.6f seconds\n", t, time_spent);

        if (return_struct->status == 1) {
            printf("Thread #%ld found a solution\n", t);
            print_moves(return_struct->solveMoves, max_depth);
            moves = return_struct->solveMoves;
        }
    }

    return moves;
}
