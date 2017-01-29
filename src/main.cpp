#include <iostream>
#include "CubeFace.h"
#include "RubiksCube.h"

void printFace(int** face_) {
	std::string out = "[\n";

	for (int i=0; i < 3; i++) {
		out += "[";
		for (int j=0; j < 2; j++) {
			out += std::to_string(face_[i][j]) + ",";
		}
		out += std::to_string(face_[i][2]) + "]\n";
	}

	out.append("]");

	std::cout << out << std::endl;
}

int main() {
    CubeFace *face = new CubeFace(CubeFace::White);
	face->setRow(1, new int[3] {CubeFace::Blue, CubeFace::Blue, CubeFace::Blue});
    face->setRow(2, new int[3] {CubeFace::Yellow, CubeFace::Yellow, CubeFace::Yellow});

	printFace(face->getFace());
	face->rotateFaceClockwise(90);
	printFace(face->getFace());

	int** f = face->getFace();
	f[0][0] = 6;
	printFace(face->getFace());
//	RubiksCube *cube = new RubiksCube();
//	int*** state = cube->getState();
//
//	printFace(state[0]);
}

