#ifndef SOFTSYS_ASOCIAL_AARDVARK_CUBEFACE_H
#define SOFTSYS_ASOCIAL_AARDVARK_CUBEFACE_H

class CubeFace {
private:
    int n_;
    int** face_;

public:
    enum Color {Red, Blue, Orange, White, Yellow, Green};
    CubeFace(CubeFace::Color color);
    int** getFace();
    void rotateFace(int degrees);
    void setRow(int whichRow, int* row);
		std::string toString();
};


#endif //SOFTSYS_ASOCIAL_AARDVARK_CUBEFACE_H
