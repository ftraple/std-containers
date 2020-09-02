#include <gtest/gtest.h>

extern "C" {
#include "vector.h"
}

class ClearTest : public ::testing::Test {
protected:
    void SetUp() override {
        vector = std_vector_create(sizeof(int));
    }

    void TearDown() override {
        std_vector_destroy(&vector);
    }

    StdVector vector;
};

TEST_F(ClearTest, NullObject) {
    std_vector_clear(NULL);
    EXPECT_EQ(0, std_vector_size(vector));
    EXPECT_EQ(0, std_vector_capacity(vector));
}

TEST_F(ClearTest, EmptyVector) {
    std_vector_clear(vector);
    EXPECT_EQ(0, std_vector_size(vector));
    EXPECT_EQ(0, std_vector_capacity(vector));
}

TEST_F(ClearTest, VectorGreaterThanZero) {
    int value = 10;
    std_vector_push_back(vector, &value);
    std_vector_clear(vector);
    EXPECT_EQ(0, std_vector_size(vector));
    EXPECT_EQ(STD_VECTOR_BLOCK_SIZE, std_vector_capacity(vector));
}

