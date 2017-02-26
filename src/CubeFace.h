#ifndef SOFTSYS_ASOCIAL_AARDVARK_CUBEFACE_H
#define SOFTSYS_ASOCIAL_AARDVARK_CUBEFACE_H

#include <string>
#include "Enums.h"

class CubeFace {
private:
    /**
     * The edge length of the Rubik's cube (standard is 3).
     */
    int n_;

    /**
     * The underlying face representation.
     * Holds integers from the Color enum.
     */
    int** face_;

    /**
     * These three methods are used in tandem to rotate
     * the face correctly.
     *
     * Rotate 90: transposeFace() + reverseRows();
     * Rotate 270: transposeFace() + reverseCols();
     */
    void transposeFace();
    void reverseRows();
    void reverseCols();

    /**
     * Factory methods called by the switch statement
     * in the public method rotateFaceClockwise().
     */
    void rotate90();
    void rotate180();
    void rotate270();

    /**
     * Helper method to check passed in index argument
     * for row/col getters and setters is valid.
     * @param i
     * @return true if i is valid
     */
    bool isValidIndex(int i);

public:
    explicit CubeFace(Color color);
    explicit CubeFace(int** state);

    /**
     * @return A copy of the cube face as a 3x3 array.
     */
    int** getFace();

    /**
     * Rotates a face clockwise by the specified number of degrees.
     */
    void rotateFaceClockwise(Degrees d);

    /**
     * Row/column setters and getters.
     */
    void setRow(int whichRow, int* row);
    int* getRow(int whichRow);
    void setCol(int whichCol, int* col);
    int* getCol(int whichCol);
};

#endif
