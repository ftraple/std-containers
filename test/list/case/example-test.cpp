#include <gtest/gtest.h>

extern "C" {
#include "list.h"
}

TEST(ExampleTest, SimpleTest) {
    // Create the list
    StdList list = std_list_create(sizeof(int));
    
    // Populate the list
    int value = 10;
    std_list_push_back(list, &value);
    value = 20;
    std_list_push_back(list, &value);
    value = 30;
    std_list_push_back(list, &value);
    
    // Show the list
    StdListNode node = std_list_begin(list);
    while (node != NULL) {
        value = *(int*)std_list_at(node);
        printf("Value = %d\n", value);
        node = std_list_next(node);
    }

    // Destroy the list
    std_list_destroy(&list);
}
