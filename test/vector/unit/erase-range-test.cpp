#include <gtest/gtest.h>

extern "C" {
#include "vector.h"
}

class EraseRangeTest : public ::testing::Test {
protected:
    void SetUp() override {
        vector = std_vector_create(sizeof(int));
    }

    void TearDown() override {
        std_vector_destroy(&vector);
    }

    StdVector vector;
};

TEST_F(EraseRangeTest, NullObject) {
    std_vector_erase_range(NULL, 0, 3);
}

TEST_F(EraseRangeTest, EmptyVector) {
    int value = 123;
    std_vector_erase_range(vector, 0, 3);
    EXPECT_EQ(0, std_vector_size(vector));
    EXPECT_EQ(0, std_vector_capacity(vector));
}

TEST_F(EraseRangeTest, FirstBiggerThanLast) {
    int value = 0;
    for (int i = 0; i < 10; i++) {
        std_vector_push_back(vector, &value);
        value += 10;
    }
    std_vector_erase_range(vector, 3, 0);
    EXPECT_EQ(10, std_vector_size(vector));
    EXPECT_EQ(STD_VECTOR_BLOCK_SIZE, std_vector_capacity(vector));
}

TEST_F(EraseRangeTest, EraseFront) {
    int value = 0;
    for (int i = 0; i < 10; i++) {
        std_vector_push_back(vector, &value);
        value += 10;
    }
    value = 0;
    for (int i = 0; i < 10; i++) {
        EXPECT_EQ(value, *(int *)std_vector_at(vector, i));
        value += 10;
    }
    std_vector_erase_range(vector, 0, 4);
    value = 50;
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(value, *(int *)std_vector_at(vector, i));
        value += 10;
    }
    EXPECT_EQ(5, std_vector_size(vector));
    EXPECT_EQ(STD_VECTOR_BLOCK_SIZE, std_vector_capacity(vector));
}

TEST_F(EraseRangeTest, EraseMiddle) {
    int value = 0;
    for (int i = 0; i < 10; i++) {
        std_vector_push_back(vector, &value);
        value += 10;
    }
    value = 0;
    for (int i = 0; i < 10; i++) {
        EXPECT_EQ(value, *(int *)std_vector_at(vector, i));
        value += 10;
    }
    std_vector_erase_range(vector, 3, 7);
    EXPECT_EQ(0, *(int *)std_vector_at(vector, 0));
    EXPECT_EQ(10, *(int *)std_vector_at(vector, 1));
    EXPECT_EQ(20, *(int *)std_vector_at(vector, 2));
    EXPECT_EQ(80, *(int *)std_vector_at(vector, 3));
    EXPECT_EQ(90, *(int *)std_vector_at(vector, 4));
    EXPECT_EQ(5, std_vector_size(vector));
    EXPECT_EQ(STD_VECTOR_BLOCK_SIZE, std_vector_capacity(vector));
}

TEST_F(EraseRangeTest, EraseBack) {
    int value = 0;
    for (int i = 0; i < 10; i++) {
        std_vector_push_back(vector, &value);
        value += 10;
    }
    value = 0;
    for (int i = 0; i < 10; i++) {
        EXPECT_EQ(value, *(int *)std_vector_at(vector, i));
        value += 10;
    }
    std_vector_erase_range(vector, 5, 9);
    value = 0;
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(value, *(int *)std_vector_at(vector, i));
        value += 10;
    }
    EXPECT_EQ(5, std_vector_size(vector));
    EXPECT_EQ(STD_VECTOR_BLOCK_SIZE, std_vector_capacity(vector));
}

TEST_F(EraseRangeTest, EraseOverflow) {
    int value = 0;
    for (int i = 0; i < 10; i++) {
        std_vector_push_back(vector, &value);
        value += 10;
    }
    value = 0;
    for (int i = 0; i < 10; i++) {
        EXPECT_EQ(value, *(int *)std_vector_at(vector, i));
        value += 10;
    }
    std_vector_erase_range(vector, 5, 9);
    value = 0;
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(value, *(int *)std_vector_at(vector, i));
        value += 10;
    }
    EXPECT_EQ(5, std_vector_size(vector));
    EXPECT_EQ(STD_VECTOR_BLOCK_SIZE, std_vector_capacity(vector));
}
