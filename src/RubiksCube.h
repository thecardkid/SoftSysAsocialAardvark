#ifndef SOFTSYS_ASOCIAL_AARDVARK_RUBIKSCUBE_H
#define SOFTSYS_ASOCIAL_AARDVARK_RUBIKSCUBE_H

#include <vector>
#include "CubeFace.h"

// 3x3 cube
class RubiksCube {
private:
	int n_;
	CubeFace xLeft_, xRight_, yTop_, yBottom_, zFront_, zBack_;
	void rotateXLeft(CubeFace::Degrees degrees);
	void rotateXRight(CubeFace::Degrees degrees);
    void rotateYTop(CubeFace::Degrees degrees);
	void rotateYBottom(CubeFace::Degrees degrees);
	void rotateZFront(CubeFace::Degrees degrees);
	void rotateZBack(CubeFace::Degrees degrees);
    void rotateXSlice(CubeFace::Degrees degrees);
	void rotateYSlice(CubeFace::Degrees degrees);
	void rotateZSlice(CubeFace::Degrees degrees);

public:
	enum LetterNotation {
		// https://ruwix.com/the-rubiks-cube/notation/
		U, L, F, R, B, D, M, E, S, LastRotation
	};
	struct Move {
		RubiksCube::LetterNotation slice;
		CubeFace::Degrees degrees;
	};
	RubiksCube();
	std::vector<Move> scramble(int n);
	void rotate(LetterNotation action, CubeFace::Degrees degrees);
	int*** getState();
};


#endif
