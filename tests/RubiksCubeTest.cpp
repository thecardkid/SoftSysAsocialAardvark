#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/RubiksCube.h"

const int N = 3;

using testing::Eq;

namespace {
class CubeFixture : public testing::Test {
public:
    RubiksCube *testCube;
    CubeFace *expectedXLeft, *expectedXRight, *expectedYTop, *expectedYBottom, *expectedZFront, *expectedZBack;
    CubeFixture() {
        testCube = new RubiksCube();
        expectedXLeft = new CubeFace(CubeFace::Green);
        expectedXRight = new CubeFace(CubeFace::Blue);
        expectedYTop = new CubeFace(CubeFace::White);
        expectedYBottom = new CubeFace(CubeFace::Yellow);
        expectedZFront = new CubeFace(CubeFace::Red);
        expectedZBack = new CubeFace(CubeFace::Orange);
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

TEST_F(CubeFixture, xleft_face_rotation) {
    expectedYTop->setCol(0, getArrayOfColor(CubeFace::Orange));
    expectedZFront->setCol(0, getArrayOfColor(CubeFace::White));
    expectedYBottom->setCol(0, getArrayOfColor(CubeFace::Red));
    expectedZBack->setCol(0, getArrayOfColor(CubeFace::Yellow));

    testCube->rotate(RubiksCube::L, CubeFace::Ninety);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, xright_face_rotation) {
    expectedYTop->setCol(2, getArrayOfColor(CubeFace::Red));
    expectedZFront->setCol(2, getArrayOfColor(CubeFace::Yellow));
    expectedYBottom->setCol(2, getArrayOfColor(CubeFace::Orange));
    expectedZBack->setCol(2, getArrayOfColor(CubeFace::White));

    testCube->rotate(RubiksCube::R, CubeFace::Ninety);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, ytop_face_rotation) {
    expectedXLeft->setRow(0, getArrayOfColor(CubeFace::Red));
    expectedZBack->setRow(0, getArrayOfColor(CubeFace::Green));
    expectedXRight->setRow(0, getArrayOfColor(CubeFace::Orange));
    expectedZFront->setRow(0, getArrayOfColor(CubeFace::Blue));

    testCube->rotate(RubiksCube::U, CubeFace::Ninety);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, ybottom_face_rotation) {
    expectedXLeft->setRow(2, getArrayOfColor(CubeFace::Orange));
    expectedZBack->setRow(2, getArrayOfColor(CubeFace::Blue));
    expectedXRight->setRow(2, getArrayOfColor(CubeFace::Red));
    expectedZFront->setRow(2, getArrayOfColor(CubeFace::Green));

    testCube->rotate(RubiksCube::D, CubeFace::Ninety);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, zfront_face_rotation) {
    expectedYTop->setRow(2, getArrayOfColor(CubeFace::Green));
    expectedXRight->setCol(0, getArrayOfColor(CubeFace::White));
    expectedYBottom->setRow(0, getArrayOfColor(CubeFace::Blue));
    expectedXLeft->setCol(2, getArrayOfColor(CubeFace::Yellow));

    testCube->rotate(RubiksCube::F, CubeFace::Ninety);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, zback_face_rotation) {
    expectedYTop->setRow(0, getArrayOfColor(CubeFace::Blue));
    expectedXLeft->setCol(0, getArrayOfColor(CubeFace::White));
    expectedYBottom->setRow(2, getArrayOfColor(CubeFace::Green));
    expectedXRight->setCol(2, getArrayOfColor(CubeFace::Yellow));

    testCube->rotate(RubiksCube::B, CubeFace::Ninety);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, ytop_180_rotation) {
    expectedXLeft->setRow(0, getArrayOfColor(CubeFace::Blue));
    expectedXRight->setRow(0, getArrayOfColor(CubeFace::Green));
    expectedZFront->setRow(0, getArrayOfColor(CubeFace::Orange));
    expectedZBack->setRow(0, getArrayOfColor(CubeFace::Red));

    testCube->rotate(RubiksCube::U, CubeFace::OneEighty);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, x_slice_rotation) {
    expectedYTop->setCol(1, getArrayOfColor(CubeFace::Orange));
    expectedZFront->setCol(1, getArrayOfColor(CubeFace::White));
    expectedYBottom->setCol(1, getArrayOfColor(CubeFace::Red));
    expectedZBack->setCol(1, getArrayOfColor(CubeFace::Yellow));

    testCube->rotate(RubiksCube::M, CubeFace::Ninety);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, y_slice_rotation) {
    expectedXLeft->setRow(1, getArrayOfColor(CubeFace::Orange));
    expectedZFront->setRow(1, getArrayOfColor(CubeFace::Green));
    expectedXRight->setRow(1, getArrayOfColor(CubeFace::Red));
    expectedZBack->setRow(1, getArrayOfColor(CubeFace::Blue));

    testCube->rotate(RubiksCube::E, CubeFace::Ninety);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, z_slice_rotation) {
    expectedYTop->setRow(1, getArrayOfColor(CubeFace::Green));
    expectedXRight->setCol(1, getArrayOfColor(CubeFace::White));
    expectedYBottom->setRow(1, getArrayOfColor(CubeFace::Blue));
    expectedXLeft->setCol(1, getArrayOfColor(CubeFace::Yellow));

    testCube->rotate(RubiksCube::S, CubeFace::Ninety);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}

TEST_F(CubeFixture, x_slice_rotation_180) {
    expectedYTop->setCol(1, getArrayOfColor(CubeFace::Yellow));
    expectedZFront->setCol(1, getArrayOfColor(CubeFace::Orange));
    expectedYBottom->setCol(1, getArrayOfColor(CubeFace::White));
    expectedZBack->setCol(1, getArrayOfColor(CubeFace::Red));

    testCube->rotate(RubiksCube::M, CubeFace::OneEighty);
    ASSERT_TRUE(allFacesEqual(expectedXLeft, expectedXRight, expectedYTop, expectedYBottom, expectedZFront, expectedZBack, testCube->getState()));
}
