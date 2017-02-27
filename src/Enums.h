#ifndef SOFTSYS_ASOCIAL_AARDVARK_ENUMS_H
#define SOFTSYS_ASOCIAL_AARDVARK_ENUMS_H

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

/**
 * Degree notation for Rubik's cube moves.
 * Moves are performed clockwise.
 *
 * LastDegree represents the size of the enum.
 *
 * Not defined as enum class to allow for implicit casting to ints.
 */
typedef enum {Ninety, OneEighty, TwoSeventy, LastDegree} Degrees;

enum Color {Red, Blue, Orange, White, Yellow, Green};

/**
 * Represents a single move using two components:
 * letter notation to represent which slice is moving &
 * degrees to denote the clockwise rotation of the slice.
 */
struct Move {
    LetterNotation slice;
    Degrees degrees;
};

#endif
