#include <gtest/gtest.h>

extern "C" {
#include "vector.h"
}

class PopBackTest : public ::testing::Test {
protected:
    void SetUp() override {
        vector = std_vector_create(sizeof(int));
    }

    void TearDown() override {
        std_vector_destroy(&vector);
    }

    StdVector vector;
};

TEST_F(PopBackTest, NullObject) {
    std_vector_pop_back(NULL);
}

TEST_F(PopBackTest, EmptyVector) {
    std_vector_pop_back(vector);
    EXPECT_EQ(0, std_vector_size(vector));
    EXPECT_EQ(0, std_vector_capacity(vector));
}

TEST_F(PopBackTest, PopValue) {
    int value0 = 10;
    int value1 = 20;
    int value2 = 30;
    std_vector_push_back(vector, &value0);
    std_vector_push_back(vector, &value1);
    std_vector_push_back(vector, &value2);
    EXPECT_EQ(3, std_vector_size(vector));
    std_vector_pop_back(vector);
    EXPECT_EQ(2, std_vector_size(vector));
    std_vector_pop_back(vector);
    EXPECT_EQ(1, std_vector_size(vector));
    std_vector_pop_back(vector);
    EXPECT_EQ(0, std_vector_size(vector));
    EXPECT_EQ(STD_VECTOR_BLOCK_SIZE, std_vector_capacity(vector));
}
