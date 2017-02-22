#include <stdio.h>
#include <stdlib.h>

#include "dfs.h"
#include "Connector.h"
#include "Enums.h"

int*** solution;
// TO DO: define solution

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

	lazyRubiksCube(args.state);
	RubiksCube_rotate(args.rotation, args.degrees);

	dfsSolveHelper(moves, args.max_depth, 0);

	free(actual_args);
	return moves;
}

char* dfsSolveHelper(char* moves, int depth, int n) {
	/* Recursively checks whether you can get from the current state to the solved state
	in N turns. Returns a char array of length 20 containing "None" if this is impossible.
	Returns a char array of length 20 containing the moves (in char format) to solve the cube.*/

	int*** state = RubiksCube_getState();

	if (depth > n) {
		// Base case, don't look deeper
		return "None";
	}
	if (equalStates(state)) {
		// If cube is solved
		return moves;
	}

	int i;
	for (i = 0; i < 9; i++) {
		/* Loop through the movements and try each one. This
		   would be a lot nicer with enums?
		   Also keep track of the reverse movement for recursive
		   backtracking. */

		LetterNotation movement;
		char movement_c;

		switch (i) {
			case 0: 
				movement = U;
				movement_c = 'U';
				break;
			case 1:
				movement = L;
				movement_c = 'L';
				break;
			case 2:
				movement = F;
				movement_c = 'F';
				break;
			case 3: 
				movement = R;
				movement_c = 'R';
				break;
			case 4:
				movement = B;
				movement_c = 'B';
				break;
			case 5:
				movement = D;
				movement_c = 'D';
				break;
			case 6: 
				movement = M;
				movement_c = 'M';
				break;
			case 7:
				movement = E;
				movement_c = 'E';
				break;
			case 8:
				movement = S;
				movement_c = 'S';
				break;
		}

		RubiksCube_rotate(movement, Ninety);
		
		moves[n] = movement_c;
		moves = dfsSolveHelper(moves, depth + 1, n);

		// If we find a solution, we're done.
		if (moves != "None") return moves;

		// Turn the cube back. Recursive backtracking.
		RubiksCube_rotate(movement, TwoSeventy);
	}
	return "None";
}

int equalStates(int*** state) {
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