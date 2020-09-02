#include <gtest/gtest.h>

extern "C" {
#include "vector.h"
}

class ResizeTest : public ::testing::Test {
protected:
    void SetUp() override {
        vector = std_vector_create(sizeof(int));
    }

    void TearDown() override {
        std_vector_destroy(&vector);
    }

    StdVector vector;
};

TEST_F(ResizeTest, NullObject) {
    std_vector_reserve(NULL, 0);
}

TEST_F(ResizeTest, SizeEqualZero) {
    std_vector_reserve(vector, 0);
    EXPECT_EQ(0, std_vector_size(vector));
    EXPECT_EQ(0, std_vector_capacity(vector));
}

TEST_F(ResizeTest, EmptyVector) {
    int size = 10;
    std_vector_reserve(vector, size);
    EXPECT_EQ(0, std_vector_size(vector));
    EXPECT_EQ(size, std_vector_capacity(vector));
}

TEST_F(ResizeTest, VectorLessThanCapacity) {
    int size = 10;
    int value = 10;
    std_vector_push_back(vector, &value);
    std_vector_reserve(vector, size);
    EXPECT_EQ(1, std_vector_size(vector));
    EXPECT_EQ(STD_VECTOR_BLOCK_SIZE, std_vector_capacity(vector));
}

TEST_F(ResizeTest, GreaterThanCapacity) {
    int size = STD_VECTOR_BLOCK_SIZE + 10;
    int value = 10;
    std_vector_push_back(vector, &value);
    std_vector_reserve(vector, size);
    EXPECT_EQ(1, std_vector_size(vector));
    EXPECT_EQ(size, std_vector_capacity(vector));
}
