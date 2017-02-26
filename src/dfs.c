#include <stdio.h>
#include <stdlib.h>

#include "dfs.h"
#include "Connector.h"

int*** solution, state;
int** parent_pointers[6];
int* child_pointers[6][3];

/**
 * @param args is the struct passed in by the calling function in Thread.c (check what it contains by looking in Enums.h). The args input is cast to a thread_struct type so we can access its attributes. This struct needs to be freed before the function returns
 * @return array of length 20 contain the moves to solve cube
 */
void* dfsSolve(void* args) {
    thread_struct *actual_args = args;
    solution = get_default_state();

    char moves[actual_args->max_depth];


    state = (int***) malloc(sizeof(int) * 54);

    /*
    Converting an array to a pointer to pointer to pointer for compatibility.
    */
    int i,j;
    for (j=0; j<3; j++) {
        for (i=0; i<6; i++) {
            child_pointers[i][j] = &actual_args->state[i][j][0];
            printf("%p\n", &child_pointers[i][0]);
            parent_pointers[i] = &child_pointers[i][0];
        }
    }
    state = &parent_pointers[0];

    printPointers(state);
    rubiks_cube_rotate(state, actual_args->rotation, actual_args->degrees);
    printPointers(state);

    dfsSolveHelper(state, moves, 1, 6, actual_args->rotation);

    free(actual_args);
}

/* Recursively checks whether you can get from the current state to the solved state
in N turns. Returns a char array of length 20 containing "None" if this is impossible.
Returns a char array of length 20 containing the moves (in char format) to solve the cube.*/

void dfsSolveHelper(int*** state, char* moves, int depth, int max_depth, int id) {
    // printPointers(state);

    // if (isSolved(state)) {
    //  printf("Solved %s!\n", moves);
    //  return;
    // }

    // if (depth == max_depth) {
    //  return;
    // }

    // int i;
    // LetterNotation movement;
    // char movement_c;
    // for (i = 0; i < 9; i++) {
    //  movement = convert_int_to_rotation(i);
    //  movement_c = convert_rotation_to_char(movement);

    //  //rubiks_cube_rotate(p_state, movement, Ninety);

    //  moves[depth] = movement_c;
    //  dfsSolveHelper(state, moves, depth + 1, max_depth, id);

    //  // Turn the cube back. Recursive backtracking.
    //  moves[depth] = '-';
    //  //state = rubiks_cube_rotate(state, movement, TwoSeventy);
    // }
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
