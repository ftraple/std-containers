#include <gtest/gtest.h>

extern "C" {
#include "vector.h"
}

class ShrinkToFitTest : public ::testing::Test {
protected:
    void SetUp() override {
        vector = std_vector_create(sizeof(int));
    }

    void TearDown() override {
        std_vector_destroy(&vector);
    }

    StdVector vector;
};

TEST_F(ShrinkToFitTest, NullObject) {
    std_vector_shrink_to_fit(NULL);
}

TEST_F(ShrinkToFitTest, EqualZero) {
    std_vector_shrink_to_fit(vector);
    EXPECT_EQ(0, std_vector_capacity(vector));
}

TEST_F(ShrinkToFitTest, GreaterThanZero) {
    int value0 = 10;
    int value1 = 20;
    int value2 = 30;
    std_vector_push_back(vector, &value0);
    std_vector_push_back(vector, &value1);
    std_vector_push_back(vector, &value2);
    EXPECT_EQ(STD_VECTOR_BLOCK_SIZE, std_vector_capacity(vector));
    std_vector_shrink_to_fit(vector);
    EXPECT_EQ(3, std_vector_capacity(vector));
}
