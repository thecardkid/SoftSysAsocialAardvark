/**
 * Create a 3-element array of integers representing the specified color.
 *
 * @param color: enum integer representing color
 * @return array of color integers
 */
int* getArrayOfColor(Color color);

/**
 * Compare two rows.
 *
 * @param row1, row2: the two rows
 * @return true if the rows are equivalent (contain the same colors)
 */
bool rowsEqual(int* row1, int* row2);

/**
 * Compare two columns.
 *
 * @param col1, col2: the two columns
 * @return true if the columns are equivalent (contain the same colors)
 */
bool colsEqual(int* col1, int* col2);

/**
 * Compare two faces.
 *
 * @param face1, face2: the two faces
 * @return true if the faces are equivalent (contain the same colors)
 */
bool facesEqual(int** face1, int** face2);

/**
 * Compare six faces to a state.
 *
 * @param expected...: the six faces
 * @param actualState: the state
 * @return true if the six faces represent the state
 */
bool allFacesEqual(CubeFace* expectedXLeft, CubeFace* expectedXRight,
                   CubeFace* expectedYTop, CubeFace* expectedYBottom,
                   CubeFace* expectedZFront, CubeFace* expectedZBack,
                   int*** actualState);
