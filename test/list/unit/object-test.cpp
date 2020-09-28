#include <gtest/gtest.h>

extern "C" {
#include "list.h"
}

TEST(ObjectTest, ValueSizeEqualZero) {
    EXPECT_TRUE(NULL == std_list_create(0));
}

TEST(ObjectTest, ValueSizeGreaterThanZero) {
    StdList list = std_list_create(sizeof(int));
    EXPECT_TRUE(NULL != list);
    std_list_destroy(&list);
}

TEST(ObjectTest, DestroyObject) {
    StdList list = std_list_create(sizeof(int));
    EXPECT_TRUE(NULL != list);
    std_list_destroy(&list);
    EXPECT_TRUE(NULL == list);
}
