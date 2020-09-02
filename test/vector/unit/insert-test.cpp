#include <gtest/gtest.h>

extern "C" {
#include "vector.h"
}

class InsertTest : public ::testing::Test {
protected:
    void SetUp() override {
        vector = std_vector_create(sizeof(int));
    }

    void TearDown() override {
        std_vector_destroy(&vector);
    }

    StdVector vector;
};

TEST_F(InsertTest, NullObject) {
    int value = 123;
    std_vector_insert(NULL, 0, &value);
}

TEST_F(InsertTest, EmptyVector) {
    int value = 123;
    std_vector_insert(vector, 0, &value);
    EXPECT_EQ(value, *(int *)std_vector_at(vector, 0));
    EXPECT_EQ(1, std_vector_size(vector));
    EXPECT_EQ(STD_VECTOR_BLOCK_SIZE, std_vector_capacity(vector));
}

TEST_F(InsertTest, InsertFront) {
    int value0 = 10;
    int value1 = 20;
    std_vector_push_back(vector, &value0);
    std_vector_push_back(vector, &value1);
    EXPECT_EQ(value0, *(int *)std_vector_at(vector, 0));
    EXPECT_EQ(value1, *(int *)std_vector_at(vector, 1));
    int value_insert = 30;
    std_vector_insert(vector, 0, &value_insert);
    EXPECT_EQ(value_insert, *(int *)std_vector_at(vector, 0));
    EXPECT_EQ(value0, *(int *)std_vector_at(vector, 1));
    EXPECT_EQ(value1, *(int *)std_vector_at(vector, 2));
    EXPECT_EQ(3, std_vector_size(vector));
    EXPECT_EQ(STD_VECTOR_BLOCK_SIZE, std_vector_capacity(vector));
}

TEST_F(InsertTest, InsertMiddle) {
    int value0 = 10;
    int value1 = 20;
    std_vector_push_back(vector, &value0);
    std_vector_push_back(vector, &value1);
    EXPECT_EQ(value0, *(int *)std_vector_at(vector, 0));
    EXPECT_EQ(value1, *(int *)std_vector_at(vector, 1));
    int value_insert = 30;
    std_vector_insert(vector, 1, &value_insert);
    EXPECT_EQ(value0, *(int *)std_vector_at(vector, 0));
    EXPECT_EQ(value_insert, *(int *)std_vector_at(vector, 1));
    EXPECT_EQ(value1, *(int *)std_vector_at(vector, 2));
    EXPECT_EQ(3, std_vector_size(vector));
    EXPECT_EQ(STD_VECTOR_BLOCK_SIZE, std_vector_capacity(vector));
}

TEST_F(InsertTest, InsertBack) {
    int value0 = 10;
    int value1 = 20;
    std_vector_push_back(vector, &value0);
    std_vector_push_back(vector, &value1);
    EXPECT_EQ(value0, *(int *)std_vector_at(vector, 0));
    EXPECT_EQ(value1, *(int *)std_vector_at(vector, 1));
    int value_insert = 30;
    std_vector_insert(vector, 2, &value_insert);
    EXPECT_EQ(value0, *(int *)std_vector_at(vector, 0));
    EXPECT_EQ(value1, *(int *)std_vector_at(vector, 1));
    EXPECT_EQ(value_insert, *(int *)std_vector_at(vector, 2));
    EXPECT_EQ(3, std_vector_size(vector));
    EXPECT_EQ(STD_VECTOR_BLOCK_SIZE, std_vector_capacity(vector));
}

TEST_F(InsertTest, InsertOverflow) {
    int value0 = 10;
    int value1 = 20;
    std_vector_push_back(vector, &value0);
    std_vector_push_back(vector, &value1);
    EXPECT_EQ(value0, *(int *)std_vector_at(vector, 0));
    EXPECT_EQ(value1, *(int *)std_vector_at(vector, 1));
    int value_insert = 30;
    std_vector_insert(vector, 10, &value_insert);
    EXPECT_EQ(value0, *(int *)std_vector_at(vector, 0));
    EXPECT_EQ(value1, *(int *)std_vector_at(vector, 1));
    EXPECT_EQ(value_insert, *(int *)std_vector_at(vector, 2));
    EXPECT_EQ(3, std_vector_size(vector));
    EXPECT_EQ(STD_VECTOR_BLOCK_SIZE, std_vector_capacity(vector));
}
