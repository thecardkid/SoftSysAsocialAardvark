#ifndef SOFTSYS_ASOCIAL_AARDVARK_CUBEFACE_H
#define SOFTSYS_ASOCIAL_AARDVARK_CUBEFACE_H

#include <string>
#include "Shared.h"

class CubeFace {
private:
    int n_;
    int** face_;

    /**
     * These three methods are used in tandem to rotate
     * the face correctly.
     *
     * Rotate 90: transposeFace() + reverseRows();
     * Rotate -90: transposeFace() + reverseCols();
     */
    void transposeFace();
    void reverseRows();
    void reverseCols();

    /**
     * Factory methods called by the switch statement
     * in the public method rotateFaceClockwsie().
     */
    void rotate90Clockwise();
    void rotate180();
    void rotate90Anticlockwise();

    /**
     * Helper method to check passed in index argument
     * for row/col getters and setters is valid.
     * @param i
     * @return
     */
    bool isValidIndex(int i);

public:
    explicit CubeFace(Color color);
    explicit CubeFace(int** state);

    /**
     * @return A copy of the cube face as a 3x3 array.
     */
    int** getFace();

    void rotateFaceClockwise(Degrees d);

    void setRow(int whichRow, int* row);
    int* getRow(int whichRow);
    void setCol(int whichCol, int* col);
    int* getCol(int whichCol);
};

#endif
