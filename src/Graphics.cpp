#include <GL/glut.h>
#include <iostream>
#include "Graphics.h"

/**
 * Represents one of the twenty-seven blocks which make up a 3x3x3 Rubik's cube.
 */
struct Cubelet {
    float vertices[8][3]; // 8 corners, each corner defined by (x,y,z) triple
};

/**
 * The Rubik's cube -- represented by a 3x3x3 array of cubelets
 */
Cubelet rubiksCube[3][3][3];

/**
 * Camera rotations.
 */
double rotate_x = 0; // about the x axis
double rotate_y = 0; // about the y axis

/**
 * The colors used in the cube -- represented by { R, G, B } arrays.
 */
float red[3] = { 1.0f, 0.0f, 0.0f };
float blue[3] = { 0.0f, 0.0f, 1.0f };
float orange[3] = { 1.0f, 0.5f, 0.0f };
float white[3] = { 1.0f, 1.0f, 1.0f };
float yellow[3] = { 1.0f, 1.0f, 0.0f };
float green[3] = { 0.0f, 1.0f, 0.0f };
float black[3] = { 0.0f, 0.0f, 0.0f };

/**
 * The mapping from integer enum to color
 * Keep this method in sync with the Color enum in src/Enums.h.
 */
float* intToColor(int i) {
    switch (i) {
        case 0: return red;
        case 1: return blue;
        case 2: return orange;
        case 3: return white;
        case 4: return yellow;
        case 5: return green;
        default: return black;
    }
}

/**
 * Draws a single cubelet.
 *
 * @param cubelet: the cubelet to draw
 * @param cubeletState: a 6x3 array of colors to assign to the cubelet's faces
 */
void drawCubelet(Cubelet cubelet, float** cubeletState) {
    glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
        // Top face (y = 1.0f)
        // Define vertices in counter-clockwise (CCW) order with normal pointing out
        glColor3f(cubeletState[0][0], cubeletState[0][1], cubeletState[0][2]);
        glVertex3f(cubelet.vertices[2][0], cubelet.vertices[2][1], cubelet.vertices[2][2]);
        glVertex3f(cubelet.vertices[5][0], cubelet.vertices[5][1], cubelet.vertices[5][2]);
        glVertex3f(cubelet.vertices[7][0], cubelet.vertices[7][1], cubelet.vertices[7][2]);
        glVertex3f(cubelet.vertices[4][0], cubelet.vertices[4][1], cubelet.vertices[4][2]);

        // Bottom face (y = -1.0f)
        glColor3f(cubeletState[1][0], cubeletState[1][1], cubeletState[1][2]);
        glVertex3f(cubelet.vertices[0][0], cubelet.vertices[0][1], cubelet.vertices[0][2]);
        glVertex3f(cubelet.vertices[3][0], cubelet.vertices[3][1], cubelet.vertices[3][2]);
        glVertex3f(cubelet.vertices[6][0], cubelet.vertices[6][1], cubelet.vertices[6][2]);
        glVertex3f(cubelet.vertices[1][0], cubelet.vertices[1][1], cubelet.vertices[1][2]);

        // Front face  (z = 1.0f)
        glColor3f(cubeletState[2][0], cubeletState[2][1], cubeletState[2][2]);
        glVertex3f(cubelet.vertices[0][0], cubelet.vertices[0][1], cubelet.vertices[0][2]);
        glVertex3f(cubelet.vertices[1][0], cubelet.vertices[1][1], cubelet.vertices[1][2]);
        glVertex3f(cubelet.vertices[5][0], cubelet.vertices[5][1], cubelet.vertices[5][2]);
        glVertex3f(cubelet.vertices[2][0], cubelet.vertices[2][1], cubelet.vertices[2][2]);

        // Back face (z = -1.0f)
        glColor3f(cubeletState[3][0], cubeletState[3][1], cubeletState[3][2]);
        glVertex3f(cubelet.vertices[3][0], cubelet.vertices[3][1], cubelet.vertices[3][2]);
        glVertex3f(cubelet.vertices[4][0], cubelet.vertices[4][1], cubelet.vertices[4][2]);
        glVertex3f(cubelet.vertices[7][0], cubelet.vertices[7][1], cubelet.vertices[7][2]);
        glVertex3f(cubelet.vertices[6][0], cubelet.vertices[6][1], cubelet.vertices[6][2]);

        // Left face (x = -1.0f)
        glColor3f(cubeletState[4][0], cubeletState[4][1], cubeletState[4][2]);
        glVertex3f(cubelet.vertices[0][0], cubelet.vertices[0][1], cubelet.vertices[0][2]);
        glVertex3f(cubelet.vertices[2][0], cubelet.vertices[2][1], cubelet.vertices[2][2]);
        glVertex3f(cubelet.vertices[4][0], cubelet.vertices[4][1], cubelet.vertices[4][2]);
        glVertex3f(cubelet.vertices[3][0], cubelet.vertices[3][1], cubelet.vertices[3][2]);

        // Right face (x = 1.0f)
        glColor3f(cubeletState[5][0], cubeletState[5][1], cubeletState[5][2]);
        glVertex3f(cubelet.vertices[1][0], cubelet.vertices[1][1], cubelet.vertices[1][2]);
        glVertex3f(cubelet.vertices[6][0], cubelet.vertices[6][1], cubelet.vertices[6][2]);
        glVertex3f(cubelet.vertices[7][0], cubelet.vertices[7][1], cubelet.vertices[7][2]);
        glVertex3f(cubelet.vertices[5][0], cubelet.vertices[5][1], cubelet.vertices[5][2]);
   glEnd();  // End of drawing color-cube
}

/**
 * Gets state for the specified cubelet.
 *
 * @param state: the state of the Rubik's cube (a 6x3x3 array of integers
 * which represent Colors)
 * @param x, y, z: the indices of the cubelet in the rubik's cube
 */
float** getCubeletState(int*** state, int x, int y, int z) {
    float** cubeletState = new float*[6];
    cubeletState[0] = black; // front
    cubeletState[1] = black; // back
    cubeletState[2] = black; // bottom
    cubeletState[3] = black; // top
    cubeletState[4] = black; // right
    cubeletState[5] = black; // left

    // TODO(swalters): numbering schemes for API and graphics don't match up.
    // Should be easy to fix.

    // x: 0 = right to 2 = left
    switch (x) {
        case 0: // right layer -- set right sides
            cubeletState[4] = intToColor(state[1][2 - z][2 - y]);
            break;
        case 2: // left layer -- set left sides
            cubeletState[5] = intToColor(state[0][2 - z][y]);
            break;
    }

    // y: 0 = back to 2 = front
    switch (y) {
        case 0: // back layer -- set back sides
            cubeletState[1] = intToColor(state[5][2 - z][x]);
            break;
        case 2: // front layer -- set front sides
            cubeletState[0] = intToColor(state[4][2 - z][2 - x]);
            break;
    }

    // z: 0 = bottom to 2 = top
    switch (z) {
        case 0: // bottom layer -- set bottom sides
            cubeletState[2] = intToColor(state[3][2 - y][2 - x]);
            break;
        case 2: // top layer -- set top sides
            cubeletState[3] = intToColor(state[2][y][2 - x]);
            break;
    }

    return cubeletState;
}

/**
 * Draws the Rubik's cube.
 *
 * @param state: the state of the Rubik's cube (a 6x3x3 array of integers
 * which represent Colors)
 */
void drawRubiksCube(int*** state) {
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            for (int z = 0; z < 3; z++) {
                float** cubeletState = getCubeletState(state, x, y, z);
                drawCubelet(rubiksCube[x][y][z], cubeletState);
            }
        }
    }
}

/**
 * Moves a cubelet diagonally along the line x = y = z
 * by moving it centerShift in each direction.
 *
 * @param x, y, z: the indices of the cubelet in the rubik's cube
 * @param centerShift: the distance to move the cubelet in each direction
 */
void centerCubelet(int x, int y, int z, float centerShift) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 3; j++) {
            rubiksCube[x][y][z].vertices[i][j] -= centerShift;
        }
    }
}

/**
 * Defines the geometry of the Rubik's cube by setting the vertices
 * of its cubelets.
 */
void initializeCube() {
    float shift = 1.5;
    float cubeletSize = 0.9; // margin between cubes is the remaining 0.1

    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            for (int z = 0; z < 3; z++) {
                rubiksCube[x][y][z].vertices[0][0] = x;
                rubiksCube[x][y][z].vertices[0][1] = y;
                rubiksCube[x][y][z].vertices[0][2] = z;

                rubiksCube[x][y][z].vertices[1][0] = x + cubeletSize;
                rubiksCube[x][y][z].vertices[1][1] = y;
                rubiksCube[x][y][z].vertices[1][2] = z;

                rubiksCube[x][y][z].vertices[2][0] = x;
                rubiksCube[x][y][z].vertices[2][1] = y + cubeletSize;
                rubiksCube[x][y][z].vertices[2][2] = z;

                rubiksCube[x][y][z].vertices[3][0] = x;
                rubiksCube[x][y][z].vertices[3][1] = y;
                rubiksCube[x][y][z].vertices[3][2] = z + cubeletSize;

                rubiksCube[x][y][z].vertices[4][0] = x;
                rubiksCube[x][y][z].vertices[4][1] = y + cubeletSize;
                rubiksCube[x][y][z].vertices[4][2] = z + cubeletSize;

                rubiksCube[x][y][z].vertices[5][0] = x + cubeletSize;
                rubiksCube[x][y][z].vertices[5][1] = y + cubeletSize;
                rubiksCube[x][y][z].vertices[5][2] = z;

                rubiksCube[x][y][z].vertices[6][0] = x + cubeletSize;
                rubiksCube[x][y][z].vertices[6][1] = y;
                rubiksCube[x][y][z].vertices[6][2] = z + cubeletSize;

                rubiksCube[x][y][z].vertices[7][0] = x + cubeletSize;
                rubiksCube[x][y][z].vertices[7][1] = y + cubeletSize;
                rubiksCube[x][y][z].vertices[7][2] = z + cubeletSize;

                centerCubelet(x, y, z, 1.5);
            }
        }
    }
}

/**
 * Handles graphics-related keyboard events.
 *
 * @param key: which key was pressed
 * @param x, y: coordinates of the mouse when the key was pressed
 */
void graphicsSpecialKeys(int key, int x, int y) {
    if (key == GLUT_KEY_RIGHT) {
        rotate_y += 5;
    } else if (key == GLUT_KEY_LEFT) {
        rotate_y -= 5;
    } else if (key == GLUT_KEY_UP) {
        rotate_x += 5;
    } else if (key == GLUT_KEY_DOWN) {
        rotate_x -= 5;
    } else if (key == GLUT_KEY_F1) {
        rotate_x = 0;
        rotate_y = 0;
    }
    glutPostRedisplay();
}

void display(int*** state) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set up the projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);
    gluPerspective(60, w / h, 0.1, 100);

    // Set up the model matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Look at cube from the corner
    gluLookAt(5, 5, 5, 0, 0, 0, 0, 0, 1);

    // Set the camera rotation.
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);

    // Animation uses double-buffering
    drawRubiksCube(state);
    glutSwapBuffers();
}
