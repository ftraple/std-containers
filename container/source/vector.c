#include "vector.h"

struct StdVector_t {
    size_t value_size;
    size_t size;
    size_t capacity;
    void *data;
};

// Private
//----------------------------------------------------------------------------------------------------------------------

static bool reallocate_vector_memory(StdVector vector, size_t size) {
    void *new_data = realloc(vector->data, size);
    if (new_data == NULL) return false;
    vector->data = new_data;
    vector->capacity = size;
    return true;
}

// Constructors and destructors
//----------------------------------------------------------------------------------------------------------------------

StdVector std_vector_create(size_t value_size) {
    if (value_size == 0) return NULL;
    StdVector vector = (StdVector)malloc(sizeof(struct StdVector_t));
    if (vector == NULL) return NULL;
    vector->value_size = value_size;
    vector->size = 0;
    vector->capacity = 0;
    vector->data = NULL;
    return vector;
}

StdVector std_vector_create_size(size_t value_size, size_t size) {
    StdVector vector = std_vector_create(value_size);
    if (vector == NULL) return NULL;
    if (size > 0) {
        vector->size = size;
        vector->capacity = size;
        vector->data = (void *)malloc(value_size * size);
        if (vector->data == NULL) {
            free(vector);
            return NULL;
        }
    }
    return vector;
}

StdVector std_vector_create_default_value(size_t value_size, size_t size, void *default_value) {
    if (default_value == NULL) return NULL;
    StdVector vector = std_vector_create_size(value_size, size);
    if (vector == NULL) return NULL;
    for (size_t i = 0; i < vector->size; ++i) {
        size_t start = (i * vector->value_size);
        memcpy(vector->data + start, default_value, value_size);
    }
    return vector;
}

void std_vector_destroy(StdVector *vector_ptr) {
    if (*vector_ptr == NULL) return;
    StdVector vector = *vector_ptr;
    free(vector->data);
    free(vector);
    *vector_ptr = NULL;
}

// Element access
//----------------------------------------------------------------------------------------------------------------------

void *std_vector_at(StdVector vector, size_t index) {
    if (vector == NULL || index >= vector->size) return NULL;
    return vector->data + (index * vector->value_size);
}

void *std_vector_front(StdVector vector) {
    if (vector == NULL || vector->size == 0) return NULL;
    return vector->data;
}

void *std_vector_back(StdVector vector) {
    if (vector == NULL || vector->size == 0) return NULL;
    size_t position = (vector->size - 1) * vector->value_size;
    return vector->data + position;
}

void *std_vector_data(StdVector vector) {
    if (vector == NULL) return NULL;
    return vector->data;
}

// Capacity
//----------------------------------------------------------------------------------------------------------------------

bool std_vector_empty(StdVector vector) {
    if (vector == NULL) return true;
    return (vector->size == 0) ? true : false;
}

size_t std_vector_size(StdVector vector) {
    if (vector == NULL) return 0;
    return vector->size;
}

void std_vector_reserve(StdVector vector, size_t size) {
    if (vector == NULL || size <= vector->capacity) return;
    reallocate_vector_memory(vector, size);
}

size_t std_vector_capacity(StdVector vector) {
    if (vector == NULL) return 0;
    return vector->capacity;
}

void std_vector_shrink_to_fit(StdVector vector) {
    if (vector == NULL) return;
    reallocate_vector_memory(vector, vector->size);
}

// Modifiers
//----------------------------------------------------------------------------------------------------------------------

void std_vector_clear(StdVector vector) {
    if (vector == NULL) return;
    vector->size = 0;
}

void std_vector_insert(StdVector vector, size_t position, void *value) {
    if (vector == NULL) return;
    if (vector->size == vector->capacity) {
        if (!reallocate_vector_memory(vector, vector->size + STD_VECTOR_BLOCK_SIZE)) return;
    }
    if (position > vector->size) {
        position = vector->size;
    }
    size_t start = position * vector->value_size;
    if (position < vector->size) {
        size_t end = vector->size * vector->value_size;
        memcpy(vector->data + start + vector->value_size, vector->data + start, end - start);
    }
    vector->size++;
    memcpy(vector->data + start, value, vector->value_size);
}

void std_vector_erase(StdVector vector, size_t position) {
    if (vector == NULL || vector->size == 0 || position >= vector->size) return;
    if (position == vector->size - 1) {
        vector->size--;
    } else {
        size_t index = position * vector->value_size;
        size_t rest_start = (position + 1) * vector->value_size;
        size_t rest_end = vector->size * vector->value_size;
        size_t rest_size = rest_end - rest_start;
        if (rest_size > 0) {
            memcpy(vector->data + index, vector->data + rest_start, rest_size);
        }
        vector->size--;
    }
}

void std_vector_erase_range(StdVector vector, size_t first, size_t last) {
    if (vector == NULL || vector->size == 0 || first >= vector->size || first > last) return;
    if (last >= vector->size - 1) {
        vector->size = first;
    } else {
        size_t index = first * vector->value_size;
        size_t rest_start = (last + 1) * vector->value_size;
        size_t rest_end = vector->size * vector->value_size;
        size_t rest_size = rest_end - rest_start;
        if (rest_size > 0) {
            memcpy(vector->data + index, vector->data + rest_start, rest_size);
        }
        vector->size -= last - first + 1;
    }
}

void std_vector_push_back(StdVector vector, void *value) {
    if (vector == NULL) return;
    if (vector->size == vector->capacity) {
        reallocate_vector_memory(vector, vector->size + STD_VECTOR_BLOCK_SIZE);
    }
    size_t position = vector->size * vector->value_size;
    memcpy(vector->data + position, value, vector->value_size);
    vector->size++;
}

void *std_vector_emplace_back(StdVector vector) {
    if (vector == NULL) return NULL;
    if (vector->size == vector->capacity) {
        reallocate_vector_memory(vector, vector->size + STD_VECTOR_BLOCK_SIZE);
    }
    size_t position = vector->size * vector->value_size;
    vector->size++;
    return vector->data + position;
}

void std_vector_pop_back(StdVector vector) {
    if (vector == NULL) return;
    if (vector->size > 0) {
        vector->size--;
    }
}

void std_vector_resize(StdVector vector, size_t size) {
    if (vector == NULL) return;
    if (size > vector->capacity) {
        reallocate_vector_memory(vector, size);
    }
    vector->size = size;
}

void std_vector_swap(StdVector *vector_a_ptr, StdVector *vector_b_ptr) {
    if (vector_a_ptr == NULL || vector_b_ptr == NULL) return;
    StdVector vector_tmp_ptr = *vector_a_ptr;
    *vector_a_ptr = *vector_b_ptr;
    *vector_b_ptr = vector_tmp_ptr;
}