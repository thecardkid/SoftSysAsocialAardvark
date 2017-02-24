#ifndef SOFTSYS_ASOCIAL_AARDVARK_CONNECTOR_H
#define SOFTSYS_ASOCIAL_AARDVARK_CONNECTOR_H

#include "RubiksCube.h"
#include "Shared.h"

#ifdef __cplusplus
extern "C" {
#endif

int*** rubiks_cube_rotate(int*** state, LetterNotation action, Degrees degrees);
int*** get_default_state();

#ifdef __cplusplus
}
#endif

#endif
