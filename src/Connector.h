#ifndef SOFTSYS_ASOCIAL_AARDVARK_CONNECTOR_H
#define SOFTSYS_ASOCIAL_AARDVARK_CONNECTOR_H

#include "RubiksCube.h"
#include "Enums.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Modifies the state of a Rubik's cube with a rotation.
 *
 * @param state: the state of the cube (modified by method)
 * @param slice: the slice of the cube to rotate
 * @param degrees: the number of degrees to rotate the slice, clockwise
 */
void rubiks_cube_rotate(int*** state, LetterNotation slice, Degrees degrees);

/**
 * Creates the default Rubik's cube state
 * (according to http://www.rubiksplace.com/move-notations/)
 *
 * @return the default Rubik's Cube state
 */
int*** get_default_state();

#ifdef __cplusplus
}
#endif

#endif
