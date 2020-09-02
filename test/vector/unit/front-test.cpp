#include <gtest/gtest.h>

extern "C" {
#include "vector.h"
}

class FrontTest : public ::testing::Test {
protected:
    void SetUp() override {
        vector = std_vector_create(sizeof(int));
    }

    void TearDown() override {
        std_vector_destroy(&vector);
    }

    StdVector vector;
};

TEST_F(FrontTest, NullObject) {
    EXPECT_TRUE(NULL == std_vector_front(NULL));
}

TEST_F(FrontTest, EmptyVector) {
    EXPECT_TRUE(NULL == std_vector_front(vector));
}

TEST_F(FrontTest, ValidIndex) {
    int value0 = 10;
    int value1 = 20;
    int value2 = 30;
    std_vector_push_back(vector, &value0);
    std_vector_push_back(vector, &value1);
    std_vector_push_back(vector, &value2);
    EXPECT_EQ(value0, *(int *)std_vector_front(vector));
}
