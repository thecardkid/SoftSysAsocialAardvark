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
    }
}

char convert_rotation_to_char(LetterNotation n) {
	switch (n) {
		case U: return 'U';
		case L: return 'L';
		case F: return 'F';
		case R: return 'R';
		case B: return 'B';
		case D: return 'D';
		case M: return 'M';
		case E: return 'E';
		case S: return 'S';
	}
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

void printPointers(int*** state) {
	printf("Printing state pointers.. \n");
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
