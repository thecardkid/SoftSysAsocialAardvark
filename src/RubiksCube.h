#ifndef SOFTSYS_ASOCIAL_AARDVARK_RUBIKSCUBE_H
#define SOFTSYS_ASOCIAL_AARDVARK_RUBIKSCUBE_H

#include <vector>
#include "CubeFace.h"

// 3x3 cube
class RubiksCube {
private:
	int n_;
	CubeFace xLeft_, xRight_, yTop_, yBottom_, zFront_, zBack_;
	enum FaceRotation {
		xLeft, xRight,
		yTop, yBottom,
		zFront, zBack
	};
	enum SliceRotation {
		xMid, yMid, zMid
	};
	void rotateFace(FaceRotation r, int times);
	void rotateSlice(SliceRotation r, int times);

public:
	enum LetterNotation {
		// https://ruwix.com/the-rubiks-cube/notation/
		U, L, F, R, B, D, M, E, S
	};
	RubiksCube();
	void scramble();
	void rotate(LetterNotation action);
	int*** getState();
};


#endif
