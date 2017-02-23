#include <cstdlib>
#include "Connector.h"
#include "RubiksCube.h"

#ifdef __cplusplus
extern "C" {
#endif

int*** rubiks_cube_rotate(int*** state, LetterNotation action, Degrees degrees) {
    RubiksCube *instance = new RubiksCube(state);
    instance->rotate(action, degrees);
    return instance->getState();
}

int*** get_default_state() {
    RubiksCube *instance = new RubiksCube();
    return instance->getState();
}

#ifdef __cplusplus
}
#endif
