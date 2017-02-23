int* getArrayOfColor(Color color);
bool cubesEqual(int*** expected, int*** actual);
bool allFacesEqual(CubeFace* expectedXLeft, CubeFace* expectedXRight, CubeFace* expectedYTop,
    CubeFace* expectedYBottom, CubeFace* expectedZFront, CubeFace* expectedZBack, int*** actualCube);
bool facesEqual(int** expected, int** actual);
bool rowsEqual(int* expected, int* actual);
bool colsEqual(int* expected, int* actual);
