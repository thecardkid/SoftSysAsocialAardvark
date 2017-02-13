extern "C" {
    #include "Logic.h"
}

#include <GL/glut.h>
#include <gtest/gtest.h>
#include <iostream>

#include "CubeFace.h"
#include "Graphics.h"
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

RubiksCube* cube = new RubiksCube();
std::vector<RubiksCube::Move> moves;

void displayWrapper() {
    int*** colors = cube->getState();
    display(colors);
}

void myKeyboardFunc(unsigned char key, int x, int y) {
	switch (key) {
		case 'x':
			std::cout << "C++ " << moves.at(0).slice << std::endl;
			solve();
			break;
		case 'l':
			cube->rotate(RubiksCube::L, CubeFace::Ninety);
			break;
		case 'L':
			cube->rotate(RubiksCube::L, CubeFace::TwoSeventy);
			break;
		case 'r':
			cube->rotate(RubiksCube::R, CubeFace::Ninety);
			break;
		case 'R':
			cube->rotate(RubiksCube::R, CubeFace::TwoSeventy);
			break;
		case 'u':
			cube->rotate(RubiksCube::U, CubeFace::Ninety);
			break;
		case 'U':
			cube->rotate(RubiksCube::U, CubeFace::TwoSeventy);
			break;
		case 'd':
			cube->rotate(RubiksCube::D, CubeFace::Ninety);
			break;
		case 'D':
			cube->rotate(RubiksCube::D, CubeFace::TwoSeventy);
			break;
		case 'f':
			cube->rotate(RubiksCube::F, CubeFace::Ninety);
			break;
		case 'F':
			cube->rotate(RubiksCube::F, CubeFace::TwoSeventy);
			break;
		case 'b':
			cube->rotate(RubiksCube::B, CubeFace::Ninety);
			break;
		case 'B':
			cube->rotate(RubiksCube::B, CubeFace::Ninety);
			break;
		case 'm':
			cube->rotate(RubiksCube::M, CubeFace::Ninety);
			break;
		case 'M':
			cube->rotate(RubiksCube::M, CubeFace::TwoSeventy);
			break;
		case 'e':
			cube->rotate(RubiksCube::E, CubeFace::Ninety);
			break;
		case 'E':
			cube->rotate(RubiksCube::E, CubeFace::TwoSeventy);
			break;
		case 's':
			cube->rotate(RubiksCube::S, CubeFace::Ninety);
			break;
		case 'S':
			cube->rotate(RubiksCube::S, CubeFace::TwoSeventy);
			break;
		default:
			break;
	}

	glutPostRedisplay();
}

void specialKeys(int key, int x, int y) {
    graphicsSpecialKeys(key, x, y);
}

int main(int argc, char **argv) {
    // TEST
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();

    // GRAPHICS
    initializeCubes();
	moves = cube->scramble(20);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Rubik's Cube");
    glutDisplayFunc(displayWrapper);
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(myKeyboardFunc);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();

    // LOGIC
	displayWrapper();

    return 0;
}

