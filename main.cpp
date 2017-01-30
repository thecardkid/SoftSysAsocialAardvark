#include <iostream>
#include "src/CubeFace.h"
#include "src/RubiksCube.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

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

int main(int argc, char* argv[]) {
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	return 0;
}

