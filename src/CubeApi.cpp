#include "RubiksCube.h"

#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

EXTERNC api_rotateXLeft();
// EXTERNC api_rotateXRight();
// EXTERNC api_rotateYTop();
// EXTERNC api_rotateYBottom();
// EXTERNC api_rotateZFront();
// EXTERNC api_rotateZBack();
// EXTERNC api_rotateXSlice();
// EXTERNC api_rotateYSlice();
// EXTERNC api_rotateZSlice();

#undef EXTERNC

typedef void* api_cube;

api_cube api_cube_init() {
    return new RubiksCube();
}

void api_rotateXLeft(api_cube self) {
    RubiksCube typed_self = static_cast<RubiksCube*>(self);
    typed_self->rotateXLeft();
}
