#include <vector>
#include "RubiksCube.h"

RubiksCube::RubiksCube(): n_(3),
	yTop_(CubeFace::White),
	yBottom_(CubeFace::Yellow),
	xLeft_(CubeFace::Green),
	xRight_(CubeFace::Blue),
	zFront_(CubeFace::Red),
	zBack_(CubeFace::Orange)
{}

int*** RubiksCube::getState() {
	int*** state = new int**[6];

	state[0] = yTop_.getFace();
	state[1] = yBottom_.getFace();
	state[2] = xLeft_.getFace();
	state[3] = xRight_.getFace();
	state[4] = zFront_.getFace();
	state[5] = zBack_.getFace();

	return state;
}
