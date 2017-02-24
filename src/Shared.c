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

