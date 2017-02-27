#include <stdio.h>
#include <stdlib.h>
#include "Connector.h"
#include "Logic.h"
#include "Enums.h"

int solve() {
    int*** to_rotate = get_default_state();
    rubiks_cube_rotate(to_rotate, L, Ninety);
    int*** state = get_default_state();

    // Proof of concept: "state" and "rotated" are different.
    // Will write tests ASAP.
    int i, j, k, state_val, rotated_val;
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                state_val = state[i][j][k];
                rotated_val = to_rotate[i][j][k];

                if (state_val != rotated_val) {
                    printf("State differs from rotated at (%i, %i, %i)\n", i, j, k);
                }
            }
        }
    }
    printf("\n");
    return 0;
}
