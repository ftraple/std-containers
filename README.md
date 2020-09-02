# C Containers Library

This is an implementation of the C++ standards containers libraries to C.

## Vector

Provides the container object to a dynamic array, example:

```C
StdVector vector = std_vector_create(sizeof(int));

int value0 = 10;
int value1 = 20;
int value2 = 30;
std_vector_push_back(vector, &value0);
std_vector_push_back(vector, &value1);
std_vector_push_back(vector, &value2);

for (int i = 0; i < std_vector_size(vector); ++i) {
    printf("Value = %d\n", *(int*)std_vector_at(vector, i));
}

std_vector_destroy(&vector);
```

## stack

## List

## forward list

## map

## unordered map

## queue

## dequeue

## set

## unordered set
