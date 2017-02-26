#include <stdio.h>
#include <stdlib.h>

#include "dfs.h"
#include "Connector.h"

int*** solution;
int*** state;
int max_depth;
int** parent_pointers[6];
int* child_pointers[6][3];

/**
 * @param args is the struct passed in by the calling function in Thread.c (check what it contains by looking in Enums.h). The args input is cast to a thread_struct type so we can access its attributes. This struct needs to be freed before the function returns
 * @return array of length 20 contain the moves to solve cube
 */
void* dfsSolve(void* args) {
	thread_struct *actual_args = args;
	thread_return_struct *return_args = malloc(sizeof(thread_return_struct));
	solution = get_default_state();
	max_depth = actual_args->max_depth;
	LetterNotation moves[max_depth];

	// Converting an array to a pointer to pointer to pointer for compatibility.
	int i,j;
	for (j=0; j<3; j++) {
		for (i=0; i<6; i++) {
			child_pointers[i][j] = &actual_args->state[i][j][0];
			parent_pointers[i] = &child_pointers[i][0];
		}
	}
	state = (int***) &parent_pointers[0];

	rubiks_cube_rotate(state, actual_args->rotation, actual_args->degrees);
	moves[0] = actual_args->rotation;

	int answer = dfsSolveHelper(state, &moves[0], 1, actual_args->rotation); 
	return_args->status = answer;
	int x;
	for (x=0; x<max_depth; x++) {
		return_args->solveMoves[x] = moves[x];
	}

	free(actual_args);

	pthread_exit(return_args);
}

/* Recursively checks whether you can get from the current state to the solved state
in N turns. Returns a char array of length 20 containing "None" if this is impossible.
Returns a char array of length 20 containing the moves (in char format) to solve the cube.*/

int dfsSolveHelper(int*** state, LetterNotation* moves, int depth, int id) {
	if (isSolved(state)) {
		return 1;
	}

	if (depth == max_depth) {
		return 0;
	}

	int i;
	LetterNotation movement;
	char movement_c;
	for (i = 0; i < 9; i++) {
		movement = convert_int_to_rotation(i);
		movement_c = convert_rotation_to_char(movement);

		rubiks_cube_rotate(state, movement, Ninety);

		moves[depth] = movement;
		if (dfsSolveHelper(state, moves, depth + 1, id)) {
			return 1;
		}

		// Turn the cube back. Recursive backtracking.
		rubiks_cube_rotate(state, movement, TwoSeventy);
	}

	return 0;
}


/* If state 3D-matrices differ at any value, return false.*/
int isSolved(int*** state) {
    int i, j, k;
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                if (state[i][j][k] != solution[i][j][k]) {
                    return 0;
                }
            }
        }
    }
    return 1;
}
