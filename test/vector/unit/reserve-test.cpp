#include <gtest/gtest.h>

extern "C" {
#include "vector.h"
}

class ReserveTest : public ::testing::Test {
protected:
    void SetUp() override {
        vector = std_vector_create(sizeof(int));
    }

    void TearDown() override {
        std_vector_destroy(&vector);
    }

    StdVector vector;
};

TEST_F(ReserveTest, NullObject) {
    std_vector_reserve(NULL, 0);
}

TEST_F(ReserveTest, EquallZero) {
    std_vector_reserve(vector, 0);
    EXPECT_EQ(0, std_vector_size(vector));
    EXPECT_EQ(0, std_vector_capacity(vector));
}

TEST_F(ReserveTest, SizeGreaterThanZero) {
    size_t size = 10;
    std_vector_reserve(vector, size);
    EXPECT_EQ(0, std_vector_size(vector));
    EXPECT_EQ(size, std_vector_capacity(vector));
}
