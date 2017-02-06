#ifndef SOFTSYS_ASOCIAL_AARDVARK_RUBIKSCUBE_H
#define SOFTSYS_ASOCIAL_AARDVARK_RUBIKSCUBE_H

#include <vector>
#include "CubeFace.h"

class RubiksCube {
private:
	int n_;
	CubeFace xLeft_, xRight_, yTop_, yBottom_, zFront_, zBack_;
	void rotateXLeft();
	void rotateXRight();
  void rotateYTop();
	void rotateYBottom();
	void rotateZFront();
	void rotateZBack();
  void rotateXSlice();
	void rotateYSlice();
	void rotateZSlice();
  int* reverse(int* a);

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
