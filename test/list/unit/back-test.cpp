#include <gtest/gtest.h>

extern "C" {
#include "list.h"
}

class BackTest : public ::testing::Test {
protected:
    void SetUp() override {
        list = std_list_create(sizeof(int));
    }

    void TearDown() override {
        std_list_destroy(&list);
    }

    StdList list;
};

TEST_F(BackTest, NullObject) {
    EXPECT_TRUE(NULL == std_list_back(NULL));
}

TEST_F(BackTest, EmptyList) {
    EXPECT_TRUE(NULL == std_list_back(list));
}

TEST_F(BackTest, OneElements) {
    int value = 10;
    std_list_push_back(list, &value);
    EXPECT_EQ(value, *(int*)std_list_back(list));
}

TEST_F(BackTest, MultipleElements) {
    int value[] = {10, 20, 30};
    std_list_push_back(list, &value[0]);
    std_list_push_back(list, &value[1]);
    std_list_push_back(list, &value[2]);
    EXPECT_EQ(value[2], *(int*)std_list_back(list));
}
