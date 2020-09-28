#include <gtest/gtest.h>

extern "C" {
#include "list.h"
}

class AtTest : public ::testing::Test {
protected:
    void SetUp() override {
        list = std_list_create(sizeof(int));
    }

    void TearDown() override {
        std_list_destroy(&list);
    }

    StdList list;
};

TEST_F(AtTest, NullObject) {
    EXPECT_TRUE(NULL == std_list_at(NULL));
}

TEST_F(AtTest, EmptyNode) {
    StdListNode node = NULL;
    EXPECT_TRUE(NULL == std_list_at(node));
}

TEST_F(AtTest, OneElements) {
    int value = 10;
    std_list_push_back(list, &value);
    StdListNode node = std_list_begin(list);
    EXPECT_EQ(value, *(int *)std_list_at(node));
}

TEST_F(AtTest, MultipleElements) {
    int value[] = {10, 20, 30};
    std_list_push_back(list, &value[0]);
    std_list_push_back(list, &value[1]);
    std_list_push_back(list, &value[2]);
    int i = 0;
    StdListNode node = std_list_begin(list);
    while (node != NULL) {
        int new_value = *(int *)std_list_at(node);
        EXPECT_EQ(value[i], new_value);
        node = std_list_next(node);
        i++;
    }
}
