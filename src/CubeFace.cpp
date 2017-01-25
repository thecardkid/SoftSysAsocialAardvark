#include <iostream>
#include "CubeFace.h"

CubeFace::CubeFace(CubeFace::Color color): n_(3) {
    face_ = new int*[n_];

    for (int i=0; i<n_; i++) {
        face_[i] = new int[n_];
        std::fill_n(face_[i], n_, color);
    }
}

int** CubeFace::getFace() {
    return face_;
}

void CubeFace::rotateFace(int degrees) {

}

void CubeFace::setRow(int whichRow, int* row) {

}

std::string CubeFace::toString() {
	return NULL;
}
