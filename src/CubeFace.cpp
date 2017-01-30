#include "CubeFace.h"
#include <iostream>

CubeFace::CubeFace(CubeFace::Color color): n_(3) {
	face_ = new int*[n_];

	for (int i=0; i < n_; i++) {
        face_[i] = new int[n_];
        std::fill_n(face_[i], n_, color);
	}
}

void CubeFace::transposeFace() {
	int temp;
    for (int r=0; r <= n_-2; r++) {
        for (int c=r+1; c <= n_-1; c++) {
            temp = face_[r][c];
            face_[r][c] = face_[c][r];
            face_[c][r] = temp;
        }
    }
}

void CubeFace::reverseRows() {
	int temp;
	for (int r=0; r < n_; r++) {
		for (int c=0; c < n_/2; c++) {
			temp = face_[r][c];
			face_[r][c] = face_[r][n_-1-c];
			face_[r][n_-1-c] = temp;
		}
	}
}

void CubeFace::reverseCols() {
	int temp;
	for (int c=0; c < n_; c++) {
		for (int r=0; r < n_/2; r++) {
			temp = face_[r][c];
			face_[r][c] = face_[n_-1-r][c];
			face_[n_-1-r][c] = temp;
		}
	}
}

void CubeFace::rotate90Clockwise() {
	transposeFace();
	reverseRows();
}

void CubeFace::rotate180() {
	rotate90Clockwise();
	rotate90Clockwise();
}

void CubeFace::rotate90Anticlockwise() {
	transposeFace();
	reverseCols();
}

int** CubeFace::getFace() {
    int** copyOfFace = new int*[n_];
	for (int r=0; r < n_; r++) {
        copyOfFace[r] = new int[n_];
        for (int c=0; c < n_; c++)
			copyOfFace[r][c] = face_[r][c];
	}

	return copyOfFace;
}

void CubeFace::rotateFaceClockwise(Degrees d) {
    switch (d) {
        case Ninety: return rotate90Clockwise();
        case OneEighty: return rotate180();
        case TwoSeventy: return rotate90Anticlockwise();
    }
}

void CubeFace::setRow(int whichRow, int* row) {
	if (whichRow < n_ && whichRow >= 0)
		face_[whichRow] = row;
}

int* CubeFace::getRow(int whichRow) {
    if (whichRow < n_ && whichRow >= 0) {
		int *copyOfRow = new int[n_];
		for (int i=0; i < n_; i++) copyOfRow[i] = face_[whichRow][i];
		return copyOfRow;
	}

	return NULL;
}
