#include <gtest/gtest.h>

extern "C" {
#include "vector.h"
}

class EmptyTest : public ::testing::Test {
protected:
    void SetUp() override {
        vector = std_vector_create(sizeof(int));
    }

    void TearDown() override {
        std_vector_destroy(&vector);
    }

    StdVector vector;
};

TEST_F(EmptyTest, NullObject) {
    EXPECT_TRUE(std_vector_empty(NULL));
}

TEST_F(EmptyTest, EmptyVector) {
    EXPECT_TRUE(std_vector_empty(vector));
}

TEST_F(EmptyTest, Valid) {
    int value = 10;
    std_vector_push_back(vector, &value);
    EXPECT_FALSE(std_vector_empty(vector));
}
