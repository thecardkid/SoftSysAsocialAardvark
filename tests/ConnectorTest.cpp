#include <gtest/gtest.h>
#include "../src/Connector.h"
#include "../src/RubiksCube.h"
#include "Utils.h"

const int N = 3;

namespace {
class ConnectorFixture : public testing::Test {
public:
    int*** state;
    CubeFace *expectedXLeft, *expectedXRight, *expectedYTop, *expectedYBottom, *expectedZFront, *expectedZBack;
    ConnectorFixture() {
        state = get_default_state();
        expectedXLeft = new CubeFace(Orange);
        expectedXRight = new CubeFace(Red);
        expectedYTop = new CubeFace(White);
        expectedYBottom = new CubeFace(Yellow);
        expectedZFront = new CubeFace(Green);
        expectedZBack = new CubeFace(Blue);
    }

    bool compare() {
        return allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, state);
    }
};
}

TEST_F(ConnectorFixture, default_state) {
    ASSERT_TRUE(compare());
}

TEST_F(ConnectorFixture, xleft_face_rotation_90) {
    expectedYTop->setCol(0, getArrayOfColor(Blue));
    expectedZFront->setCol(0, getArrayOfColor(White));
    expectedYBottom->setCol(0, getArrayOfColor(Green));
    expectedZBack->setCol(2, getArrayOfColor(Yellow));

    rubiks_cube_rotate(state, L, Ninety);
    ASSERT_TRUE(compare());
}

TEST_F(ConnectorFixture, xleft_face_rotation_180) {
    expectedYTop->setCol(0, getArrayOfColor(Yellow));
    expectedZFront->setCol(0, getArrayOfColor(Blue));
    expectedYBottom->setCol(0, getArrayOfColor(White));
    expectedZBack->setCol(2, getArrayOfColor(Green));

    rubiks_cube_rotate(state, L, OneEighty);
    ASSERT_TRUE(compare());
}


TEST_F(ConnectorFixture, xleft_face_rotation_270) {
    expectedYTop->setCol(0, getArrayOfColor(Green));
    expectedZFront->setCol(0, getArrayOfColor(Yellow));
    expectedYBottom->setCol(0, getArrayOfColor(Blue));
    expectedZBack->setCol(2, getArrayOfColor(White));

    rubiks_cube_rotate(state, L, TwoSeventy);
    ASSERT_TRUE(compare());
}

TEST_F(ConnectorFixture, xright_face_rotation_90) {
    expectedYTop->setCol(2, getArrayOfColor(Green));
    expectedZFront->setCol(2, getArrayOfColor(Yellow));
    expectedYBottom->setCol(2, getArrayOfColor(Blue));
    expectedZBack->setCol(0, getArrayOfColor(White));

    rubiks_cube_rotate(state, R, Ninety);
    ASSERT_TRUE(compare());
}

TEST_F(ConnectorFixture, xright_face_rotation_180) {
    expectedYTop->setCol(2, getArrayOfColor(Yellow));
    expectedZFront->setCol(2, getArrayOfColor(Blue));
    expectedYBottom->setCol(2, getArrayOfColor(White));
    expectedZBack->setCol(0, getArrayOfColor(Green));

    rubiks_cube_rotate(state, R, OneEighty);
    ASSERT_TRUE(compare());
}

TEST_F(ConnectorFixture, xright_face_rotation_270) {
    expectedYTop->setCol(2, getArrayOfColor(Blue));
    expectedZFront->setCol(2, getArrayOfColor(White));
    expectedYBottom->setCol(2, getArrayOfColor(Green));
    expectedZBack->setCol(0, getArrayOfColor(Yellow));

    rubiks_cube_rotate(state, R, TwoSeventy);
    ASSERT_TRUE(compare());
}

TEST_F(ConnectorFixture, ytop_face_rotation_90) {
    expectedXLeft->setRow(0, getArrayOfColor(Green));
    expectedZBack->setRow(0, getArrayOfColor(Orange));
    expectedXRight->setRow(0, getArrayOfColor(Blue));
    expectedZFront->setRow(0, getArrayOfColor(Red));

    rubiks_cube_rotate(state, U, Ninety);
    ASSERT_TRUE(compare());
}

TEST_F(ConnectorFixture, ytop_face_rotation_180) {
    expectedXLeft->setRow(0, getArrayOfColor(Red));
    expectedZBack->setRow(0, getArrayOfColor(Green));
    expectedXRight->setRow(0, getArrayOfColor(Orange));
    expectedZFront->setRow(0, getArrayOfColor(Blue));

    rubiks_cube_rotate(state, U, OneEighty);
    ASSERT_TRUE(compare());
}

TEST_F(ConnectorFixture, ytop_face_rotation_270) {
    expectedXLeft->setRow(0, getArrayOfColor(Blue));
    expectedZBack->setRow(0, getArrayOfColor(Red));
    expectedXRight->setRow(0, getArrayOfColor(Green));
    expectedZFront->setRow(0, getArrayOfColor(Orange));

    rubiks_cube_rotate(state, U, TwoSeventy);
    ASSERT_TRUE(compare());
}

TEST_F(ConnectorFixture, ybottom_face_rotation_90) {
    expectedXLeft->setRow(2, getArrayOfColor(Blue));
    expectedZBack->setRow(2, getArrayOfColor(Red));
    expectedXRight->setRow(2, getArrayOfColor(Green));
    expectedZFront->setRow(2, getArrayOfColor(Orange));

    rubiks_cube_rotate(state, D, Ninety);
    ASSERT_TRUE(compare());
}

TEST_F(ConnectorFixture, ybottom_face_rotation_180) {
    expectedXLeft->setRow(2, getArrayOfColor(Red));
    expectedZBack->setRow(2, getArrayOfColor(Green));
    expectedXRight->setRow(2, getArrayOfColor(Orange));
    expectedZFront->setRow(2, getArrayOfColor(Blue));

    rubiks_cube_rotate(state, D, OneEighty);
    ASSERT_TRUE(compare());
}

TEST_F(ConnectorFixture, ybottom_face_rotation_270) {
    expectedXLeft->setRow(2, getArrayOfColor(Green));
    expectedZBack->setRow(2, getArrayOfColor(Orange));
    expectedXRight->setRow(2, getArrayOfColor(Blue));
    expectedZFront->setRow(2, getArrayOfColor(Red));

    rubiks_cube_rotate(state, D, TwoSeventy);
    ASSERT_TRUE(compare());
}

TEST_F(ConnectorFixture, zfront_face_rotation_90) {
    expectedYTop->setRow(2, getArrayOfColor(Orange));
    expectedXRight->setCol(0, getArrayOfColor(White));
    expectedYBottom->setRow(0, getArrayOfColor(Red));
    expectedXLeft->setCol(2, getArrayOfColor(Yellow));

    rubiks_cube_rotate(state, F, Ninety);
    ASSERT_TRUE(compare());
}

TEST_F(ConnectorFixture, zfront_face_rotation_180) {
    expectedYTop->setRow(2, getArrayOfColor(Yellow));
    expectedXRight->setCol(0, getArrayOfColor(Orange));
    expectedYBottom->setRow(0, getArrayOfColor(White));
    expectedXLeft->setCol(2, getArrayOfColor(Red));

    rubiks_cube_rotate(state, F, OneEighty);
    ASSERT_TRUE(compare());
}

TEST_F(ConnectorFixture, zfront_face_rotation_270) {
    expectedYTop->setRow(2, getArrayOfColor(Red));
    expectedXRight->setCol(0, getArrayOfColor(Yellow));
    expectedYBottom->setRow(0, getArrayOfColor(Orange));
    expectedXLeft->setCol(2, getArrayOfColor(White));

    rubiks_cube_rotate(state, F, TwoSeventy);
    ASSERT_TRUE(compare());
}

TEST_F(ConnectorFixture, zback_face_rotation_90) {
    expectedYTop->setRow(0, getArrayOfColor(Red));
    expectedXLeft->setCol(0, getArrayOfColor(White));
    expectedYBottom->setRow(2, getArrayOfColor(Orange));
    expectedXRight->setCol(2, getArrayOfColor(Yellow));

    rubiks_cube_rotate(state, B, Ninety);
    ASSERT_TRUE(compare());
}

TEST_F(ConnectorFixture, zback_face_rotation_180) {
    expectedYTop->setRow(0, getArrayOfColor(Yellow));
    expectedXLeft->setCol(0, getArrayOfColor(Red));
    expectedYBottom->setRow(2, getArrayOfColor(White));
    expectedXRight->setCol(2, getArrayOfColor(Orange));

    rubiks_cube_rotate(state, B, OneEighty);
    ASSERT_TRUE(compare());
}

TEST_F(ConnectorFixture, zback_face_rotation_270) {
    expectedYTop->setRow(0, getArrayOfColor(Orange));
    expectedXLeft->setCol(0, getArrayOfColor(Yellow));
    expectedYBottom->setRow(2, getArrayOfColor(Red));
    expectedXRight->setCol(2, getArrayOfColor(White));

    rubiks_cube_rotate(state, B, TwoSeventy);
    ASSERT_TRUE(compare());
}

TEST_F(ConnectorFixture, x_slice_rotation_90) {
    expectedYTop->setCol(1, getArrayOfColor(Blue));
    expectedZFront->setCol(1, getArrayOfColor(White));
    expectedYBottom->setCol(1, getArrayOfColor(Green));
    expectedZBack->setCol(1, getArrayOfColor(Yellow));

    rubiks_cube_rotate(state, M, Ninety);
    ASSERT_TRUE(compare());
}

TEST_F(ConnectorFixture, x_slice_rotation_180) {
    expectedYTop->setCol(1, getArrayOfColor(Yellow));
    expectedZFront->setCol(1, getArrayOfColor(Blue));
    expectedYBottom->setCol(1, getArrayOfColor(White));
    expectedZBack->setCol(1, getArrayOfColor(Green));

    rubiks_cube_rotate(state, M, OneEighty);
    ASSERT_TRUE(compare());
}

TEST_F(ConnectorFixture, x_slice_rotation_270) {
    expectedYTop->setCol(1, getArrayOfColor(Green));
    expectedZFront->setCol(1, getArrayOfColor(Yellow));
    expectedYBottom->setCol(1, getArrayOfColor(Blue));
    expectedZBack->setCol(1, getArrayOfColor(White));

    rubiks_cube_rotate(state, M, TwoSeventy);
    ASSERT_TRUE(compare());
}

TEST_F(ConnectorFixture, y_slice_rotation_90) {
    expectedXLeft->setRow(1, getArrayOfColor(Blue));
    expectedZFront->setRow(1, getArrayOfColor(Orange));
    expectedXRight->setRow(1, getArrayOfColor(Green));
    expectedZBack->setRow(1, getArrayOfColor(Red));

    rubiks_cube_rotate(state, E, Ninety);
    ASSERT_TRUE(compare());
}

TEST_F(ConnectorFixture, y_slice_rotation_180) {
    expectedXLeft->setRow(1, getArrayOfColor(Red));
    expectedZFront->setRow(1, getArrayOfColor(Blue));
    expectedXRight->setRow(1, getArrayOfColor(Orange));
    expectedZBack->setRow(1, getArrayOfColor(Green));

    rubiks_cube_rotate(state, E, OneEighty);
    ASSERT_TRUE(compare());
}

TEST_F(ConnectorFixture, y_slice_rotation_270) {
    expectedXLeft->setRow(1, getArrayOfColor(Green));
    expectedZFront->setRow(1, getArrayOfColor(Red));
    expectedXRight->setRow(1, getArrayOfColor(Blue));
    expectedZBack->setRow(1, getArrayOfColor(Orange));

    rubiks_cube_rotate(state, E, TwoSeventy);
    ASSERT_TRUE(compare());
}

TEST_F(ConnectorFixture, z_slice_rotation_90) {
    expectedYTop->setRow(1, getArrayOfColor(Orange));
    expectedXRight->setCol(1, getArrayOfColor(White));
    expectedYBottom->setRow(1, getArrayOfColor(Red));
    expectedXLeft->setCol(1, getArrayOfColor(Yellow));

    rubiks_cube_rotate(state, S, Ninety);
    ASSERT_TRUE(compare());
}

TEST_F(ConnectorFixture, z_slice_rotation_180) {
    expectedYTop->setRow(1, getArrayOfColor(Yellow));
    expectedXRight->setCol(1, getArrayOfColor(Orange));
    expectedYBottom->setRow(1, getArrayOfColor(White));
    expectedXLeft->setCol(1, getArrayOfColor(Red));

    rubiks_cube_rotate(state, S, OneEighty);
    ASSERT_TRUE(compare());
}

TEST_F(ConnectorFixture, z_slice_rotation_270) {
    expectedYTop->setRow(1, getArrayOfColor(Red));
    expectedXRight->setCol(1, getArrayOfColor(Yellow));
    expectedYBottom->setRow(1, getArrayOfColor(Orange));
    expectedXLeft->setCol(1, getArrayOfColor(White));

    rubiks_cube_rotate(state, S, TwoSeventy);
    ASSERT_TRUE(compare());
}

void applyComboMoves(int*** state) {
    rubiks_cube_rotate(state, L, Ninety);
    rubiks_cube_rotate(state, D, Ninety);
    rubiks_cube_rotate(state, U, Ninety);
    rubiks_cube_rotate(state, F, OneEighty);
    rubiks_cube_rotate(state, B, TwoSeventy);
    rubiks_cube_rotate(state, R, OneEighty);
    rubiks_cube_rotate(state, M, Ninety);
    rubiks_cube_rotate(state, E, TwoSeventy);
    rubiks_cube_rotate(state, S, OneEighty);
}

TEST_F(ConnectorFixture, combination_of_rotations) {
    expectedXLeft->setRow(0, new int[N] {Yellow, Blue, White});
    expectedXLeft->setRow(1, new int[N] {Green, Yellow, Orange});
    expectedXLeft->setRow(2, new int[N] {Yellow, Green, Blue});

    expectedXRight->setRow(0, new int[N] {Blue, Blue, Green});
    expectedXRight->setRow(1, new int[N] {White, White, Red});
    expectedXRight->setRow(2, new int[N] {Blue, Green, Yellow});

    expectedYTop->setRow(0, new int[N] {Blue, Blue, White});
    expectedYTop->setRow(1, new int[N] {White, Green, Yellow});
    expectedYTop->setRow(2, new int[N] {Green, Yellow, Yellow});

    expectedYBottom->setRow(0, new int[N] {White, Orange, White});
    expectedYBottom->setRow(1, new int[N] {Yellow, Blue, White});
    expectedYBottom->setRow(2, new int[N] {Green, Red, Green});

    expectedZFront->setRow(0, getArrayOfColor(Orange));
    expectedZFront->setRow(1, new int[N] {Blue, Red, Orange});
    expectedZFront->setRow(2, new int[N] {Red, Green, Orange});

    expectedZBack->setRow(0, getArrayOfColor(Red));
    expectedZBack->setRow(1, new int[N] {Yellow, Orange, Red});
    expectedZBack->setRow(2, new int[N] {Orange, White, Red});

    applyComboMoves(state);
    ASSERT_TRUE(compare());
}

TEST_F(ConnectorFixture, undoing_moves_should_solve_cube) {
    applyComboMoves(state);

    // undoing combo moves above
    rubiks_cube_rotate(state, S, OneEighty);
    rubiks_cube_rotate(state, E, Ninety);
    rubiks_cube_rotate(state, M, TwoSeventy);
    rubiks_cube_rotate(state, R, OneEighty);
    rubiks_cube_rotate(state, B, Ninety);
    rubiks_cube_rotate(state, F, OneEighty);
    rubiks_cube_rotate(state, U, TwoSeventy);
    rubiks_cube_rotate(state, D, TwoSeventy);
    rubiks_cube_rotate(state, L, TwoSeventy);

    ASSERT_TRUE(compare());
}
