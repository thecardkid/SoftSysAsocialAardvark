#include <stdio.h>
#include <stdlib.h>

#include "Dfs.h"
#include "Connector.h"

int*** solution;
int max_depth;

/**
 * @param received_args: a dummy type which can be cast to
 * the thread_struct defined in Shared.h.
 * This struct needs to be freed before the function returns.
 *
 * Thread exits with struct containing array of moves necessary to solve cube.
 */
void* dfs_solve(void* received_args) {
	thread_struct *args = received_args;
	thread_return_struct *return_args = malloc(sizeof(thread_return_struct));
	LetterNotation moves[max_depth];
	solution = get_default_state();
	max_depth = args->max_depth;

	// Converting an array to a pointer to pointer to pointer for compatibility.
	int i,j, status;
	int*** state;
	int** parent_pointers[6];
	int* child_pointers[6][3];
	for (j=0; j<3; j++) {
		for (i=0; i<6; i++) {
			child_pointers[i][j] = &args->state[i][j][0];
			parent_pointers[i] = &child_pointers[i][0];
		}
	}
	state = (int***) &parent_pointers[0];

	// Performing first rotation, then dfs search
	rubiks_cube_rotate(state, args->rotation, args->degrees);
	moves[0] = args->rotation;
	status = dfs_solve_helper(state, &moves[0], 1, args->rotation);

	return_args->status = status;
	memcpy(return_args->solveMoves, moves, max_depth*sizeof(int));

	free(args);
	pthread_exit(return_args);
}

/* Recursively checks whether you can get from the current state to the solved state
in N turns. Returns a char array of length 20 containing "None" if this is impossible.
Returns a char array of length 20 containing the moves (in char format) to solve the cube.*/
int dfs_solve_helper(int*** state, LetterNotation* moves, int depth, int id) {
	if (is_solved(state)) return 1;

	if (depth == max_depth) return 0;

	int i;
	LetterNotation movement;
	for (i = 0; i < 9; i++) {
		movement = convert_int_to_rotation(i);
		rubiks_cube_rotate(state, movement, Ninety);
		moves[depth] = movement;

		if (dfs_solve_helper(state, moves, depth + 1, id)) return 1;

		rubiks_cube_rotate(state, movement, TwoSeventy);
	}

	return 0;
}


/* If state 3D-matrices differ at any value, return false.*/
int is_solved(int*** state) {
    int i, j, k;
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                if (state[i][j][k] != solution[i][j][k]) return 0;
            }
        }
    }
    return 1;
}
