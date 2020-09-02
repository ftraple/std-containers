#include <gtest/gtest.h>

extern "C" {
#include "vector.h"
}

class SwapTest : public ::testing::Test {
protected:
    void SetUp() override {
        vector_a = std_vector_create(sizeof(int));
        vector_b = std_vector_create(sizeof(int));
    }

    void TearDown() override {
        std_vector_destroy(&vector_a);
        std_vector_destroy(&vector_b);
    }

    StdVector vector_a;
    StdVector vector_b;
};

TEST_F(SwapTest, NullObject) {
    std_vector_swap(NULL, NULL);
    std_vector_swap(&vector_a, NULL);
    std_vector_swap(NULL, &vector_b);
}

TEST_F(SwapTest, EmptyVector) {
    StdVector vector_a_tmp = vector_a;
    StdVector vector_b_tmp = vector_b;
    std_vector_swap(&vector_a, &vector_b);
    EXPECT_EQ(vector_a_tmp, vector_b);
    EXPECT_EQ(vector_b_tmp, vector_a);
}

TEST_F(SwapTest, VectorWithValues) {
    int value_a = 10;
    int value_b = 20;
    std_vector_push_back(vector_a, &value_a);
    std_vector_push_back(vector_b, &value_b);
    std_vector_swap(&vector_a, &vector_b);
    EXPECT_EQ(value_a, *(int *)std_vector_at(vector_b, 0));
    EXPECT_EQ(value_b, *(int *)std_vector_at(vector_a, 0));
}
