#ifndef SOFTSYS_ASOCIAL_AARDVARK_RUBIKSCUBE_H
#define SOFTSYS_ASOCIAL_AARDVARK_RUBIKSCUBE_H

#ifdef __cplusplus
    #include <vector>
    #include "CubeFace.h"

    class RubiksCube {
    private:
    	int n_;
    	CubeFace xLeft_, xRight_, yTop_, yBottom_, zFront_, zBack_;

        /**
         * Reverse an array. Based on how the faces are indexed,
         * sometimes we're not just setting a face's column to another
         * face's row, we also have to reverse the column so that
         * we don't end up with illegal faces/corner cubes.
         *
         * @param a the array to reverse
         * @return the new reversed array
         */
        int* reverse(int* a);

    public:
    	RubiksCube();

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
    	 * Based on notation from https://ruwix.com/the-rubiks-cube/notation/.
    	 * LastRotation acts as a dummy variable so that we can call the
    	 * % operator when trying to generate random moves in scramble().
    	 * It is not used anywhere else.
    	 *
    	 * This is also not defined as enum class to allow for implicit
    	 * casting to ints.
    	 */
    	enum LetterNotation {
    		U, L, F, R, B, D, M, E, S, LastRotation
    	};

    	/**
    	 * A simple struct that captures the randomized sequence
    	 * of moves done by the scramble() method. Its parameters
    	 * are 1. the rotation and 2. how many degrees of that rotation.
    	 */
    	struct Move {
    		RubiksCube::LetterNotation slice;
    		CubeFace::Degrees degrees;
    	};

    	/**
    	 * Randomly generate moves and scramble the cube.
    	 * @param n How many random moves.
    	 * @return List of all moves.
    	 */
    	std::vector<Move> scramble(int n);

        /**
         * Perform a rotation.
         * @param action What rotation.
         * @param degrees How many degrees.
         */
    	void rotate(LetterNotation action, CubeFace::Degrees degrees);
        void rotate(Move move);

    	/**
    	 * @return State of the cube as a 6x3x3 array.
    	 */
    	int*** getState();
    };
#else
    typedef
        struct RubiksCube
            RubiksCube;
#endif

#endif
