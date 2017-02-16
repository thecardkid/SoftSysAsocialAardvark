#include <gtest/gtest.h>
#include "../src/RubiksCube.h"

const int N = 3;

namespace {
class CubeFixture : public testing::Test {
public:
    RubiksCube *testCube;
    CubeFace *expectedXLeft, *expectedXRight, *expectedYTop, *expectedYBottom, *expectedZFront, *expectedZBack;
    CubeFixture() {
        testCube = new RubiksCube();
        expectedXLeft = new CubeFace(Orange);
        expectedXRight = new CubeFace(Red);
        expectedYTop = new CubeFace(White);
        expectedYBottom = new CubeFace(Yellow);
        expectedZFront = new CubeFace(Green);
        expectedZBack = new CubeFace(Blue);
    }
};
} // namespace

bool areFacesEqual(int** expected, int** actual) {
    for (int r=0; r < N; r++) {
        for (int c=0; c < N; c++) {
            if (expected[r][c] != actual[r][c]) return false;
        }
    }

    return true;
}

bool allFacesEqual(CubeFace* expectedXLeft, CubeFace* expectedXRight, CubeFace* expectedYTop,
    CubeFace* expectedYBottom, CubeFace* expectedZFront, CubeFace* expectedZBack, int*** actualCube) {
    return areFacesEqual(expectedXLeft->getFace(), actualCube[0]) &&
           areFacesEqual(expectedXRight->getFace(), actualCube[1]) &&
           areFacesEqual(expectedYTop->getFace(), actualCube[2]) &&
           areFacesEqual(expectedYBottom->getFace(), actualCube[3]) &&
           areFacesEqual(expectedZFront->getFace(), actualCube[4]) &&
           areFacesEqual(expectedZBack->getFace(), actualCube[5]);
}

int* getArrayOfColor(Color color) {
    return new int[N] {color, color, color};
}

TEST_F(CubeFixture, scramble_returns_list_of_n_moves) {
    const int times = 8;
    std::vector<RubiksCube::Move> moves = testCube->scramble(8);

    ASSERT_EQ(times, moves.size());
    ASSERT_TRUE(!allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, xleft_face_rotation_90) {
    expectedYTop->setCol(0, getArrayOfColor(Blue));
    expectedZFront->setCol(0, getArrayOfColor(White));
    expectedYBottom->setCol(0, getArrayOfColor(Green));
    expectedZBack->setCol(2, getArrayOfColor(Yellow));

    testCube->rotate(L, Ninety);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, xleft_face_rotation_180) {
    expectedYTop->setCol(0, getArrayOfColor(Yellow));
    expectedZFront->setCol(0, getArrayOfColor(Blue));
    expectedYBottom->setCol(0, getArrayOfColor(White));
    expectedZBack->setCol(2, getArrayOfColor(Green));

    testCube->rotate(L, OneEighty);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, xleft_face_rotation_270) {
    expectedYTop->setCol(0, getArrayOfColor(Green));
    expectedZFront->setCol(0, getArrayOfColor(Yellow));
    expectedYBottom->setCol(0, getArrayOfColor(Blue));
    expectedZBack->setCol(2, getArrayOfColor(White));

    testCube->rotate(L, TwoSeventy);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, xright_face_rotation_90) {
    expectedYTop->setCol(2, getArrayOfColor(Green));
    expectedZFront->setCol(2, getArrayOfColor(Yellow));
    expectedYBottom->setCol(2, getArrayOfColor(Blue));
    expectedZBack->setCol(0, getArrayOfColor(White));

    testCube->rotate(R, Ninety);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, xright_face_rotation_180) {
    expectedYTop->setCol(2, getArrayOfColor(Yellow));
    expectedZFront->setCol(2, getArrayOfColor(Blue));
    expectedYBottom->setCol(2, getArrayOfColor(White));
    expectedZBack->setCol(0, getArrayOfColor(Green));

    testCube->rotate(R, OneEighty);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, xright_face_rotation_270) {
    expectedYTop->setCol(2, getArrayOfColor(Blue));
    expectedZFront->setCol(2, getArrayOfColor(White));
    expectedYBottom->setCol(2, getArrayOfColor(Green));
    expectedZBack->setCol(0, getArrayOfColor(Yellow));

    testCube->rotate(R, TwoSeventy);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, ytop_face_rotation_90) {
    expectedXLeft->setRow(0, getArrayOfColor(Green));
    expectedZBack->setRow(0, getArrayOfColor(Orange));
    expectedXRight->setRow(0, getArrayOfColor(Blue));
    expectedZFront->setRow(0, getArrayOfColor(Red));

    testCube->rotate(U, Ninety);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, ytop_face_rotation_180) {
    expectedXLeft->setRow(0, getArrayOfColor(Red));
    expectedZBack->setRow(0, getArrayOfColor(Green));
    expectedXRight->setRow(0, getArrayOfColor(Orange));
    expectedZFront->setRow(0, getArrayOfColor(Blue));

    testCube->rotate(U, OneEighty);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, ytop_face_rotation_270) {
    expectedXLeft->setRow(0, getArrayOfColor(Blue));
    expectedZBack->setRow(0, getArrayOfColor(Red));
    expectedXRight->setRow(0, getArrayOfColor(Green));
    expectedZFront->setRow(0, getArrayOfColor(Orange));

    testCube->rotate(U, TwoSeventy);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, ybottom_face_rotation_90) {
    expectedXLeft->setRow(2, getArrayOfColor(Blue));
    expectedZBack->setRow(2, getArrayOfColor(Red));
    expectedXRight->setRow(2, getArrayOfColor(Green));
    expectedZFront->setRow(2, getArrayOfColor(Orange));

    testCube->rotate(D, Ninety);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, ybottom_face_rotation_180) {
    expectedXLeft->setRow(2, getArrayOfColor(Red));
    expectedZBack->setRow(2, getArrayOfColor(Green));
    expectedXRight->setRow(2, getArrayOfColor(Orange));
    expectedZFront->setRow(2, getArrayOfColor(Blue));

    testCube->rotate(D, OneEighty);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, ybottom_face_rotation_270) {
    expectedXLeft->setRow(2, getArrayOfColor(Green));
    expectedZBack->setRow(2, getArrayOfColor(Orange));
    expectedXRight->setRow(2, getArrayOfColor(Blue));
    expectedZFront->setRow(2, getArrayOfColor(Red));

    testCube->rotate(D, TwoSeventy);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, zfront_face_rotation_90) {
    expectedYTop->setRow(2, getArrayOfColor(Orange));
    expectedXRight->setCol(0, getArrayOfColor(White));
    expectedYBottom->setRow(0, getArrayOfColor(Red));
    expectedXLeft->setCol(2, getArrayOfColor(Yellow));

    testCube->rotate(F, Ninety);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, zfront_face_rotation_180) {
    expectedYTop->setRow(2, getArrayOfColor(Yellow));
    expectedXRight->setCol(0, getArrayOfColor(Orange));
    expectedYBottom->setRow(0, getArrayOfColor(White));
    expectedXLeft->setCol(2, getArrayOfColor(Red));

    testCube->rotate(F, OneEighty);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, zfront_face_rotation_270) {
    expectedYTop->setRow(2, getArrayOfColor(Red));
    expectedXRight->setCol(0, getArrayOfColor(Yellow));
    expectedYBottom->setRow(0, getArrayOfColor(Orange));
    expectedXLeft->setCol(2, getArrayOfColor(White));

    testCube->rotate(F, TwoSeventy);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, zback_face_rotation_90) {
    expectedYTop->setRow(0, getArrayOfColor(Red));
    expectedXLeft->setCol(0, getArrayOfColor(White));
    expectedYBottom->setRow(2, getArrayOfColor(Orange));
    expectedXRight->setCol(2, getArrayOfColor(Yellow));

    testCube->rotate(B, Ninety);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, zback_face_rotation_180) {
    expectedYTop->setRow(0, getArrayOfColor(Yellow));
    expectedXLeft->setCol(0, getArrayOfColor(Red));
    expectedYBottom->setRow(2, getArrayOfColor(White));
    expectedXRight->setCol(2, getArrayOfColor(Orange));

    testCube->rotate(B, OneEighty);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, zback_face_rotation_270) {
    expectedYTop->setRow(0, getArrayOfColor(Orange));
    expectedXLeft->setCol(0, getArrayOfColor(Yellow));
    expectedYBottom->setRow(2, getArrayOfColor(Red));
    expectedXRight->setCol(2, getArrayOfColor(White));

    testCube->rotate(B, TwoSeventy);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, x_slice_rotation_90) {
    expectedYTop->setCol(1, getArrayOfColor(Blue));
    expectedZFront->setCol(1, getArrayOfColor(White));
    expectedYBottom->setCol(1, getArrayOfColor(Green));
    expectedZBack->setCol(1, getArrayOfColor(Yellow));

    testCube->rotate(M, Ninety);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, x_slice_rotation_180) {
    expectedYTop->setCol(1, getArrayOfColor(Yellow));
    expectedZFront->setCol(1, getArrayOfColor(Blue));
    expectedYBottom->setCol(1, getArrayOfColor(White));
    expectedZBack->setCol(1, getArrayOfColor(Green));

    testCube->rotate(M, OneEighty);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, x_slice_rotation_270) {
    expectedYTop->setCol(1, getArrayOfColor(Green));
    expectedZFront->setCol(1, getArrayOfColor(Yellow));
    expectedYBottom->setCol(1, getArrayOfColor(Blue));
    expectedZBack->setCol(1, getArrayOfColor(White));

    testCube->rotate(M, TwoSeventy);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, y_slice_rotation_90) {
    expectedXLeft->setRow(1, getArrayOfColor(Blue));
    expectedZFront->setRow(1, getArrayOfColor(Orange));
    expectedXRight->setRow(1, getArrayOfColor(Green));
    expectedZBack->setRow(1, getArrayOfColor(Red));

    testCube->rotate(E, Ninety);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, y_slice_rotation_180) {
    expectedXLeft->setRow(1, getArrayOfColor(Red));
    expectedZFront->setRow(1, getArrayOfColor(Blue));
    expectedXRight->setRow(1, getArrayOfColor(Orange));
    expectedZBack->setRow(1, getArrayOfColor(Green));

    testCube->rotate(E, OneEighty);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, y_slice_rotation_270) {
    expectedXLeft->setRow(1, getArrayOfColor(Green));
    expectedZFront->setRow(1, getArrayOfColor(Red));
    expectedXRight->setRow(1, getArrayOfColor(Blue));
    expectedZBack->setRow(1, getArrayOfColor(Orange));

    testCube->rotate(E, TwoSeventy);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, z_slice_rotation_90) {
    expectedYTop->setRow(1, getArrayOfColor(Orange));
    expectedXRight->setCol(1, getArrayOfColor(White));
    expectedYBottom->setRow(1, getArrayOfColor(Red));
    expectedXLeft->setCol(1, getArrayOfColor(Yellow));

    testCube->rotate(S, Ninety);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, z_slice_rotation_180) {
    expectedYTop->setRow(1, getArrayOfColor(Yellow));
    expectedXRight->setCol(1, getArrayOfColor(Orange));
    expectedYBottom->setRow(1, getArrayOfColor(White));
    expectedXLeft->setCol(1, getArrayOfColor(Red));

    testCube->rotate(S, OneEighty);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, z_slice_rotation_270) {
    expectedYTop->setRow(1, getArrayOfColor(Red));
    expectedXRight->setCol(1, getArrayOfColor(Yellow));
    expectedYBottom->setRow(1, getArrayOfColor(Orange));
    expectedXLeft->setCol(1, getArrayOfColor(White));

    testCube->rotate(S, TwoSeventy);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

void applyComboMoves(RubiksCube *testCube) {
    testCube->rotate(L, Ninety);
    testCube->rotate(D, Ninety);
    testCube->rotate(U, Ninety);
    testCube->rotate(F, OneEighty);
    testCube->rotate(B, TwoSeventy);
    testCube->rotate(R, OneEighty);
    testCube->rotate(M, Ninety);
    testCube->rotate(E, TwoSeventy);
    testCube->rotate(S, OneEighty);
}

TEST_F(CubeFixture, combination_of_rotations) {
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

    applyComboMoves(testCube);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, undoing_moves_should_solve_cube) {
    applyComboMoves(testCube);

    // undoing combo moves above
    testCube->rotate(S, OneEighty);
    testCube->rotate(E, Ninety);
    testCube->rotate(M, TwoSeventy);
    testCube->rotate(R, OneEighty);
    testCube->rotate(B, Ninety);
    testCube->rotate(F, OneEighty);
    testCube->rotate(U, TwoSeventy);
    testCube->rotate(D, TwoSeventy);
    testCube->rotate(L, TwoSeventy);

    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

