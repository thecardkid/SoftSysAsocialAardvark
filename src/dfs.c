#include <stdio.h>
#include <stdlib.h>

#include "dfs.h"

/*
Recursive solution.
*/

/**
 * @param args is the struct passed in by the calling function in Thread.c (check what it contains by looking in Enums.h). The args input is cast to a thread_struct type so we can access its attributes. This struct needs to be freed before the function returns
 * @return array of length 20 contain the moves to solve cube
 */
char* dfsSolve(void* args) {
	thread_struct *actual_args = args;
	char moves[20]; // will store list of moves

	free(actual_args);
	return 'a';
	// return dfsSolveHelper(state, solution, moves, depth, 0);
}

char* dfsSolveHelper(int*** state, int*** solution, char* moves, int depth, int n) {
	/* Recursively checks whether you can get from the current state to the solved state
	in N turns. Returns a char array of length 20 containing "None" if this is impossible.
	Returns a char array of length 20 containing the moves (in char format) to solve the cube.*/

	if (depth > n) {
		// Base case, don't look deeper
		return "None";
	}
	if (equalStates(state, solution)) {
		// If cube is solved
		return moves;
	}

	int i;
	for (i = 0; i < 9; i++) {
		/* Loop through the movements and try each one. This
		   would be a lot nicer with enums?
		   Also keep track of the reverse movement for recursive
		   backtracking. */

		char movement;
		char reverse_movement;

		switch (i) {
			case 0:
				movement = 'U';
				// will need change the name of these to something more logical
				reverse_movement = 'I';
				break;
			case 1:
				movement = 'F';
				reverse_movement = 'K';
				break;
			case 2:
				movement = 'D';
				reverse_movement = 'J';
				break;
			/// fill in rest....
		}

		rotate(state, movement);

		moves[n] = movement;
		moves = dfsSolveHelper(state, solution, moves, depth + 1, n);

		// If we find a solution, we're done.
		if (moves != "None") return moves;

		// Turn the cube back. Recursive backtracking.
		rotate(state, reverse_movement);
	}
	return "None";
}

int equalStates(int*** state, int*** solution) {
	/* If state 3D-matrices differ at any value, return false.
	I'm not entirely sure this is the right way to compare pointer
	matrices in C. */
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

void rotate(int*** state, char movement) {
	// TO DO:
	// Implement rotations. I think we've already done this in C++
	// and can easily translate?
}
