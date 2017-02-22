#ifndef SOFTSYS_ASOCIAL_AARDVARK_CONNECTOR_H
#define SOFTSYS_ASOCIAL_AARDVARK_CONNECTOR_H

#include "RubiksCube.h"
#include "Enums.h"

#ifdef __cplusplus
extern "C" {
#endif

void use_rubiks_cube(RubiksCube *cube);
void new_rubiks_cube_with_state(int*** state);
void new_rubiks_cube_default_state();
int*** rubiks_cube_get_state();
void rubiks_cube_rotate(LetterNotation action, Degrees degrees);

#ifdef __cplusplus
}
#endif

#endif
