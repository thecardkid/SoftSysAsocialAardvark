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
		case 's':
			std::cout << moves.size() << std::endl;
			break;
		case 'u':
			std::cout << "C++ " << moves.at(0).slice << std::endl;
			solve();
			break;
		default:
			break;
	}
}

void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_F1:
            cube->rotate(RubiksCube::L, CubeFace::Ninety);
            break;
        case GLUT_KEY_F2:
            cube->rotate(RubiksCube::R, CubeFace::Ninety);
            break;
        case GLUT_KEY_F3:
            cube->rotate(RubiksCube::U, CubeFace::Ninety);
            break;
        case GLUT_KEY_F4:
            cube->rotate(RubiksCube::D, CubeFace::Ninety);
            break;
        case GLUT_KEY_F5:
            cube->rotate(RubiksCube::F, CubeFace::Ninety);
            break;
        case GLUT_KEY_F6:
            cube->rotate(RubiksCube::B, CubeFace::Ninety);
            break;
        case GLUT_KEY_F7:
            cube->rotate(RubiksCube::M, CubeFace::Ninety);
            break;
        case GLUT_KEY_F8:
            cube->rotate(RubiksCube::E, CubeFace::Ninety);
            break;
        case GLUT_KEY_F9:
            cube->rotate(RubiksCube::S, CubeFace::Ninety);
            break;
    }

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

