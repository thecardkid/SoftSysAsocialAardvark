#include <cstdlib>
#include "Connector.h"
#include "RubiksCube.h"

#ifdef __cplusplus
extern "C" {
#endif

static RubiksCube *RubiksCube_instance = NULL;

/*
 * Sets RubiksCube_instance to an existing RubiksCube
 * Use this method if you want to use C to manipulate the RubiksCube which
 * connects to graphics & is instantiated with C++
 */
void useRubiksCube(RubiksCube *cube) {
    RubiksCube_instance = cube;
}

/*
 * Sets up a new, graphics-less RubiksCube instance with preexisting state
 * Use this method if you want to manipulate a RubiksCube instance e.g. for
 * the purpose of a solving algorithm -- without leaving C and without
 * interfacing with the graphics
 */
void newRubiksCubeWithState(int*** state) {
    RubiksCube_instance = new RubiksCube(state);
}

/*
 * Works the same way as newRubiksCube (sets up a new, graphics-less RubiksCube
 * instance) but in the default state, not a specified one
 */
void newRubiksCubeDefaultState() {
    RubiksCube_instance = new RubiksCube();
}

int*** RubiksCube_getState() {
    return RubiksCube_instance->getState();
}

void RubiksCube_rotate(LetterNotation action, Degrees degrees) {
    if (RubiksCube_instance == NULL) {
        newRubiksCubeDefaultState();
    }
    RubiksCube_instance->rotate(action, degrees);
}

#ifdef __cplusplus
}
#endif
