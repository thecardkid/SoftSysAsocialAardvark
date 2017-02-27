extern "C" {
    #include "Thread.h"
}

#include <GL/glut.h>
#include <gtest/gtest.h>
#include <iostream>

#include "CubeFace.h"
#include "Graphics.h"
#include "RubiksCube.h"
#include "Connector.h"
#include "Shared.h"

int scrambleDepth = 6;
RubiksCube* cube = new RubiksCube();
std::vector<RubiksCube::Move> moves;
LetterNotation* solveLetterNotations;
time_t lastUpdate, now;
int ready = 0;

void getStateAndDisplay() {
    int*** colors = cube->getState();
    display(colors);
}

void copyState(int copyOfState[6][3][3], int*** state) {
    int i,j,k;
    for (i=0; i<6; i++) {
        for (j=0; j<3; j++) {
            for (k=0; k<3; k++) {
                copyOfState[i][j][k] = state[i][j][k];
            }
        }
    }
}

void myKeyboardFunc(unsigned char key, int x, int y) {
    switch (key) {
        case 'x':
            moves = cube->scramble(scrambleDepth);
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
        case 't':
            int copyOfState[6][3][3];
            copyState(copyOfState, cube->getState());
            solveLetterNotations = create_threads(copyOfState, scrambleDepth);
            int i;
            RubiksCube::Move m;
            for (i=0; i<scrambleDepth; i++) {
                m.slice = solveLetterNotations[i];
                m.degrees = Ninety;
                moves[scrambleDepth-i-1] = m;
            }
            print_moves(solveLetterNotations, scrambleDepth);
            ready = 1;
            break;
        default:
            break;
    }

    glutPostRedisplay();
}

void update() {
    time(&now);
    if (ready == 1 && difftime(now, lastUpdate) > 0 && !moves.empty()) {
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

    // GRAPHICS
    initializeCubes();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Rubik's Cube");
    glutIdleFunc(update);
    glutDisplayFunc(getStateAndDisplay);
    glutSpecialFunc(graphicsSpecialKeys);
    glutKeyboardFunc(myKeyboardFunc);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();

    return 0;
}
