#include <cstdlib>
#include "Connector.h"
#include "RubiksCube.h"

#ifdef __cplusplus
extern "C" {
#endif

static RubiksCube *instance = NULL;

/*
 * Sets instance to an existing RubiksCube
 * Use this method if you want to use C to manipulate the RubiksCube which
 * connects to graphics & is instantiated with C++
 */
void use_rubiks_cube(RubiksCube *cube) {
    instance = cube;
}

/*
 * Sets up a new, graphics-less RubiksCube instance with preexisting state
 * Use this method if you want to manipulate a RubiksCube instance e.g. for
 * the purpose of a solving algorithm -- without leaving C and without
 * interfacing with the graphics
 */
void new_rubiks_cube_with_state(int*** state) {
    instance = new RubiksCube(state);
}

/*
 * Works the same way as newRubiksCube (sets up a new, graphics-less RubiksCube
 * instance) but in the default state, not a specified one
 */
void new_rubiks_cube_default_state() {
    instance = new RubiksCube();
}

int*** rubiks_cube_get_state() {
    return instance->getState();
}

void rubiks_cube_rotate(LetterNotation action, Degrees degrees) {
    if (instance == NULL) {
        new_rubiks_cube_default_state();
    }
    instance->rotate(action, degrees);
}

#ifdef __cplusplus
}
#endif
