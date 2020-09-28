#include "list.h"

struct StdListNode_t {
    void *data;
    StdListNode previous;
    StdListNode next;
};

struct StdList_t {
    size_t value_size;
    size_t size;
    StdListNode begin;
    StdListNode end;
};

static StdListNode create_node(StdList list, const void *value) {
    StdListNode node = (StdListNode)malloc(sizeof(struct StdListNode_t));
    if (node == NULL) return NULL;
    node->data = malloc(list->value_size * sizeof(char));
    if (node->data == NULL) {
        free(node);
        return NULL;
    }
    if (value != NULL) {
        memcpy(node->data, value, list->value_size);
    }
    node->previous = NULL;
    node->next = NULL;
    return node;
}

// Constructors and destructors
//----------------------------------------------------------------------------------------------------------------------

StdList std_list_create(size_t value_size) {
    if (value_size == 0) return NULL;
    StdList list = (StdList)malloc(sizeof(struct StdList_t));
    if (list == NULL) return NULL;
    list->value_size = value_size;
    list->size = 0;
    list->begin = NULL;
    list->end = NULL;
    return list;
}

void std_list_destroy(StdList *list_ptr) {
    if (*list_ptr == NULL) return;
    StdList list = *list_ptr;
    // TODO Clear the list
    free(list);
    *list_ptr = NULL;
}

// Element access
//----------------------------------------------------------------------------------------------------------------------

void *std_list_at(StdListNode node) {
    if (node == NULL) return NULL;
    return node->data;
}

void *std_list_front(StdList list) {
    if (list == NULL || list->size == 0) return NULL;
    return list->begin->data;
}

void *std_list_back(StdList list) {
    if (list == NULL || list->size == 0) return NULL;
    return list->end->data;
}

// Iterators
//----------------------------------------------------------------------------------------------------------------------

StdListNode std_list_begin(StdList list) {
    if (list == NULL) return NULL;
    return list->begin;
}

StdListNode std_list_end(StdList list) {
    if (list == NULL) return NULL;
    return list->end;
}

StdListNode std_list_next(StdListNode node) {
    if (node == NULL) return NULL;
    return node->next;
}

StdListNode std_list_previous(StdListNode node) {
    if (node == NULL) return NULL;
    return node->previous;
}

// Capacity
//----------------------------------------------------------------------------------------------------------------------

bool std_list_empty(StdList list) {
    if (list == NULL) return true;
    return (list->size == 0);
}

size_t std_list_size(StdList list) {
    if (list == NULL) return 0;
    return list->size;
}

// Modifiers
//----------------------------------------------------------------------------------------------------------------------

void std_list_clear(StdList list) {
    if (list == NULL) return;
    while (!std_list_empty(list)) {
        std_list_pop_back(list);
    }
}

void std_list_insert(StdList list, StdListNode node, const void *value) {
    if (list == NULL || value == NULL) return;
    StdListNode new_node = create_node(list, value);
    if (new_node == NULL) return;
    if (list->size == 0) {
        list->begin = new_node;
        list->end = new_node;
    } else if (node->next == NULL) {
        node->next = new_node;
        new_node->previous = node;
        list->end = new_node;
    } else {
        new_node->next = node->next;
        new_node->previous = node;
        node->next->previous = new_node;
        node->next = new_node;
    }
    list->size++;
}

void std_list_erase(StdList list, StdListNode node) {
    if (list == NULL || list->size == 0) return;
    if (node->previous == NULL) {
        std_list_pop_front(list);
    } else if (node->next == NULL) {
        std_list_pop_back(list);
    } else {
        node->previous->next = node->next;
        node->next->previous = node->previous;
        list->size--;
        free(node->data);
        free(node);
    }
}

void std_list_push_back(StdList list, const void *value) {
    if (list == NULL) return;
    StdListNode node = create_node(list, value);
    if (node == NULL) return;
    if (list->end != NULL) {
        list->end->next = node;
        node->previous = list->end;
    }
    list->end = node;
    list->size++;
    if (list->begin == NULL) {
        list->begin = node;
    }
}

void *std_list_emplace_back(StdList list) {
    if (list == NULL) return NULL;
    StdListNode node = create_node(list, NULL);
    if (node == NULL) return NULL;
    if (list->end != NULL) {
        list->end->next = node;
        node->previous = list->end;
    }
    list->end = node;
    list->size++;
    if (list->begin == NULL) {
        list->begin = node;
    }
    return node->data;
}

void std_list_pop_back(StdList list) {
    if (list == NULL || list->size == 0) return;
    StdListNode node = list->end;
    if (list->size == 1) {
        list->begin = NULL;
        list->end = NULL;
        list->size = 0;
    } else {
        node->previous->next = NULL;
        list->size--;
    }
    free(node->data);
    free(node);
}

void std_list_push_front(StdList list, const void *value) {
    if (list == NULL || value != NULL) return;
    StdListNode node = create_node(list, value);
    if (node == NULL) return;
    if (list->begin != NULL) {
        list->begin->previous = node;
        node->next = list->begin;
    }
    list->begin = node;
    list->size++;
    if (list->end == NULL) {
        list->end = node;
    }
}

void *std_list_emplace_front(StdList list) {
    if (list == NULL) return NULL;
    StdListNode node = create_node(list, NULL);
    if (node == NULL) return NULL;
    if (list->begin != NULL) {
        list->begin->previous = node;
        node->next = list->begin;
    }
    list->begin = node;
    list->size++;
    if (list->end == NULL) {
        list->end = node;
    }
    return node->data;
}

void std_list_pop_front(StdList list) {
    if (list == NULL || list->size == 0) return;
    StdListNode node = list->begin;
    if (list->size == 1) {
        list->begin = NULL;
        list->end = NULL;
        list->size = 0;
    } else {
        node->next->previous = NULL;
        list->size--;
    }
    free(node->data);
    free(node);
}

void std_list_swap(StdList *list_a_ptr, StdList *list_b_ptr) {
    if (list_a_ptr == NULL || list_b_ptr == NULL) return;
    StdList vector_tmp_ptr = *list_a_ptr;
    *list_a_ptr = *list_b_ptr;
    *list_b_ptr = vector_tmp_ptr;
}