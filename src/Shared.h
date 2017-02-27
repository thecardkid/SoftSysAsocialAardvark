#ifndef SOFTSYS_ASOCIAL_AARDVARK_SHARED_H
#define SOFTSYS_ASOCIAL_AARDVARK_SHARED_H

/**
 * Based on notation from https://ruwix.com/the-rubiks-cube/notation/.
 * LastRotation acts as a dummy variable so that we can call the
 * % operator when trying to generate random moves in scramble().
 * It is not used anywhere else.
 *
 * This is also not defined as enum class to allow for implicit
 * casting to ints.
 */
typedef enum {U, L, F, R, B, D, M, E, S, LastRotation} LetterNotation;

typedef enum {Ninety, OneEighty, TwoSeventy, LastDegree} Degrees;

enum Color {Red, Blue, Orange, White, Yellow, Green};

typedef struct {
  LetterNotation rotation;
  Degrees degrees;
  int state[6][3][3];
  int max_depth;
} thread_struct;

typedef struct {
	LetterNotation solveMoves[20];
	int status;
} thread_return_struct;

LetterNotation convert_int_to_rotation(int x);
void print_moves(LetterNotation* moves, int s);

#endif
