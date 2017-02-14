#include <stdio.h>
#include <stdlib.h>
#include "Connector.h"
#include "Logic.h"
#include "Enums.h"

int solve() {
    printf("%i", LastRotation);
    RubiksCube_rotateXLeft();
    return 0;
}
