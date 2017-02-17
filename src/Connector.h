#ifndef SOFTSYS_ASOCIAL_AARDVARK_CONNECTOR_H
#define SOFTSYS_ASOCIAL_AARDVARK_CONNECTOR_H

#include "RubiksCube.h"
#include "Enums.h"

#ifdef __cplusplus
extern "C" {
#endif

void useRubiksCube(RubiksCube *cube);
void newRubiksCubeWithState(int*** state);
void newRubiksCubeDefaultState();
int*** RubiksCube_getState();
void RubiksCube_rotate(LetterNotation action, Degrees degrees);

#ifdef __cplusplus
}
#endif

#endif
