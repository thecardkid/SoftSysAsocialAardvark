#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/CubeFace.h"

const int N = 3;

using testing::Eq;

namespace {
class FaceFixture : public testing::Test {
public:
    CubeFace *testFace;
    int n;
    FaceFixture() {
        testFace = new CubeFace(CubeFace::White);
        testFace->setRow(0, new int[N] {CubeFace::Red, CubeFace::Red, CubeFace::Red});
        testFace->setRow(1, new int[N] {CubeFace::Orange, CubeFace::Orange, CubeFace::Orange});
    }
};
} // namespace

bool facesEqual(int** expected, int** actual) {
    for (int r=0; r < N; r++) {
        for (int c=0; c < N; c++) {
            if (expected[r][c] != actual[r][c]) return false;
        }
    }

    return true;
}

bool rowsEqual(int* expected, int* actual) {
    for (int i=0; i < N; i++) {
        if (expected[i] != actual[i]) return false;
    }

    return true;
}

TEST_F(FaceFixture, get_face) {
    int** expected = new int*[N];
    expected[0] = new int[N] {CubeFace::Red, CubeFace::Red, CubeFace::Red};
    expected[1] = new int[N] {CubeFace::Orange, CubeFace::Orange, CubeFace::Orange};
    expected[2] = new int[N] {CubeFace::White, CubeFace::White, CubeFace::White};

    ASSERT_TRUE(facesEqual(expected, testFace->getFace()));
}

TEST_F(FaceFixture, returned_face_is_copy_of_actual_cube_face) {
    int** expected = new int*[N];
    expected[0] = new int[N] {CubeFace::Red, CubeFace::Red, CubeFace::Red};
    expected[1] = new int[N] {CubeFace::Orange, CubeFace::Orange, CubeFace::Orange};
    expected[2] = new int[N] {CubeFace::White, CubeFace::White, CubeFace::White};

    int** returnedFace = testFace->getFace();
    returnedFace[0][0] = CubeFace::Yellow;
    ASSERT_TRUE(facesEqual(expected, testFace->getFace()));
}

TEST_F(FaceFixture, set_and_get_row) {
    int* expected = new int[N] {CubeFace::Blue, CubeFace::Yellow, CubeFace::Green};

    testFace->setRow(0, expected);
    ASSERT_TRUE(rowsEqual(expected, testFace->getRow(0)));
}

TEST_F(FaceFixture, returned_row_is_copy_of_actual_row) {
    int* expected = new int[N] {CubeFace::Red, CubeFace::Red, CubeFace::Red};

    int* returnedRow = testFace->getRow(0);
    returnedRow[0] = CubeFace::Yellow;
    ASSERT_TRUE(rowsEqual(expected, testFace->getRow(0)));
}

TEST_F(FaceFixture, invalid_row_index_returns_null) {
    ASSERT_EQ(NULL, testFace->getRow(-1));
    ASSERT_EQ(NULL, testFace->getRow(N));
}

TEST_F(FaceFixture, rotate_face_90) {
    int** expected = new int*[N];
    expected[0] = expected[1] = expected[2] =
        new int[N] {CubeFace::White, CubeFace::Orange, CubeFace::Red};

    testFace->rotateFaceClockwise(CubeFace::Ninety);
    ASSERT_TRUE(facesEqual(expected, testFace->getFace()));
}

TEST_F(FaceFixture, rotate_face_180) {
    int** expected = new int*[N];
    expected[0] = new int[N] {CubeFace::White, CubeFace::White, CubeFace::White};
    expected[1] = new int[N] {CubeFace::Orange, CubeFace::Orange, CubeFace::Orange};
    expected[2] = new int[N] {CubeFace::Red, CubeFace::Red, CubeFace::Red};

    testFace->rotateFaceClockwise(CubeFace::OneEighty);
    ASSERT_TRUE(facesEqual(expected, testFace->getFace()));
}

TEST_F(FaceFixture, rotate_face_270) {
    int** expected = new int*[N];
    expected[0] = expected[1] = expected[2] =
        new int[N] {CubeFace::Red, CubeFace::Orange, CubeFace::White};

    testFace->rotateFaceClockwise(CubeFace::TwoSeventy);
    ASSERT_TRUE(facesEqual(expected, testFace->getFace()));
}
