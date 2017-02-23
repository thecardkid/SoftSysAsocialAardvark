#include "CubeFace.h"

const int N = 3;

int* getArrayOfColor(Color color) {
    return new int[N] {color, color, color};
}

bool rowsEqual(int* expected, int* actual) {
    for (int i = 0; i < N; i++) {
        if (expected[i] != actual[i]) return false;
    }

    return true;
}

bool colsEqual(int* expected, int* actual) {
    return rowsEqual(expected, actual);
}

bool facesEqual(int** expected, int** actual) {
    for (int r = 0; r < N; r++) {
        if (!rowsEqual(expected[r], actual[r])) return false;
    }

    return true;
}

bool allFacesEqual(CubeFace* expectedXLeft, CubeFace* expectedXRight, CubeFace* expectedYTop,
    CubeFace* expectedYBottom, CubeFace* expectedZFront, CubeFace* expectedZBack, int*** actualCube) {
    return facesEqual(expectedXLeft->getFace(), actualCube[0]) &&
           facesEqual(expectedXRight->getFace(), actualCube[1]) &&
           facesEqual(expectedYTop->getFace(), actualCube[2]) &&
           facesEqual(expectedYBottom->getFace(), actualCube[3]) &&
           facesEqual(expectedZFront->getFace(), actualCube[4]) &&
           facesEqual(expectedZBack->getFace(), actualCube[5]);
}

bool cubesEqual(int*** expected, int*** actual) {
    for (int f=0; f < 6; f++) {
        if (!facesEqual(expected[f], actual[f])) return false;
    }

    return true;
}
