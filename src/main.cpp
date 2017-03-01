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
bool safeToUpdate = false; // True when it's safe to "play" moves on the cube

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
    int copyOfState[6][3][3];
    int i;
    Move m;

    safeToUpdate = false;
    copyState(copyOfState, cube->getState());
    solveLetterNotations = create_threads(copyOfState, scrambleDepth);
    for (i=0; i<scrambleDepth; i++) {
        m.slice = solveLetterNotations[i];
        m.degrees = Ninety;
        moves[scrambleDepth-i-1] = m;
    }
    safeToUpdate = true;
}

void rotateCube(LetterNotation n, Degrees d) {
	if (moves.empty()) cube->rotate(n, d);
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
            if (moves.empty()) moves = cube->scramble(scrambleDepth);
            break;
        case 'l':
            return rotateCube(L, Ninety);
        case 'L':
            return rotateCube(L, TwoSeventy);
        case 'r':
            return rotateCube(R, Ninety);
        case 'R':
            return rotateCube(R, TwoSeventy);
        case 'u':
            return rotateCube(U, Ninety);
        case 'U':
            return rotateCube(U, TwoSeventy);
        case 'd':
            return rotateCube(D, Ninety);
        case 'D':
            return rotateCube(D, TwoSeventy);
        case 'f':
            return rotateCube(F, Ninety);
        case 'F':
            return rotateCube(F, TwoSeventy);
        case 'b':
            return rotateCube(B, Ninety);
        case 'B':
            return rotateCube(B, TwoSeventy);
        case 'm':
            return rotateCube(M, Ninety);
        case 'M':
            return rotateCube(M, TwoSeventy);
        case 'e':
            return rotateCube(E, Ninety);
        case 'E':
            return rotateCube(E, TwoSeventy);
        case 's':
            return rotateCube(S, Ninety);
        case 'S':
            return rotateCube(S, TwoSeventy);
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
        safeToUpdate = !moves.empty();
    }
    glutPostRedisplay();
}

/**
 * Runs all code.
 */
int main(int argc, char **argv) {
    time(&lastUpdate);
    int which = atoi(argv[1]);

    if (which == 1) {
        // TEST
        testing::InitGoogleTest(&argc, argv);
        int testsPassed = RUN_ALL_TESTS();
        return testsPassed;
    }

    if (which == 0) {
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
        return 1;
    }

    return 0;
}
