#include <gtest/gtest.h>

extern "C" {
#include "vector.h"
}

class SizeTest : public ::testing::Test {
protected:
    void SetUp() override {
        vector = std_vector_create(sizeof(int));
    }

    void TearDown() override {
        std_vector_destroy(&vector);
    }

    StdVector vector;
};

TEST_F(SizeTest, NullObject) {
    EXPECT_EQ(0, std_vector_size(NULL));
}

TEST_F(SizeTest, EqualZero) {
    EXPECT_EQ(0, std_vector_size(vector));
}

TEST_F(SizeTest, GreaterThanZero) {
    int value = 10;
    std_vector_push_back(vector, &value);
    EXPECT_EQ(1, std_vector_size(vector));
    std_vector_push_back(vector, &value);
    EXPECT_EQ(2, std_vector_size(vector));
    std_vector_push_back(vector, &value);
    EXPECT_EQ(3, std_vector_size(vector));
}
