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

void displayWrapper() {
    int*** colors = cube->getState();
    display(colors);
}

void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_F1:
            cube->rotate(L, Ninety);
            break;
        case GLUT_KEY_F2:
            cube->rotate(R, Ninety);
            break;
        case GLUT_KEY_F3:
            cube->rotate(U, Ninety);
            break;
        case GLUT_KEY_F4:
            cube->rotate(D, Ninety);
            break;
        case GLUT_KEY_F5:
            cube->rotate(F, Ninety);
            break;
        case GLUT_KEY_F6:
            cube->rotate(B, Ninety);
            break;
        case GLUT_KEY_F7:
            cube->rotate(M, Ninety);
            break;
        case GLUT_KEY_F8:
            cube->rotate(E, Ninety);
            break;
        case GLUT_KEY_F9:
            cube->rotate(S, Ninety);
            break;
    }

    graphicsSpecialKeys(key, x, y);
}

void update() {
    glutPostRedisplay();
}

int main(int argc, char **argv) {
    // TEST
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();

    // LOGIC
    setRubiksCube(cube);
    solve();

    // GRAPHICS
    initializeCubes();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Rubik's Cube");
    glutIdleFunc(update);
    glutDisplayFunc(displayWrapper);
    glutSpecialFunc(specialKeys);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();

    return 0;
}

