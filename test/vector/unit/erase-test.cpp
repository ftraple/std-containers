#include <gtest/gtest.h>

extern "C" {
#include "vector.h"
}

class EraseTest : public ::testing::Test {
protected:
    void SetUp() override {
        vector = std_vector_create(sizeof(int));
    }

    void TearDown() override {
        std_vector_destroy(&vector);
    }

    StdVector vector;
};

TEST_F(EraseTest, NullObject) {
    std_vector_erase(NULL, 0);
}

TEST_F(EraseTest, EmptyVector) {
    int value = 123;
    std_vector_erase(vector, 0);
    EXPECT_EQ(0, std_vector_size(vector));
    EXPECT_EQ(0, std_vector_capacity(vector));
}

TEST_F(EraseTest, EraseFront) {
    int value0 = 10;
    int value1 = 20;
    int value2 = 30;
    std_vector_push_back(vector, &value0);
    std_vector_push_back(vector, &value1);
    std_vector_push_back(vector, &value2);
    EXPECT_EQ(value0, *(int *)std_vector_at(vector, 0));
    EXPECT_EQ(value1, *(int *)std_vector_at(vector, 1));
    EXPECT_EQ(value2, *(int *)std_vector_at(vector, 2));
    std_vector_erase(vector, 0);
    EXPECT_EQ(value1, *(int *)std_vector_at(vector, 0));
    EXPECT_EQ(value2, *(int *)std_vector_at(vector, 1));
    EXPECT_EQ(2, std_vector_size(vector));
    EXPECT_EQ(STD_VECTOR_BLOCK_SIZE, std_vector_capacity(vector));
}

TEST_F(EraseTest, EraseMiddle) {
    int value0 = 10;
    int value1 = 20;
    int value2 = 30;
    std_vector_push_back(vector, &value0);
    std_vector_push_back(vector, &value1);
    std_vector_push_back(vector, &value2);
    EXPECT_EQ(value0, *(int *)std_vector_at(vector, 0));
    EXPECT_EQ(value1, *(int *)std_vector_at(vector, 1));
    EXPECT_EQ(value2, *(int *)std_vector_at(vector, 2));
    std_vector_erase(vector, 1);
    EXPECT_EQ(value0, *(int *)std_vector_at(vector, 0));
    EXPECT_EQ(value2, *(int *)std_vector_at(vector, 1));
    EXPECT_EQ(2, std_vector_size(vector));
    EXPECT_EQ(STD_VECTOR_BLOCK_SIZE, std_vector_capacity(vector));
}

TEST_F(EraseTest, EraseBack) {
    int value0 = 10;
    int value1 = 20;
    int value2 = 30;
    std_vector_push_back(vector, &value0);
    std_vector_push_back(vector, &value1);
    std_vector_push_back(vector, &value2);
    EXPECT_EQ(value0, *(int *)std_vector_at(vector, 0));
    EXPECT_EQ(value1, *(int *)std_vector_at(vector, 1));
    EXPECT_EQ(value2, *(int *)std_vector_at(vector, 2));
    std_vector_erase(vector, 2);
    EXPECT_EQ(value0, *(int *)std_vector_at(vector, 0));
    EXPECT_EQ(value1, *(int *)std_vector_at(vector, 1));
    EXPECT_EQ(2, std_vector_size(vector));
    EXPECT_EQ(STD_VECTOR_BLOCK_SIZE, std_vector_capacity(vector));
}

TEST_F(EraseTest, EraseOverflow) {
    int value0 = 10;
    int value1 = 20;
    int value2 = 30;
    std_vector_push_back(vector, &value0);
    std_vector_push_back(vector, &value1);
    std_vector_push_back(vector, &value2);
    EXPECT_EQ(value0, *(int *)std_vector_at(vector, 0));
    EXPECT_EQ(value1, *(int *)std_vector_at(vector, 1));
    EXPECT_EQ(value2, *(int *)std_vector_at(vector, 2));
    std_vector_erase(vector, 3);
    EXPECT_EQ(value0, *(int *)std_vector_at(vector, 0));
    EXPECT_EQ(value1, *(int *)std_vector_at(vector, 1));
    EXPECT_EQ(value2, *(int *)std_vector_at(vector, 2));
    EXPECT_EQ(3, std_vector_size(vector));
    EXPECT_EQ(STD_VECTOR_BLOCK_SIZE, std_vector_capacity(vector));
}
