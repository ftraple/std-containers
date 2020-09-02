#include <gtest/gtest.h>

extern "C" {
#include "vector.h"
}

class DataTest : public ::testing::Test {
protected:
    void SetUp() override {
        vector = std_vector_create(sizeof(int));
    }

    void TearDown() override {
        std_vector_destroy(&vector);
    }

    StdVector vector;
};

TEST_F(DataTest, NullObject) {
    EXPECT_TRUE(NULL == std_vector_data(NULL));
}

TEST_F(DataTest, EmptyVector) {
    EXPECT_TRUE(NULL == std_vector_data(vector));
}

TEST_F(DataTest, Valid) {
    int value0 = 10;
    int value1 = 20;
    int value2 = 30;
    std_vector_push_back(vector, &value0);
    std_vector_push_back(vector, &value1);
    std_vector_push_back(vector, &value2);
    int *data = (int *)std_vector_data(vector);
    EXPECT_EQ(value0, data[0]);
    EXPECT_EQ(value1, data[1]);
    EXPECT_EQ(value2, data[2]);
}
