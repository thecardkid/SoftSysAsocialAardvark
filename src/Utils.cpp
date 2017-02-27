#include "CubeFace.h"

int* getArrayOfColor(Color color) {
    return new int[3] {color, color, color};
}

bool rowsEqual(int* row1, int* row2) {
    for (int i = 0; i < 3; i++) {
        if (row1[i] != row2[i]) return false;
    }

    return true;
}

// Wraps rowsEqual for semantics / readability.
bool colsEqual(int* col1, int* col2) {
    return rowsEqual(col1, col2);
}

bool facesEqual(int** face1, int** face2) {
    for (int r = 0; r < 3; r++) {
        if (!rowsEqual(face1[r], face2[r])) return false;
    }

    return true;
}

bool allFacesEqual(CubeFace* expectedXLeft, CubeFace* expectedXRight,
                   CubeFace* expectedYTop, CubeFace* expectedYBottom,
                   CubeFace* expectedZFront, CubeFace* expectedZBack,
                   int*** actualState) {
    return facesEqual(expectedXLeft->getFace(), actualState[0]) &&
           facesEqual(expectedXRight->getFace(), actualState[1]) &&
           facesEqual(expectedYTop->getFace(), actualState[2]) &&
           facesEqual(expectedYBottom->getFace(), actualState[3]) &&
           facesEqual(expectedZFront->getFace(), actualState[4]) &&
           facesEqual(expectedZBack->getFace(), actualState[5]);
}
