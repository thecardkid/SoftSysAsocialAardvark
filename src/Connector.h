#ifndef SOFTSYS_ASOCIAL_AARDVARK_CONNECTOR_H
#define SOFTSYS_ASOCIAL_AARDVARK_CONNECTOR_H

#include "RubiksCube.h"
#include "Shared.h"

#ifdef __cplusplus
extern "C" {
#endif

void rubiks_cube_rotate(int*** state, LetterNotation action, Degrees degrees);
int*** get_default_state();
void printCPointers(int*** state);

#ifdef __cplusplus
}
#endif

#endif
