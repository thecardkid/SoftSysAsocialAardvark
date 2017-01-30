#include <vector>
#include <cstdlib>
#include "RubiksCube.h"

// Faces as they appear at http://www.rubiksplace.com/move-notations/
RubiksCube::RubiksCube(): n_(3),
	xLeft_(CubeFace::Green),
	xRight_(CubeFace::Blue),
	yTop_(CubeFace::White),
	yBottom_(CubeFace::Yellow),
	zFront_(CubeFace::Red),
	zBack_(CubeFace::Orange)
{}

int*** RubiksCube::getState() {
	int*** state = new int**[6];
	state[0] = xLeft_.getFace();
	state[1] = xRight_.getFace();
	state[2] = yTop_.getFace();
	state[3] = yBottom_.getFace();
	state[4] = zFront_.getFace();
	state[5] = zBack_.getFace();

	return state;
}

void RubiksCube::rotateXLeft(CubeFace::Degrees degrees) {
	xLeft_.rotateFaceClockwise(degrees);

	int *tempCol;
	for (int i=0; i < degrees+1; i++) {
		tempCol = yTop_.getCol(0);
		yTop_.setCol(0, zBack_.getCol(0));
		zBack_.setCol(0, yBottom_.getCol(0));
		yBottom_.setCol(0, zFront_.getCol(0));
		zFront_.setCol(0, tempCol);
	}
}

void RubiksCube::rotateXRight(CubeFace::Degrees degrees) {
	xRight_.rotateFaceClockwise(degrees);

	int *tempCol;
	for (int i=0; i < degrees+1; i++) {
		tempCol = yTop_.getCol(2);
		yTop_.setCol(2, zFront_.getCol(2));
		zFront_.setCol(2, yBottom_.getCol(2));
		yBottom_.setCol(2, zBack_.getCol(2));
		zBack_.setCol(2, tempCol);
	}
}

void RubiksCube::rotateYTop(CubeFace::Degrees degrees) {
	yTop_.rotateFaceClockwise(degrees);

	int *tempRow;
    for (int i=0; i < degrees+1; i++) {
		tempRow = xLeft_.getRow(0);
		xLeft_.setRow(0, zFront_.getRow(0));
		zFront_.setRow(0, xRight_.getRow(0));
		xRight_.setRow(0, zBack_.getRow(0));
		zBack_.setRow(0, tempRow);
	}
}

void RubiksCube::rotateYBottom(CubeFace::Degrees degrees) {
	yBottom_.rotateFaceClockwise(degrees);

	int *tempRow;
	for (int i=0; i < degrees+1; i++) {
		tempRow = xLeft_.getRow(2);
		xLeft_.setRow(2, zBack_.getRow(2));
		zBack_.setRow(2, xRight_.getRow(2));
		xRight_.setRow(2, zFront_.getRow(2));
		zFront_.setRow(2, tempRow);
	}
}

void RubiksCube::rotateZFront(CubeFace::Degrees degrees) {
	zFront_.rotateFaceClockwise(degrees);

	int *yTopLastRow;
	for (int i=0; i < degrees+1; i++) {
		yTopLastRow = yTop_.getRow(2);
		yTop_.setRow(2, xLeft_.getCol(2));
		xLeft_.setCol(2, yBottom_.getRow(0));
		yBottom_.setRow(0, xRight_.getCol(0));
		xRight_.setCol(0, yTopLastRow);
	}
}

void RubiksCube::rotateZBack(CubeFace::Degrees degrees) {
	zBack_.rotateFaceClockwise(degrees);

    int *yTopFirstRow;
	for (int i=0; i < degrees+1; i++) {
		yTopFirstRow = yTop_.getRow(0);
		yTop_.setRow(0, xRight_.getCol(2));
		xRight_.setCol(2, yBottom_.getRow(2));
		yBottom_.setRow(2, xLeft_.getCol(0));
		xLeft_.setCol(0, yTopFirstRow);
	}
}

void RubiksCube::rotateXSlice(CubeFace::Degrees degrees) {
	int* tempCol;
	for (int i=0; i < degrees+1; i++) {
		tempCol = yTop_.getCol(1);
		yTop_.setCol(1, zBack_.getCol(1));
        zBack_.setCol(1, yBottom_.getCol(1));
		yBottom_.setCol(1, zFront_.getCol(1));
		zFront_.setCol(1, tempCol);
	}
}

void RubiksCube::rotateYSlice(CubeFace::Degrees degrees) {
	int* tempRow;
	for (int i=0; i < degrees+1; i++) {
		tempRow = zFront_.getRow(1);
		zFront_.setRow(1, xLeft_.getRow(1));
		xLeft_.setRow(1, zBack_.getRow(1));
		zBack_.setRow(1, xRight_.getRow(1));
		xRight_.setRow(1, tempRow);
	}
}

void RubiksCube::rotateZSlice(CubeFace::Degrees degrees) {
	int* temp;
	for (int i=0; i < degrees+1; i++) {
		temp = yTop_.getRow(1);
		yTop_.setRow(1, xLeft_.getCol(1));
		xLeft_.setCol(1, yBottom_.getRow(1));
		yBottom_.setRow(1, xRight_.getCol(1));
		xRight_.setCol(1, temp);
	}
}

std::vector<RubiksCube::Move> RubiksCube::scramble(int n) {
    std::vector<RubiksCube::Move> moves;

	for (int i=0; i < n; i++) {
		Move m;
		m.slice = static_cast<RubiksCube::LetterNotation>(rand() % RubiksCube::LastRotation);
		m.degrees = static_cast<CubeFace::Degrees>(rand() % CubeFace::LastDegree);
		moves.push_back(m);
		rotate(m.slice, m.degrees);
	}

    return moves;
}

void RubiksCube::rotate(LetterNotation action, CubeFace::Degrees degrees) {
	switch (action) {
		case U: return rotateYTop(degrees);
		case L: return rotateXLeft(degrees);
		case F: return rotateZFront(degrees);
		case R: return rotateXRight(degrees);
		case B: return rotateZBack(degrees);
		case D: return rotateYBottom(degrees);
		case M: return rotateXSlice(degrees);
		case E: return rotateYSlice(degrees);
		case S: return rotateZSlice(degrees);
	}
}
