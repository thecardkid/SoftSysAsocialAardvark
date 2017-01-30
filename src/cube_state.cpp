#include "cube_state.h"

float green[3] = { 0.0f, 1.0f, 0.0f };
float orange[3] = { 1.0f, 0.5f, 0.0f };
float red[3] = { 1.0f, 0.0f, 0.0f };
float yellow[3] = { 1.0f, 1.0f, 0.0f };
float blue[3] = { 0.0f, 0.0f, 1.0f };
float magenta[3] = { 1.0f, 0.0f, 1.0f };

float** getColors(int x, int y, int z) {
    float** colors = new float*[6];
    colors[0] = green;
    colors[1] = orange;
    colors[2] = red;
    colors[3] = yellow;
    colors[4] = blue;
    colors[5] = magenta;
    return colors;
}
