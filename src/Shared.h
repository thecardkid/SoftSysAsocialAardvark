#ifndef SOFTSYS_ASOCIAL_AARDVARK_SHARED_H
#define SOFTSYS_ASOCIAL_AARDVARK_SHARED_H

#define UNUSED(expr) do { (void)(expr); } while (0)

/**
 * Letter notation for Rubik's cube slices (a slice is a coplanar set of 9 cubelets).
 * Based on notation from https://ruwix.com/the-rubiks-cube/notation/.
 *
 * LastRotation represents the size of the enum.
 *
 * Not defined as enum class to allow for implicit casting to ints.
 */
typedef enum {U, L, F, R, B, D, M, E, S, LastRotation} LetterNotation;
LetterNotation convert_int_to_rotation(int x);

/**
 * Degree notation for Rubik's cube moves.
 * Moves are performed clockwise.
 *
 * LastDegree represents the size of the enum.
 *
 * Not defined as enum class to allow for implicit casting to ints.
 */
typedef enum {Ninety, OneEighty, TwoSeventy, LastDegree} Degrees;

/**
 * Represents a single move using two components:
 * letter notation to represent which slice is moving &
 * degrees to denote the clockwise rotation of the slice.
 */
struct Move {
    LetterNotation slice;
    Degrees degrees;
};

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

void print_moves(LetterNotation* moves, int s);

#endif
