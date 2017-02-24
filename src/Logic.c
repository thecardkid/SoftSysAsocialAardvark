#include <stdio.h>
#include <stdlib.h>
#include "Connector.h"
#include "Logic.h"
#include "Shared.h"

int solve() {
    int*** rotated = rubiks_cube_rotate(get_default_state(), L, Ninety);
    int*** state = get_default_state();

    // Proof of concept: "state" and "rotated" are different.
    // Will write tests ASAP.
    int i, j, k, state_val, rotated_val;
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                state_val = state[i][j][k];
                rotated_val = rotated[i][j][k];
            }
        }
    }
    printf("\n");
    return 0;
}
