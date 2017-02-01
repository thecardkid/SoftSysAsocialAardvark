#ifndef SOFTSYS_ASOCIAL_AARDVARK_CUBEFACE_H
#define SOFTSYS_ASOCIAL_AARDVARK_CUBEFACE_H

#include <string>

class CubeFace {
private:
    int n_;
    int** face_;
    void transposeFace();
    void reverseRows();
    void reverseCols();
    void rotate90Clockwise();
    void rotate180();
    void rotate90Anticlockwise();
    bool isValidIndex(int i);

public:
    enum Color {Red, Blue, Orange, White, Yellow, Green};
    enum Degrees {Ninety, OneEighty, TwoSeventy, LastDegree};
    explicit CubeFace(CubeFace::Color color);
    int** getFace();
    void rotateFaceClockwise(Degrees d);
    void setRow(int whichRow, int* row);
    int* getRow(int whichRow);
    void setCol(int whichCol, int* col);
    int* getCol(int whichCol);
};

#endif
