#include <gtest/gtest.h>

extern "C" {
#include "vector.h"
}

class AtTest : public ::testing::Test {
protected:
    void SetUp() override {
        vector = std_vector_create(sizeof(int));
    }

    void TearDown() override {
        std_vector_destroy(&vector);
    }

    StdVector vector;
};

TEST_F(AtTest, NullObject) {
    EXPECT_TRUE(NULL == std_vector_at(NULL, 0));
}

TEST_F(AtTest, EmptyVector) {
    EXPECT_TRUE(NULL == std_vector_at(vector, 0));
}

TEST_F(AtTest, ValidIndex) {
    int value0 = 10;
    int value1 = 20;
    int value2 = 30;
    std_vector_push_back(vector, &value0);
    std_vector_push_back(vector, &value1);
    std_vector_push_back(vector, &value2);
    EXPECT_EQ(value0, *(int *)std_vector_at(vector, 0));
    EXPECT_EQ(value1, *(int *)std_vector_at(vector, 1));
    EXPECT_EQ(value2, *(int *)std_vector_at(vector, 2));
}

TEST_F(AtTest, IndexOverflow) {
    int value0 = 10;
    int value1 = 20;
    int value2 = 30;
    std_vector_push_back(vector, &value0);
    std_vector_push_back(vector, &value1);
    std_vector_push_back(vector, &value2);
    EXPECT_EQ(value0, *(int *)std_vector_at(vector, 0));
    EXPECT_EQ(value1, *(int *)std_vector_at(vector, 1));
    EXPECT_EQ(value2, *(int *)std_vector_at(vector, 2));
    EXPECT_EQ(NULL, std_vector_at(vector, 3));
}
