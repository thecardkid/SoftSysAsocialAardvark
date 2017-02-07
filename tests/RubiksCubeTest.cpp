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
        expectedXLeft = new CubeFace(CubeFace::Orange);
        expectedXRight = new CubeFace(CubeFace::Red);
        expectedYTop = new CubeFace(CubeFace::White);
        expectedYBottom = new CubeFace(CubeFace::Yellow);
        expectedZFront = new CubeFace(CubeFace::Green);
        expectedZBack = new CubeFace(CubeFace::Blue);
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

int* getArrayOfColor(CubeFace::Color color) {
    return new int[N] {color, color, color};
}

TEST_F(CubeFixture, scramble_returns_list_of_n_moves) {
    const int times = 8;
    std::vector<RubiksCube::Move> moves = testCube->scramble(8);

    ASSERT_EQ(times, moves.size());
    ASSERT_TRUE(!allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, xleft_face_rotation_90) {
    expectedYTop->setCol(0, getArrayOfColor(CubeFace::Blue));
    expectedZFront->setCol(0, getArrayOfColor(CubeFace::White));
    expectedYBottom->setCol(0, getArrayOfColor(CubeFace::Green));
    expectedZBack->setCol(2, getArrayOfColor(CubeFace::Yellow));

    testCube->rotate(RubiksCube::L, CubeFace::Ninety);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, xleft_face_rotation_180) {
    expectedYTop->setCol(0, getArrayOfColor(CubeFace::Yellow));
    expectedZFront->setCol(0, getArrayOfColor(CubeFace::Blue));
    expectedYBottom->setCol(0, getArrayOfColor(CubeFace::White));
    expectedZBack->setCol(2, getArrayOfColor(CubeFace::Green));

    testCube->rotate(RubiksCube::L, CubeFace::OneEighty);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, xleft_face_rotation_270) {
    expectedYTop->setCol(0, getArrayOfColor(CubeFace::Green));
    expectedZFront->setCol(0, getArrayOfColor(CubeFace::Yellow));
    expectedYBottom->setCol(0, getArrayOfColor(CubeFace::Blue));
    expectedZBack->setCol(2, getArrayOfColor(CubeFace::White));

    testCube->rotate(RubiksCube::L, CubeFace::TwoSeventy);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, xright_face_rotation_90) {
    expectedYTop->setCol(2, getArrayOfColor(CubeFace::Green));
    expectedZFront->setCol(2, getArrayOfColor(CubeFace::Yellow));
    expectedYBottom->setCol(2, getArrayOfColor(CubeFace::Blue));
    expectedZBack->setCol(0, getArrayOfColor(CubeFace::White));

    testCube->rotate(RubiksCube::R, CubeFace::Ninety);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, xright_face_rotation_180) {
    expectedYTop->setCol(2, getArrayOfColor(CubeFace::Yellow));
    expectedZFront->setCol(2, getArrayOfColor(CubeFace::Blue));
    expectedYBottom->setCol(2, getArrayOfColor(CubeFace::White));
    expectedZBack->setCol(0, getArrayOfColor(CubeFace::Green));

    testCube->rotate(RubiksCube::R, CubeFace::OneEighty);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, xright_face_rotation_270) {
    expectedYTop->setCol(2, getArrayOfColor(CubeFace::Blue));
    expectedZFront->setCol(2, getArrayOfColor(CubeFace::White));
    expectedYBottom->setCol(2, getArrayOfColor(CubeFace::Green));
    expectedZBack->setCol(0, getArrayOfColor(CubeFace::Yellow));

    testCube->rotate(RubiksCube::R, CubeFace::TwoSeventy);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, ytop_face_rotation_90) {
    expectedXLeft->setRow(0, getArrayOfColor(CubeFace::Green));
    expectedZBack->setRow(0, getArrayOfColor(CubeFace::Orange));
    expectedXRight->setRow(0, getArrayOfColor(CubeFace::Blue));
    expectedZFront->setRow(0, getArrayOfColor(CubeFace::Red));

    testCube->rotate(RubiksCube::U, CubeFace::Ninety);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, ytop_face_rotation_180) {
    expectedXLeft->setRow(0, getArrayOfColor(CubeFace::Red));
    expectedZBack->setRow(0, getArrayOfColor(CubeFace::Green));
    expectedXRight->setRow(0, getArrayOfColor(CubeFace::Orange));
    expectedZFront->setRow(0, getArrayOfColor(CubeFace::Blue));

    testCube->rotate(RubiksCube::U, CubeFace::OneEighty);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, ytop_face_rotation_270) {
    expectedXLeft->setRow(0, getArrayOfColor(CubeFace::Blue));
    expectedZBack->setRow(0, getArrayOfColor(CubeFace::Red));
    expectedXRight->setRow(0, getArrayOfColor(CubeFace::Green));
    expectedZFront->setRow(0, getArrayOfColor(CubeFace::Orange));

    testCube->rotate(RubiksCube::U, CubeFace::TwoSeventy);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, ybottom_face_rotation_90) {
    expectedXLeft->setRow(2, getArrayOfColor(CubeFace::Blue));
    expectedZBack->setRow(2, getArrayOfColor(CubeFace::Red));
    expectedXRight->setRow(2, getArrayOfColor(CubeFace::Green));
    expectedZFront->setRow(2, getArrayOfColor(CubeFace::Orange));

    testCube->rotate(RubiksCube::D, CubeFace::Ninety);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, ybottom_face_rotation_180) {
    expectedXLeft->setRow(2, getArrayOfColor(CubeFace::Red));
    expectedZBack->setRow(2, getArrayOfColor(CubeFace::Green));
    expectedXRight->setRow(2, getArrayOfColor(CubeFace::Orange));
    expectedZFront->setRow(2, getArrayOfColor(CubeFace::Blue));

    testCube->rotate(RubiksCube::D, CubeFace::OneEighty);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, ybottom_face_rotation_270) {
    expectedXLeft->setRow(2, getArrayOfColor(CubeFace::Green));
    expectedZBack->setRow(2, getArrayOfColor(CubeFace::Orange));
    expectedXRight->setRow(2, getArrayOfColor(CubeFace::Blue));
    expectedZFront->setRow(2, getArrayOfColor(CubeFace::Red));

    testCube->rotate(RubiksCube::D, CubeFace::TwoSeventy);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, zfront_face_rotation_90) {
    expectedYTop->setRow(2, getArrayOfColor(CubeFace::Orange));
    expectedXRight->setCol(0, getArrayOfColor(CubeFace::White));
    expectedYBottom->setRow(0, getArrayOfColor(CubeFace::Red));
    expectedXLeft->setCol(2, getArrayOfColor(CubeFace::Yellow));

    testCube->rotate(RubiksCube::F, CubeFace::Ninety);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, zfront_face_rotation_180) {
    expectedYTop->setRow(2, getArrayOfColor(CubeFace::Yellow));
    expectedXRight->setCol(0, getArrayOfColor(CubeFace::Orange));
    expectedYBottom->setRow(0, getArrayOfColor(CubeFace::White));
    expectedXLeft->setCol(2, getArrayOfColor(CubeFace::Red));

    testCube->rotate(RubiksCube::F, CubeFace::OneEighty);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, zfront_face_rotation_270) {
    expectedYTop->setRow(2, getArrayOfColor(CubeFace::Red));
    expectedXRight->setCol(0, getArrayOfColor(CubeFace::Yellow));
    expectedYBottom->setRow(0, getArrayOfColor(CubeFace::Orange));
    expectedXLeft->setCol(2, getArrayOfColor(CubeFace::White));

    testCube->rotate(RubiksCube::F, CubeFace::TwoSeventy);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, zback_face_rotation_90) {
    expectedYTop->setRow(0, getArrayOfColor(CubeFace::Red));
    expectedXLeft->setCol(0, getArrayOfColor(CubeFace::White));
    expectedYBottom->setRow(2, getArrayOfColor(CubeFace::Orange));
    expectedXRight->setCol(2, getArrayOfColor(CubeFace::Yellow));

    testCube->rotate(RubiksCube::B, CubeFace::Ninety);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, zback_face_rotation_180) {
    expectedYTop->setRow(0, getArrayOfColor(CubeFace::Yellow));
    expectedXLeft->setCol(0, getArrayOfColor(CubeFace::Red));
    expectedYBottom->setRow(2, getArrayOfColor(CubeFace::White));
    expectedXRight->setCol(2, getArrayOfColor(CubeFace::Orange));

    testCube->rotate(RubiksCube::B, CubeFace::OneEighty);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, zback_face_rotation_270) {
    expectedYTop->setRow(0, getArrayOfColor(CubeFace::Orange));
    expectedXLeft->setCol(0, getArrayOfColor(CubeFace::Yellow));
    expectedYBottom->setRow(2, getArrayOfColor(CubeFace::Red));
    expectedXRight->setCol(2, getArrayOfColor(CubeFace::White));

    testCube->rotate(RubiksCube::B, CubeFace::TwoSeventy);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, x_slice_rotation_90) {
    expectedYTop->setCol(1, getArrayOfColor(CubeFace::Blue));
    expectedZFront->setCol(1, getArrayOfColor(CubeFace::White));
    expectedYBottom->setCol(1, getArrayOfColor(CubeFace::Green));
    expectedZBack->setCol(1, getArrayOfColor(CubeFace::Yellow));

    testCube->rotate(RubiksCube::M, CubeFace::Ninety);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, x_slice_rotation_180) {
    expectedYTop->setCol(1, getArrayOfColor(CubeFace::Yellow));
    expectedZFront->setCol(1, getArrayOfColor(CubeFace::Blue));
    expectedYBottom->setCol(1, getArrayOfColor(CubeFace::White));
    expectedZBack->setCol(1, getArrayOfColor(CubeFace::Green));

    testCube->rotate(RubiksCube::M, CubeFace::OneEighty);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, x_slice_rotation_270) {
    expectedYTop->setCol(1, getArrayOfColor(CubeFace::Green));
    expectedZFront->setCol(1, getArrayOfColor(CubeFace::Yellow));
    expectedYBottom->setCol(1, getArrayOfColor(CubeFace::Blue));
    expectedZBack->setCol(1, getArrayOfColor(CubeFace::White));

    testCube->rotate(RubiksCube::M, CubeFace::TwoSeventy);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, y_slice_rotation_90) {
    expectedXLeft->setRow(1, getArrayOfColor(CubeFace::Blue));
    expectedZFront->setRow(1, getArrayOfColor(CubeFace::Orange));
    expectedXRight->setRow(1, getArrayOfColor(CubeFace::Green));
    expectedZBack->setRow(1, getArrayOfColor(CubeFace::Red));

    testCube->rotate(RubiksCube::E, CubeFace::Ninety);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, y_slice_rotation_180) {
    expectedXLeft->setRow(1, getArrayOfColor(CubeFace::Red));
    expectedZFront->setRow(1, getArrayOfColor(CubeFace::Blue));
    expectedXRight->setRow(1, getArrayOfColor(CubeFace::Orange));
    expectedZBack->setRow(1, getArrayOfColor(CubeFace::Green));

    testCube->rotate(RubiksCube::E, CubeFace::OneEighty);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, y_slice_rotation_270) {
    expectedXLeft->setRow(1, getArrayOfColor(CubeFace::Green));
    expectedZFront->setRow(1, getArrayOfColor(CubeFace::Red));
    expectedXRight->setRow(1, getArrayOfColor(CubeFace::Blue));
    expectedZBack->setRow(1, getArrayOfColor(CubeFace::Orange));

    testCube->rotate(RubiksCube::E, CubeFace::TwoSeventy);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, z_slice_rotation_90) {
    expectedYTop->setRow(1, getArrayOfColor(CubeFace::Orange));
    expectedXRight->setCol(1, getArrayOfColor(CubeFace::White));
    expectedYBottom->setRow(1, getArrayOfColor(CubeFace::Red));
    expectedXLeft->setCol(1, getArrayOfColor(CubeFace::Yellow));

    testCube->rotate(RubiksCube::S, CubeFace::Ninety);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, z_slice_rotation_180) {
    expectedYTop->setRow(1, getArrayOfColor(CubeFace::Yellow));
    expectedXRight->setCol(1, getArrayOfColor(CubeFace::Orange));
    expectedYBottom->setRow(1, getArrayOfColor(CubeFace::White));
    expectedXLeft->setCol(1, getArrayOfColor(CubeFace::Red));

    testCube->rotate(RubiksCube::S, CubeFace::OneEighty);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, z_slice_rotation_270) {
    expectedYTop->setRow(1, getArrayOfColor(CubeFace::Red));
    expectedXRight->setCol(1, getArrayOfColor(CubeFace::Yellow));
    expectedYBottom->setRow(1, getArrayOfColor(CubeFace::Orange));
    expectedXLeft->setCol(1, getArrayOfColor(CubeFace::White));

    testCube->rotate(RubiksCube::S, CubeFace::TwoSeventy);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

void applyComboMoves(RubiksCube *testCube) {
    testCube->rotate(RubiksCube::L, CubeFace::Ninety);
    testCube->rotate(RubiksCube::D, CubeFace::Ninety);
    testCube->rotate(RubiksCube::U, CubeFace::Ninety);
    testCube->rotate(RubiksCube::F, CubeFace::OneEighty);
    testCube->rotate(RubiksCube::B, CubeFace::TwoSeventy);
    testCube->rotate(RubiksCube::R, CubeFace::OneEighty);
    testCube->rotate(RubiksCube::M, CubeFace::Ninety);
    testCube->rotate(RubiksCube::E, CubeFace::TwoSeventy);
    testCube->rotate(RubiksCube::S, CubeFace::OneEighty);
}

TEST_F(CubeFixture, combination_of_rotations) {
    expectedXLeft->setRow(0, new int[N] {CubeFace::Yellow, CubeFace::Blue, CubeFace::White});
    expectedXLeft->setRow(1, new int[N] {CubeFace::Green, CubeFace::Yellow, CubeFace::Orange});
    expectedXLeft->setRow(2, new int[N] {CubeFace::Yellow, CubeFace::Green, CubeFace::Blue});

    expectedXRight->setRow(0, new int[N] {CubeFace::Blue, CubeFace::Blue, CubeFace::Green});
    expectedXRight->setRow(1, new int[N] {CubeFace::White, CubeFace::White, CubeFace::Red});
    expectedXRight->setRow(2, new int[N] {CubeFace::Blue, CubeFace::Green, CubeFace::Yellow});

    expectedYTop->setRow(0, new int[N] {CubeFace::Blue, CubeFace::Blue, CubeFace::White});
    expectedYTop->setRow(1, new int[N] {CubeFace::White, CubeFace::Green, CubeFace::Yellow});
    expectedYTop->setRow(2, new int[N] {CubeFace::Green, CubeFace::Yellow, CubeFace::Yellow});

    expectedYBottom->setRow(0, new int[N] {CubeFace::White, CubeFace::Orange, CubeFace::White});
    expectedYBottom->setRow(1, new int[N] {CubeFace::Yellow, CubeFace::Blue, CubeFace::White});
    expectedYBottom->setRow(2, new int[N] {CubeFace::Green, CubeFace::Red, CubeFace::Green});

    expectedZFront->setRow(0, getArrayOfColor(CubeFace::Orange));
    expectedZFront->setRow(1, new int[N] {CubeFace::Blue, CubeFace::Red, CubeFace::Orange});
    expectedZFront->setRow(2, new int[N] {CubeFace::Red, CubeFace::Green, CubeFace::Orange});

    expectedZBack->setRow(0, getArrayOfColor(CubeFace::Red));
    expectedZBack->setRow(1, new int[N] {CubeFace::Yellow, CubeFace::Orange, CubeFace::Red});
    expectedZBack->setRow(2, new int[N] {CubeFace::Orange, CubeFace::White, CubeFace::Red});

    applyComboMoves(testCube);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, undoing_moves_should_solve_cube) {
    applyComboMoves(testCube);

    // undoing combo moves above
    testCube->rotate(RubiksCube::S, CubeFace::OneEighty);
    testCube->rotate(RubiksCube::E, CubeFace::Ninety);
    testCube->rotate(RubiksCube::M, CubeFace::TwoSeventy);
    testCube->rotate(RubiksCube::R, CubeFace::OneEighty);
    testCube->rotate(RubiksCube::B, CubeFace::Ninety);
    testCube->rotate(RubiksCube::F, CubeFace::OneEighty);
    testCube->rotate(RubiksCube::U, CubeFace::TwoSeventy);
    testCube->rotate(RubiksCube::D, CubeFace::TwoSeventy);
    testCube->rotate(RubiksCube::L, CubeFace::TwoSeventy);

    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

