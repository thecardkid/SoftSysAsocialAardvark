#include <cstdlib>
#include "Connector.h"
#include "RubiksCube.h"

#ifdef __cplusplus
extern "C" {
#endif

static RubiksCube *RubiksCube_instance = NULL;

void setRubiksCube(RubiksCube *cube) {
    RubiksCube_instance = cube;
}

void lazyRubiksCube() {
    if (RubiksCube_instance == NULL) {
        RubiksCube_instance = new RubiksCube();
    }
}

int*** RubiksCube_getState() {
    return RubiksCube_instance->getState();
}

void RubiksCube_rotate(LetterNotation action, Degrees degrees) {
    if (RubiksCube_instance == NULL) {
        lazyRubiksCube();
    }
    RubiksCube_instance->rotate(action, degrees);
}

#ifdef __cplusplus
}
#endif
