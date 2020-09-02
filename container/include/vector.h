#ifndef STD_INCLUDE_VECTOR_H_
#define STD_INCLUDE_VECTOR_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STD_VECTOR_BLOCK_SIZE 64

typedef struct StdVector_t *StdVector;

// Constructors and destructors
//----------------------------------------------------------------------------------------------------------------------

StdVector std_vector_create(size_t value_size);

StdVector std_vector_create_size(size_t value_size, size_t size);

StdVector std_vector_create_default_value(size_t value_size, size_t size, void *default_value);

void std_vector_destroy(StdVector *vector_ptr);

// Element access
//----------------------------------------------------------------------------------------------------------------------

void *std_vector_at(StdVector vector, size_t index);

void *std_vector_front(StdVector vector);

void *std_vector_back(StdVector vector);

void *std_vector_data(StdVector vector);

// Capacity
//----------------------------------------------------------------------------------------------------------------------

bool std_vector_empty(StdVector vector);

size_t std_vector_size(StdVector vector);

void std_vector_reserve(StdVector vector, size_t size);

size_t std_vector_capacity(StdVector vector);

void std_vector_shrink_to_fit(StdVector vector);

// Modifiers
//----------------------------------------------------------------------------------------------------------------------

void std_vector_clear(StdVector vector);

void std_vector_insert(StdVector vector, size_t position, void *value);

void std_vector_erase(StdVector vector, size_t position);

void std_vector_erase_range(StdVector vector, size_t first, size_t last);

void std_vector_push_back(StdVector vector, void *value);

void *std_vector_emplace_back(StdVector vector);

void std_vector_pop_back(StdVector vector);

void std_vector_resize(StdVector vector, size_t size);

void std_vector_swap(StdVector* vector_a_ptr, StdVector* vector_b_ptr);

#endif // STD_INCLUDE_VECTOR_H_