#include <GL/glut.h>
#include <iostream>
#include "Graphics.h"

struct Cube {
	float vertices[8][3]; // 8 corners, each corner defined by (x,y,z) triple
	float face_colors[6][3]; // 6 faces, each face color defined by (R,G,B) triple
};

int n = 3;
Cube cubes[3][3][3]; // 3-dimensional array of cubes

void drawCube(Cube cube, float** colors) {
	glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
	  // Top face (y = 1.0f)
	  // Define vertices in counter-clockwise (CCW) order with normal pointing out
	  glColor3f(colors[0][0], colors[0][1], colors[0][2]);
	  glVertex3f(cube.vertices[2][0], cube.vertices[2][1], cube.vertices[2][2]);
	  glVertex3f(cube.vertices[5][0], cube.vertices[5][1], cube.vertices[5][2]);
	  glVertex3f(cube.vertices[7][0], cube.vertices[7][1], cube.vertices[7][2]);
	  glVertex3f(cube.vertices[4][0], cube.vertices[4][1], cube.vertices[4][2]);

	  // Bottom face (y = -1.0f)
	  glColor3f(colors[1][0], colors[1][1], colors[1][2]);
	  glVertex3f(cube.vertices[0][0], cube.vertices[0][1], cube.vertices[0][2]);
	  glVertex3f(cube.vertices[3][0], cube.vertices[3][1], cube.vertices[3][2]);
	  glVertex3f(cube.vertices[6][0], cube.vertices[6][1], cube.vertices[6][2]);
	  glVertex3f(cube.vertices[1][0], cube.vertices[1][1], cube.vertices[1][2]);

	  // Front face  (z = 1.0f)
	  glColor3f(colors[2][0], colors[2][1], colors[2][2]);
	  glVertex3f(cube.vertices[0][0], cube.vertices[0][1], cube.vertices[0][2]);
	  glVertex3f(cube.vertices[1][0], cube.vertices[1][1], cube.vertices[1][2]);
	  glVertex3f(cube.vertices[5][0], cube.vertices[5][1], cube.vertices[5][2]);
	  glVertex3f(cube.vertices[2][0], cube.vertices[2][1], cube.vertices[2][2]);

	  // Back face (z = -1.0f)
	  glColor3f(colors[3][0], colors[3][1], colors[3][2]);
	  glVertex3f(cube.vertices[3][0], cube.vertices[3][1], cube.vertices[3][2]);
	  glVertex3f(cube.vertices[4][0], cube.vertices[4][1], cube.vertices[4][2]);
	  glVertex3f(cube.vertices[7][0], cube.vertices[7][1], cube.vertices[7][2]);
	  glVertex3f(cube.vertices[6][0], cube.vertices[6][1], cube.vertices[6][2]);

	  // Left face (x = -1.0f)
	  glColor3f(colors[4][0], colors[4][1], colors[4][2]);
	  glVertex3f(cube.vertices[0][0], cube.vertices[0][1], cube.vertices[0][2]);
	  glVertex3f(cube.vertices[2][0], cube.vertices[2][1], cube.vertices[2][2]);
	  glVertex3f(cube.vertices[4][0], cube.vertices[4][1], cube.vertices[4][2]);
	  glVertex3f(cube.vertices[3][0], cube.vertices[3][1], cube.vertices[3][2]);

	  // Right face (x = 1.0f)
	  glColor3f(colors[5][0], colors[5][1], colors[5][2]);
	  glVertex3f(cube.vertices[1][0], cube.vertices[1][1], cube.vertices[1][2]);
	  glVertex3f(cube.vertices[6][0], cube.vertices[6][1], cube.vertices[6][2]);
	  glVertex3f(cube.vertices[7][0], cube.vertices[7][1], cube.vertices[7][2]);
	  glVertex3f(cube.vertices[5][0], cube.vertices[5][1], cube.vertices[5][2]);
   glEnd();  // End of drawing color-cube
}

void initializeCubes() {
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			for (int z = 0; z < 3; z++) {
				cubes[x][y][z].vertices[0][0] = x;
				cubes[x][y][z].vertices[0][1] = y;
				cubes[x][y][z].vertices[0][2] = z;

				cubes[x][y][z].vertices[1][0] = x + 0.9;
				cubes[x][y][z].vertices[1][1] = y;
				cubes[x][y][z].vertices[1][2] = z;

				cubes[x][y][z].vertices[2][0] = x;
				cubes[x][y][z].vertices[2][1] = y + 0.9;
				cubes[x][y][z].vertices[2][2] = z;

				cubes[x][y][z].vertices[3][0] = x;
				cubes[x][y][z].vertices[3][1] = y;
				cubes[x][y][z].vertices[3][2] = z + 0.9;

				cubes[x][y][z].vertices[4][0] = x;
				cubes[x][y][z].vertices[4][1] = y + 0.9;
				cubes[x][y][z].vertices[4][2] = z + 0.9;

				cubes[x][y][z].vertices[5][0] = x + 0.9;
				cubes[x][y][z].vertices[5][1] = y + 0.9;
				cubes[x][y][z].vertices[5][2] = z;

				cubes[x][y][z].vertices[6][0] = x + 0.9;
				cubes[x][y][z].vertices[6][1] = y;
				cubes[x][y][z].vertices[6][2] = z + 0.9;

				cubes[x][y][z].vertices[7][0] = x + 0.9;
				cubes[x][y][z].vertices[7][1] = y + 0.9;
				cubes[x][y][z].vertices[7][2] = z + 0.9;
			}
		}
	}
}


float red[3] = { 1.0f, 0.0f, 0.0f };
float blue[3] = { 0.0f, 0.0f, 1.0f };
float orange[3] = { 1.0f, 0.5f, 0.0f };
float white[3] = { 1.0f, 1.0f, 1.0f };
float yellow[3] = { 1.0f, 1.0f, 0.0f };
float green[3] = { 0.0f, 1.0f, 0.0f };
float black[3] = { 0.0f, 0.0f, 0.0f };

float** tempGetColors(int x, int y, int z) {
    float** colors = new float*[6];

    colors[0] = green; // "front right"
    colors[1] = yellow; // "back left"
    colors[2] = white; // "bottom"
    colors[3] = orange; // "top"
    colors[4] = blue; // "back right"
    colors[5] = red; // "front left"
    return colors;
}

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

float** getCubeColors(int*** colors, int x, int y, int z) {
	float** fcolors = new float*[6];
	fcolors[0] = black; // front
	fcolors[1] = black; // back
	fcolors[2] = black; // bottom
	fcolors[3] = black; // top
	fcolors[4] = black; // right
	fcolors[5] = black; // left

	// x: 0 = right to 2 = left
	// y: 0 = back to 2 = front
	// z: 0 = bottom to 2 = top

	// TODO: numbering schemes for API and graphics don't match up.
	// Should be easy to fix.
	switch (x) {
		case 0: // right layer -- set right sides
			fcolors[4] = intToColor(colors[3][2 - z][2 - y]);
			break;
		case 2: // left layer -- set left sides
			fcolors[5] = intToColor(colors[2][2 - z][y]);
	}

	switch (y) {
		case 0: // back layer -- set back sides
			fcolors[1] = intToColor(colors[5][2 - z][2 - x]);
			break;
		case 2: // front layer -- set front sides
			fcolors[0] = intToColor(colors[4][2 - z][x]);
	}

	switch (z) {
		case 0: // bottom layer -- set bottom sides
			fcolors[2] = intToColor(colors[1][y][2 - x]);
			break;
		case 2: // top layer -- set top sides
			fcolors[3] = intToColor(colors[0][y][x]);
	}

	return fcolors;
}

void drawCubes(int*** colors) {
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			for (int z = 0; z < 3; z++) {
				float** cubeColors = getCubeColors(colors, x, y, z);
				drawCube(cubes[x][y][z], cubeColors); // TODO
			}
		}
	}
}

void setVertex(Cube& cube, int vertex1, int vertex2) {
	cube.vertices[vertex1][0] = cube.vertices[vertex2][0];
	cube.vertices[vertex1][1] = cube.vertices[vertex2][1];
	cube.vertices[vertex1][2] = cube.vertices[vertex2][2];
}

void rotateIndividualCube(Cube& cube, int direction) {
	if (direction == 1) {
		// Rotate individual cube left
		float temp_a = cube.vertices[0][0];
		float temp_b = cube.vertices[0][1];
		float temp_c = cube.vertices[0][2];

		setVertex(cube, 0, 2);
		setVertex(cube, 2, 5);
		setVertex(cube, 5, 1);

		cube.vertices[1][0] = temp_a;
		cube.vertices[1][1] = temp_b;
		cube.vertices[1][2] = temp_c;

		temp_a = cube.vertices[3][0];
		temp_b = cube.vertices[3][1];
		temp_c = cube.vertices[3][2];

		setVertex(cube, 3, 4);
		setVertex(cube, 4, 7);
		setVertex(cube, 7, 6);

		cube.vertices[6][0] = temp_a;
		cube.vertices[6][1] = temp_b;
		cube.vertices[6][2] = temp_c;
	} else if (direction == 3) {
		// Rotate individual cube up
		float temp_a = cube.vertices[0][0];
		float temp_b = cube.vertices[0][1];
		float temp_c = cube.vertices[0][2];

		setVertex(cube, 0, 3);
		setVertex(cube, 3, 4);
		setVertex(cube, 4, 2);

		cube.vertices[2][0] = temp_a;
		cube.vertices[2][1] = temp_b;
		cube.vertices[2][2] = temp_c;

		temp_a = cube.vertices[1][0];
		temp_b = cube.vertices[1][1];
		temp_c = cube.vertices[1][2];

		setVertex(cube, 1, 6);
		setVertex(cube, 6, 7);
		setVertex(cube, 7, 5);

		cube.vertices[5][0] = temp_a;
		cube.vertices[5][1] = temp_b;
		cube.vertices[5][2] = temp_c;
	} else if (direction == 5) {
		// Clockwise rotation
		float temp_a = cube.vertices[0][0];
		float temp_b = cube.vertices[0][1];
		float temp_c = cube.vertices[0][2];

		setVertex(cube, 0, 2);
		setVertex(cube, 2, 5);
		setVertex(cube, 5, 1);

		cube.vertices[1][0] = temp_a;
		cube.vertices[1][1] = temp_b;
		cube.vertices[1][2] = temp_c;

		temp_a = cube.vertices[3][0];
		temp_b = cube.vertices[3][1];
		temp_c = cube.vertices[3][2];

		setVertex(cube, 3, 4);
		setVertex(cube, 4, 7);
		setVertex(cube, 7, 6);

		cube.vertices[6][0] = temp_a;
		cube.vertices[6][1] = temp_b;
		cube.vertices[6][2] = temp_c;
	}
}

void setCubeLocation(Cube& cube, Cube cube2) {
	for (int i = 0; i < 8; i++) {
		cube.vertices[i][0] = cube2.vertices[i][0];
		cube.vertices[i][1] = cube2.vertices[i][1];
		cube.vertices[i][2] = cube2.vertices[i][2];
	}
}

void rotateFront() {
	// Corners
	Cube temp_cube = cubes[0][0][0];
	setCubeLocation(cubes[0][0][0], cubes[0][2][0]);
	setCubeLocation(cubes[0][2][0], cubes[2][2][0]);
	setCubeLocation(cubes[2][2][0], cubes[2][0][0]);
	setCubeLocation(cubes[2][0][0], temp_cube);

	rotateIndividualCube(cubes[0][0][0], 1);
	rotateIndividualCube(cubes[0][2][0], 1);
	rotateIndividualCube(cubes[2][0][0], 1);
	rotateIndividualCube(cubes[2][2][0], 1);

	// Edges
	temp_cube = cubes[1][0][0];
	setCubeLocation(cubes[1][0][0], cubes[0][1][0]);
	setCubeLocation(cubes[0][1][0], cubes[1][2][0]);
	setCubeLocation(cubes[1][2][0], cubes[2][1][0]);
	setCubeLocation(cubes[2][1][0], temp_cube);

	rotateIndividualCube(cubes[1][0][0], 1);
	rotateIndividualCube(cubes[0][1][0], 1);
	rotateIndividualCube(cubes[2][1][0], 1);
	rotateIndividualCube(cubes[1][2][0], 1);
}

double rotate_y = 0;
double rotate_x = 0;
void specialKeys(int key, int x, int y) {
	if (key == GLUT_KEY_RIGHT) {
		rotate_y += 5;
	} else if (key == GLUT_KEY_LEFT) {
		rotate_y -= 5;
	} else if (key == GLUT_KEY_UP) {
		rotate_x += 5;
	} else if (key == GLUT_KEY_DOWN) {
		rotate_x -= 5;
	} else if (key == GLUT_KEY_F5) {
		rotateFront();
	}
	glutPostRedisplay();
}

void display(int*** colors) {
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	int w = glutGet(GLUT_WINDOW_WIDTH);
	int h = glutGet(GLUT_WINDOW_HEIGHT);
	gluPerspective(60, w / h, 0.1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(3, 3, 3, 0, 0, 0, 0, 0, 1);

	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);

    drawCubes(colors);
    glutSwapBuffers();
}
