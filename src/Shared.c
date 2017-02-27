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

void print_moves(LetterNotation* moves, int s) {
	int i;
	for (i=0; i<s; i++) printf("%d,", moves[i]);
	printf("\n");
}

