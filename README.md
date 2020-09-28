# C Containers Library

This is an implementation of the C++ standards containers libraries to C.

## Vector

Provides the container object to a dynamic array, example:
This container mimics the std::vector container from C++, and it uses a dinamyc allocated array as pattern, example:

```C
// Create the vector
StdVector vector = std_vector_create(sizeof(int));

// Populate the vector
int value = 10;
std_vector_push_back(vector, &value);
value = 20;
std_vector_push_back(vector, &value);
value = 30;
std_vector_push_back(vector, &value);

// Print the vector
for (int i = 0; i < std_vector_size(vector); ++i) {
    value = *(int*)std_vector_at(vector, i);
    printf("Value = %d\n", value);
}

// Destroy the vector
std_vector_destroy(&vector);
```

## List

This container mimics the std::list container from C++, and it uses a double-linked list as pattern, example:

```C
// Create the list
StdList list = std_list_create(sizeof(int));

// Populate the list
int value = 10;
std_list_push_back(list, &value);
value = 20;
std_list_push_back(list, &value);
value = 30;
std_list_push_back(list, &value);

// Print the list
StdListNode node = std_list_begin(list);
while (node != NULL) {
    value = *(int*)std_list_at(node);
    printf("Value = %d\n", value);
    node = std_list_next(node);
}

// Destroy the list
std_list_destroy(&list);
```

## stack

## forward list

## map

## unordered map

## queue

## dequeue

## set

## unordered set
