#ifndef SOFTSYS_ASOCIAL_AARDVARK_GRAPHICS_H
#define SOFTSYS_ASOCIAL_AARDVARK_GRAPHICS_H

/**
 * Defines the geometry of the Rubik's cube by setting the vertices
 * of its cubelets.
 */
void initializeCube();

/**
 * Displays a cube with the specified state.
 *
 * @param state: the cube state (6x3x3 array)
 */
void display(int*** colors);


/**
 * Graphics keypress handler.
 *
 * @param key: the key pressed
 * @param x, y: the mouse coordinates at time of keypress
 */
void graphicsSpecialKeys(int key, int x, int y);

#endif
