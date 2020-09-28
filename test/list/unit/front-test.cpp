#include <gtest/gtest.h>

extern "C" {
#include "list.h"
}

class FrontTest : public ::testing::Test {
protected:
    void SetUp() override {
        list = std_list_create(sizeof(int));
    }

    void TearDown() override {
        std_list_destroy(&list);
    }

    StdList list;
};

TEST_F(FrontTest, NullObject) {
    EXPECT_TRUE(NULL == std_list_front(NULL));
}

TEST_F(FrontTest, EmptyList) {
    EXPECT_TRUE(NULL == std_list_front(list));
}

TEST_F(FrontTest, OneElements) {
    int value = 10;
    std_list_push_back(list, &value);
    EXPECT_EQ(value, *(int*)std_list_front(list));
}

TEST_F(FrontTest, MultipleElements) {
    int value[] = {10, 20, 30};
    std_list_push_back(list, &value[0]);
    std_list_push_back(list, &value[1]);
    std_list_push_back(list, &value[2]);
    EXPECT_EQ(value[0], *(int*)std_list_front(list));
}
