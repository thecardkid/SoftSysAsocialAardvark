#include <gtest/gtest.h>
#include "../src/CubeFace.h"
#include "Utils.h"

const int N = 3;

namespace {
class FaceFixture : public testing::Test {
public:
    CubeFace *testFace;
    FaceFixture() {
        testFace = new CubeFace(White);
        testFace->setRow(0, new int[N] {Red, Red, Red});
        testFace->setRow(1, new int[N] {Orange, Orange, Orange});
    }
};
} // namespace

TEST_F(FaceFixture, get_face) {
    int** expected = new int*[N];
    expected[0] = new int[N] {Red, Red, Red};
    expected[1] = new int[N] {Orange, Orange, Orange};
    expected[2] = new int[N] {White, White, White};

    ASSERT_TRUE(facesEqual(expected, testFace->getFace()));
}

TEST_F(FaceFixture, returned_face_is_copy_of_actual_cube_face) {
    int** expected = new int*[N];
    expected[0] = new int[N] {Red, Red, Red};
    expected[1] = new int[N] {Orange, Orange, Orange};
    expected[2] = new int[N] {White, White, White};

    int** returnedFace = testFace->getFace();
    returnedFace[0][0] = Yellow;
    ASSERT_TRUE(facesEqual(expected, testFace->getFace()));
}

TEST_F(FaceFixture, set_and_get_row) {
    int* expected = new int[N] {Blue, Yellow, Green};

    testFace->setRow(0, expected);
    ASSERT_TRUE(rowsEqual(expected, testFace->getRow(0)));
}

TEST_F(FaceFixture, returned_row_is_copy_of_actual_row) {
    int* expected = new int[N] {Red, Red, Red};

    int* returnedRow = testFace->getRow(0);
    returnedRow[0] = Yellow;
    ASSERT_TRUE(rowsEqual(expected, testFace->getRow(0)));
}

TEST_F(FaceFixture, invalid_row_index_returns_null) {
    ASSERT_EQ(NULL, testFace->getRow(-1));
    ASSERT_EQ(NULL, testFace->getRow(N));
}

TEST_F(FaceFixture, set_and_get_cols) {
    int* expected = new int[N] {Blue, Yellow, Red};

    testFace->setCol(0, expected);
    ASSERT_TRUE(colsEqual(expected, testFace->getCol(0)));
}

TEST_F(FaceFixture, returned_col_is_copy_of_actual_col) {
    int* expected = new int[N] {Red, Orange, White};

    int* returnedCol = testFace->getCol(0);
    returnedCol[0] = Yellow;
    ASSERT_TRUE(colsEqual(expected, testFace->getCol(0)));
}

TEST_F(FaceFixture, invalid_col_index_returns_null) {
    ASSERT_EQ(NULL, testFace->getCol(-1));
    ASSERT_EQ(NULL, testFace->getCol(N));
}

TEST_F(FaceFixture, rotate_face_90) {
    int** expected = new int*[N];
    expected[0] = expected[1] = expected[2] =
        new int[N] {White, Orange, Red};

    testFace->rotateFaceClockwise(Ninety);
    ASSERT_TRUE(facesEqual(expected, testFace->getFace()));
}

TEST_F(FaceFixture, rotate_face_180) {
    int** expected = new int*[N];
    expected[0] = new int[N] {White, White, White};
    expected[1] = new int[N] {Orange, Orange, Orange};
    expected[2] = new int[N] {Red, Red, Red};

    testFace->rotateFaceClockwise(OneEighty);
    ASSERT_TRUE(facesEqual(expected, testFace->getFace()));
}

TEST_F(FaceFixture, rotate_face_270) {
    int** expected = new int*[N];
    expected[0] = expected[1] = expected[2] =
        new int[N] {Red, Orange, White};

    testFace->rotateFaceClockwise(TwoSeventy);
    ASSERT_TRUE(facesEqual(expected, testFace->getFace()));
}
