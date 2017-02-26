extern "C" {
    #include "Logic.h"
}

#include <GL/glut.h>
#include <gtest/gtest.h>
#include <iostream>

#include "CubeFace.h"
#include "Graphics.h"
#include "RubiksCube.h"
#include "Connector.h"
#include "Enums.h"

RubiksCube* cube = new RubiksCube();
std::vector<RubiksCube::Move> moves;
time_t lastUpdate, now;

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
			cube->rotate(L, Ninety);
			break;
		case 'L':
			cube->rotate(L, TwoSeventy);
			break;
		case 'r':
			cube->rotate(R, Ninety);
			break;
		case 'R':
			cube->rotate(R, TwoSeventy);
			break;
		case 'u':
			cube->rotate(U, Ninety);
			break;
		case 'U':
			cube->rotate(U, TwoSeventy);
			break;
		case 'd':
			cube->rotate(D, Ninety);
			break;
		case 'D':
			cube->rotate(D, TwoSeventy);
			break;
		case 'f':
			cube->rotate(F, Ninety);
			break;
		case 'F':
			cube->rotate(F, TwoSeventy);
			break;
		case 'b':
			cube->rotate(B, Ninety);
			break;
		case 'B':
			cube->rotate(B, Ninety);
			break;
		case 'm':
			cube->rotate(M, Ninety);
			break;
		case 'M':
			cube->rotate(M, TwoSeventy);
			break;
		case 'e':
			cube->rotate(E, Ninety);
			break;
		case 'E':
			cube->rotate(E, TwoSeventy);
			break;
		case 's':
			cube->rotate(S, Ninety);
			break;
		case 'S':
			cube->rotate(S, TwoSeventy);
			break;
		case 'q':
			exit(0);
		default:
			break;
	}

	glutPostRedisplay();
}

/**
 * Performs one move per second.
 * Pops moves from the end of the list "moves".
 */
void update() {
    time(&now);
    if (difftime(now, lastUpdate) > 0 && !moves.empty()) {
        RubiksCube::Move m = moves.back();
        cube->rotate(m.slice, m.degrees);
        moves.pop_back();
        time(&lastUpdate);
    }
    glutPostRedisplay();
}

int main(int argc, char **argv) {
    time(&lastUpdate);

    // TEST
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();

    // LOGIC
    solve();

    // GRAPHICS
    initializeCubes();
	moves = cube->scramble(20);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Rubik's Cube");
    glutIdleFunc(update);
    glutDisplayFunc(displayWrapper);
    glutSpecialFunc(graphicsSpecialKeys);
    glutKeyboardFunc(myKeyboardFunc);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();

    return 0;
}

