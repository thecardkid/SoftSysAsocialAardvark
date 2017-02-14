#ifndef SOFTSYS_ASOCIAL_AARDVARK_CONNECTOR_H
#define SOFTSYS_ASOCIAL_AARDVARK_CONNECTOR_H

#include "RubiksCube.h"

#ifdef __cplusplus
extern "C" {
#endif

void setRubiksCube(RubiksCube *cube);
void RubiksCube_rotateXLeft();
int*** RubiksCube_getState();

#ifdef __cplusplus
}
#endif

#endif
