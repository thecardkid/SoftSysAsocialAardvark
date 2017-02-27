#ifndef SOFTSYS_ASOCIAL_AARDVARK_RUBIKSCUBE_H
#define SOFTSYS_ASOCIAL_AARDVARK_RUBIKSCUBE_H

#ifdef __cplusplus
    #include <vector>
    #include "CubeFace.h"
    #include "Shared.h"

    class RubiksCube {
    private:
        /**
         * The edge length of the Rubik's cube (standard is 3).
         */
        int n_;

        /**
         * The faces of the cube.
         * Named in accordance with http://www.rubiksplace.com/move-notations/
         */
        CubeFace xLeft_, xRight_, yTop_, yBottom_, zFront_, zBack_;

        /**
         * Performs rotation. Called from the public method rotate
         * based on args passed into rotate().
         *
         * Changes data in the appropriate CubeFaces depending on the rotation.
         * E.g. rotating the xLeft face also changes parts of the yTop,
         * yBottom, zFront and zBack faces.
         */
        void rotateXLeft();
        void rotateXRight();
        void rotateYTop();
        void rotateYBottom();
        void rotateZFront();
        void rotateZBack();
        void rotateXSlice();
        void rotateYSlice();
        void rotateZSlice();

        /**
         * Reverse an array. Based on how the faces are indexed,
         * sometimes we're not just setting a face's column to another
         * face's row, we also have to reverse the column so that
         * we don't end up with illegal faces/corner cubes.
         *
         * @param a: the array to reverse
         * @return the new reversed array
         */
        int* reverse(int* a);

        /**
         * Construct the move which would undo the specified move.
         *
         * @param m: a move
         * @return the move which would undo m
         */
        Move oppositeMove(Move m);

    public:
        /**
         * Initialize a 3x3 cube with default state.
         */
        RubiksCube();

        /**
         * Initialize a 3x3 cube with specific state.
         */
        RubiksCube(int*** state);

        /**
         * Randomly generate moves and scramble the cube.
         * @param n: How many random moves.
         * @return List of all moves.
         */
        std::vector<Move> scramble(int n);

        /**
         * Perform a clockwise rotation.
         * @param slice: Which slice is rotating.
         * @param degrees: How many degrees.
         */
        void rotate(LetterNotation slice, Degrees degrees);
        void rotate(Move move);

        /**
         * @return A copy of the state of the cube as a 6x3x3 array.
         */
        int*** getState();
    };
#else
    typedef
        struct RubiksCube
            RubiksCube;
#endif

#endif
