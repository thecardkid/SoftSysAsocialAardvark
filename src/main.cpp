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
std::vector<Move> moves;
LetterNotation* solveLetterNotations;
time_t lastUpdate, now; // Last time the cube was rotated & current time
int safeToUpdate = 0; // True when it's safe to "play" moves on the cube

/**
 * Calls graphics display function on state of cube.
 * To be called by glutDisplayFunc
 */
void getStateAndDisplay() {
    int*** colors = cube->getState();
    display(colors);
}

/**
 * Solves the Rubik's cube.
 */
void solve() {
    safeToUpdate = 0;
    int copyOfState[6][3][3];
    copyState(copyOfState, cube->getState());
    solveLetterNotations = create_threads(copyOfState, scrambleDepth);
    int i;
    Move m;
    for (i=0; i<scrambleDepth; i++) {
        m.slice = solveLetterNotations[i];
        m.degrees = Ninety;
        moves[scrambleDepth-i-1] = m;
    }
    safeToUpdate = 1;
}

/**
 * Processes keyboard input and either rotates a cube
 * face accordingly or solves/shuffles a cube.
 * @param key: keyboard input
 * @param x, y: mouse coordinates at time of keypress
 */
void myKeyboardFunc(unsigned char key, int x, int y) {
    // Don't need mouse coordinates
    UNUSED(x);
    UNUSED(y);

    switch (key) {
        case 'x':
            if (moves.empty()) {
                moves = cube->scramble(scrambleDepth);
            }
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
        case 't':
            solve();
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
    if (safeToUpdate && !moves.empty() && difftime(now, lastUpdate) > 0) {
        Move m = moves.back();
        cube->rotate(m.slice, m.degrees);
        moves.pop_back();
        time(&lastUpdate);
    }
    glutPostRedisplay();
}

/**
 * Runs all code.
 */
int main(int argc, char **argv) {
    time(&lastUpdate);

    // TEST
    testing::InitGoogleTest(&argc, argv);
    int testsPassed = RUN_ALL_TESTS();

    // GRAPHICS
    initializeCube();
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

    return testsPassed;
}
