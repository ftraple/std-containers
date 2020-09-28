#include <gtest/gtest.h>

extern "C" {
#include "list.h"
}

TEST(ExampleTest, SimpleTest) {
    StdList list = std_list_create(sizeof(int));

    int value_array[4] = {1, 2, 3, 4};
    for (int i = 0; i < 4; i++) {
        std_list_push_back(list, &value_array[i]);
    }

    int i = 0;
    StdListNode node = std_list_begin(list);
    while (node != NULL) {
        int value = *(int*)std_list_at(node);
        EXPECT_EQ(value_array[i++], value);
        node = std_list_next(node);
    }

    std_list_destroy(&list);
}
