#include <gtest/gtest.h>

extern "C" {
#include "vector.h"
}

class BackTest : public ::testing::Test {
protected:
    void SetUp() override {
        vector = std_vector_create(sizeof(int));
    }

    void TearDown() override {
        std_vector_destroy(&vector);
    }

    StdVector vector;
};

TEST_F(BackTest, NullObject) {
    EXPECT_TRUE(NULL == std_vector_back(NULL));
}

TEST_F(BackTest, EmptyVector) {
    EXPECT_TRUE(NULL == std_vector_back(vector));
}

TEST_F(BackTest, ValidIndex) {
    int value0 = 10;
    int value1 = 20;
    int value2 = 30;
    std_vector_push_back(vector, &value0);
    std_vector_push_back(vector, &value1);
    std_vector_push_back(vector, &value2);
    EXPECT_EQ(value2, *(int *)std_vector_back(vector));
}
