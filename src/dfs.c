#include <stdio.h>
#include <stdlib.h>

#include "dfs.h"
#include "Connector.h"

int*** solution;

/**
 * @param args is the struct passed in by the calling function in Thread.c (check what it contains by looking in Enums.h). The args input is cast to a thread_struct type so we can access its attributes. This struct needs to be freed before the function returns
 * @return array of length 20 contain the moves to solve cube
 */
void* dfsSolve(void* args) {
	thread_struct *actual_args = args;
	solution = get_default_state();

	char* moves[actual_args->max_depth];

	int state[6][3][3];
	memcpy(state, actual_args->state, sizeof(actual_args->state));
	// state = rubiks_cube_rotate(actual_args->state, actual_args->rotation, actual_args->degrees);
	moves[0] = convert_rotation_to_char(actual_args->rotation);


	// dfsSolveHelper(state, moves, 1, actual_args->max_depth, actual_args->rotation); 

	free(actual_args);
}

/* Recursively checks whether you can get from the current state to the solved state
in N turns. Returns a char array of length 20 containing "None" if this is impossible.
Returns a char array of length 20 containing the moves (in char format) to solve the cube.*/

void dfsSolveHelper(int*** state, char* moves, int depth, int max_depth, int id) {

	if (isSolved(state)) {
		printf("Solved %s!\n", moves);
		return;
	}

	if (depth == max_depth) {
		return;
	}

	int i;
	LetterNotation movement;
	char movement_c;
	for (i = 0; i < 9; i++) {
		movement = convert_int_to_rotation(i);
		movement_c = convert_rotation_to_char(movement);

		state = rubiks_cube_rotate(state, movement, Ninety);

		moves[depth] = movement_c;
		dfsSolveHelper(state, moves, depth + 1, max_depth, id);

		// Turn the cube back. Recursive backtracking.
		moves[depth] = '-';
		state = rubiks_cube_rotate(state, movement, TwoSeventy);
	}
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

void printState(int state[6][3][3]) {
	printf("Printing state... \n");
	int i, j, k;
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 3; j++) {
			for (k = 0; k < 3; k++) {
				printf("%d,", state[i][j][k]);
			}
			printf("\n");;
		}
		printf("\n\n");
	}
	printf("\n\n\n");
}
