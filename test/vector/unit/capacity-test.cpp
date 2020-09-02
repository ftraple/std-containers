#include <gtest/gtest.h>

extern "C" {
#include "vector.h"
}

class CapacityTest : public ::testing::Test {
protected:
    void SetUp() override {
        vector = std_vector_create(sizeof(int));
    }

    void TearDown() override {
        std_vector_destroy(&vector);
    }

    StdVector vector;
};

TEST_F(CapacityTest, NullObject) {
    EXPECT_EQ(0, std_vector_capacity(NULL));
}

TEST_F(CapacityTest, EqualZero) {
    EXPECT_EQ(0, std_vector_capacity(vector));
}

TEST_F(CapacityTest, GreaterThanZero) {
    int value = 10;
    std_vector_push_back(vector, &value);
    EXPECT_EQ(STD_VECTOR_BLOCK_SIZE, std_vector_capacity(vector));
}
