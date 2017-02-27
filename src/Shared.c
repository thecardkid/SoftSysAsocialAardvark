#include "Shared.h"

LetterNotation convert_int_to_rotation(int x) {
    switch (x) {
        case 0: return U;
        case 1: return L;
        case 2: return F;
        case 3: return R;
        case 4: return B;
        case 5: return D;
        case 6: return M;
        case 7: return E;
        case 8: return S;
        default: return LastRotation;
    }
}

void copyState(int copyOfState[6][3][3], int*** state) {
    int i,j,k;
    for (i=0; i<6; i++) {
        for (j=0; j<3; j++) {
            for (k=0; k<3; k++) {
                copyOfState[i][j][k] = state[i][j][k];
            }
        }
    }
}

void print_moves(LetterNotation* moves, int s) {
	int i;
	for (i=0; i<s; i++) printf("%d,", moves[i]);
	printf("\n");
}

void printFace(int** face_) {
    printf("[\n");

    int i,j;
    for (i=0; i<3; i++) {
        printf("[");
        for (j=0; j<2; j++) {
            printf("%i,", face_[i][j]);
        }
        printf("%i]\n", face_[i][2]);
    }

    printf("]\n");
}
