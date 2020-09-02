#include <gtest/gtest.h>

extern "C" {
#include "vector.h"
}

TEST(ObjectTest, ValueSizeEqualZero) {
    EXPECT_TRUE(NULL == std_vector_create(0));
}

TEST(ObjectTest, ValueSizeGreaterThanZero) {
    StdVector vector = std_vector_create(sizeof(int));
    EXPECT_TRUE(NULL != vector);
    std_vector_destroy(&vector);
}

TEST(ObjectTest, SizeEqualZero) {
    StdVector vector = std_vector_create_size(sizeof(int), 0);
    EXPECT_TRUE(NULL != vector);
    EXPECT_EQ(0, std_vector_size(vector));
    EXPECT_EQ(0, std_vector_capacity(vector));
    std_vector_destroy(&vector);
}

TEST(ObjectTest, SizeGreatherThanZero) {
    size_t size = 10;
    StdVector vector = std_vector_create_size(sizeof(int), size);
    EXPECT_TRUE(NULL != vector);
    EXPECT_EQ(size, std_vector_size(vector));
    EXPECT_EQ(size, std_vector_capacity(vector));
    std_vector_destroy(&vector);
}

TEST(ObjectTest, NullDefaultValue) {
    EXPECT_TRUE(NULL == std_vector_create_default_value(sizeof(int), 10, NULL));
}

TEST(ObjectTest, ValidDefaultValue) {
    int size = 10;
    int default_value = 123;
    StdVector vector = std_vector_create_default_value(sizeof(int), size, &default_value);
    EXPECT_TRUE(NULL != vector);
    EXPECT_EQ(size, std_vector_size(vector));
    EXPECT_EQ(size, std_vector_capacity(vector));
    for (int i = 0; i < size; ++i) {
        EXPECT_EQ(default_value, *(int *)std_vector_at(vector, i));
    }
    std_vector_destroy(&vector);
}

TEST(ObjectTest, DestroyObject) {
    StdVector vector = std_vector_create(sizeof(int));
    EXPECT_TRUE(NULL != vector);
    std_vector_destroy(&vector);
    EXPECT_TRUE(NULL == vector);
}
