#ifndef SOFTSYS_ASOCIAL_AARDVARK_SHARED_H
#define SOFTSYS_ASOCIAL_AARDVARK_SHARED_H

/**
 * Mark function parameters which are unused with UNUSED(param)
 * to avoid triggering unused-variable warnings.
 */
#define UNUSED(expr) do { (void)(expr); } while (0)

#include <stdio.h>

/**
 * Letter notation for Rubik's cube slices (a slice is a coplanar set of 9 cubelets).
 * Based on notation from https://ruwix.com/the-rubiks-cube/notation/.
 *
 * LastRotation represents the size of the enum.
 *
 * Not defined as enum class to allow for implicit casting to ints.
 */
typedef enum {U, L, F, R, B, D, M, E, S, LastRotation} LetterNotation;

/**
 * Converts an integer to a LetterNotation
 *
 * @param x: the integer
 * @return the letter notation
 */
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

/**
 * Helper method that copies an int*** into an int[6][3][3]
 *
 * @param copyOfState: the destination int[6][3][3]
 * @param state: the source int***
 */
void copyState(int copyOfState[6][3][3], int*** state);

/**
 * Helper method that prints out a list of moves to stdout.
 *
 * @param moves: an array of moves
 * @param s: size of the array of moves
 */
void print_moves(LetterNotation* moves, int s);

/**
 * Helper method that prints out the individual elements
 * of a cube face to stdout.
 *
 * @param face_: 2x2 of a cube's face
 */
void printFace(int** face_);

#endif
