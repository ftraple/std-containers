#ifndef STD_INCLUDE_LIST_H_
#define STD_INCLUDE_LIST_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StdListNode_t *StdListNode;
typedef struct StdList_t *StdList;

// Constructors and destructors
//----------------------------------------------------------------------------------------------------------------------

StdList std_list_create(size_t value_size);

void std_list_destroy(StdList *list_ptr);

// Element access
//----------------------------------------------------------------------------------------------------------------------

void *std_list_at(StdListNode node);

void *std_list_front(StdList list);

void *std_list_back(StdList list);

// Iterators
//----------------------------------------------------------------------------------------------------------------------

StdListNode std_list_begin(StdList list);

StdListNode std_list_end(StdList list);

StdListNode std_list_next(StdListNode node);

StdListNode std_list_previous(StdListNode node);

// Capacity
//----------------------------------------------------------------------------------------------------------------------

bool std_list_empty(StdList list);

size_t std_list_size(StdList list);

// Modifiers
//----------------------------------------------------------------------------------------------------------------------

void std_list_clear(StdList list);

void std_list_insert(StdList list, StdListNode node, const void *value);

void std_list_erase(StdList list, StdListNode node);

void std_list_push_back(StdList list, const void *value);

void *std_list_emplace_back(StdList list);

void std_list_pop_back(StdList list);

void std_list_push_front(StdList list, const void *value);

void *std_list_emplace_front(StdList list);

void std_list_pop_front(StdList list);

void std_list_swap(StdList *list_a_ptr, StdList *list_b_ptr);

// Operations
//----------------------------------------------------------------------------------------------------------------------

// void std_list_merge(StdList *list_a_ptr, StdList *list_b_ptr);

// void std_list_splice(StdList *list_a_ptr, StdList *list_b_ptr);

// void std_list_remove_if(StdList list);

// void std_list_reverse(StdList list);

// void std_list_unique(StdList list);

// void std_list_sort(StdList list);

#endif // STD_INCLUDE_LIST_H_