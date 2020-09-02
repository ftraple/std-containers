#include <gtest/gtest.h>

extern "C" {
#include "vector.h"
}

class EmplaceBackTest : public ::testing::Test {
protected:
    void SetUp() override {
        vector = std_vector_create(sizeof(int));
    }

    void TearDown() override {
        std_vector_destroy(&vector);
    }

    StdVector vector;
};

TEST_F(EmplaceBackTest, NullObject) {
    EXPECT_TRUE(NULL == std_vector_emplace_back(NULL));
}

TEST_F(EmplaceBackTest, EmptyVector) {
    int* value = (int *)std_vector_emplace_back(vector);
    *value = 10;
    EXPECT_EQ(*value, *(int *)std_vector_at(vector, 0));
    EXPECT_EQ(1, std_vector_size(vector));
    EXPECT_EQ(STD_VECTOR_BLOCK_SIZE, std_vector_capacity(vector));
}

TEST_F(EmplaceBackTest, Multiples) {
    int* value0 = (int *)std_vector_emplace_back(vector);
    int* value1 = (int *)std_vector_emplace_back(vector);
    int* value2 = (int *)std_vector_emplace_back(vector);
    *value0 = 10;
    *value1 = 20;
    *value2 = 30;
    EXPECT_EQ(*value0, *(int *)std_vector_at(vector, 0));
    EXPECT_EQ(*value1, *(int *)std_vector_at(vector, 1));
    EXPECT_EQ(*value2, *(int *)std_vector_at(vector, 2));
    EXPECT_EQ(3, std_vector_size(vector));
    EXPECT_EQ(STD_VECTOR_BLOCK_SIZE, std_vector_capacity(vector));
}
