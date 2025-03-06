#pragma once
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
    struct Node* next;
    void* data;
} node_t;

typedef struct List {
    node_t* head;
    node_t* tail;
} list_t;

#include <stdio.h>
#include <stdlib.h>

list_t* list_init(void);
void insert_at_head(list_t* list, const void* data, const size_t bytes);
void insert_at_tail(list_t* list, const void* data, const size_t bytes);
void insert_after(const list_t* list, const int32_t index, const void* data, const size_t bytes);
void delete_head(list_t* list);
// TODO
//void delete_after(const list_t* list, const int32_t index);
void free_list(list_t* list);

#endif // LINKED_LIST_H

#ifdef LINKED_LIST_IMPL
#include <string.h>
#include <assert.h>

inline list_t* list_init(void) {
    list_t *new_list = malloc(sizeof(list_t));
    if(new_list == NULL)
        return NULL;

    *new_list = (list_t){NULL, NULL};
    return new_list;
}

inline void insert_at_head(list_t* list, const void* data, const size_t bytes) {
    node_t* new_node = malloc(sizeof(node_t));
    assert(new_node != NULL);

    new_node->data = malloc(bytes);
    assert(new_node->data != NULL);

    memcpy(new_node->data, data, bytes);
    if(list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
        new_node->next = NULL;
    } else {
        new_node->next = list->head;
        list->head = new_node;
    }
}

inline void insert_at_tail(list_t* list, const void* data, const size_t bytes) {
    node_t* new_node = malloc(sizeof(node_t));
    assert(new_node != NULL);

    new_node->data = malloc(bytes);
    assert(new_node->data != NULL);

    memcpy(new_node->data, data, bytes);
    if(list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
        new_node->next = NULL;
    } else {
        new_node->next = NULL;
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

inline void insert_after(const list_t* list, const int32_t index, const void* data, const size_t bytes) {
    node_t* new_node = malloc(sizeof(node_t));
    assert(new_node != NULL);

    new_node->data = malloc(bytes);
    assert(new_node->data != NULL);

    memcpy(new_node->data, data, bytes);

    node_t* insert_after = list->head;
    assert((insert_after != NULL) && (index > -1));
    for(int32_t i = 0; i < index && (insert_after->next != NULL); i++) {
        insert_after = insert_after->next;
    }
    new_node->next = insert_after->next;
    insert_after->next = new_node;
}

inline void delete_head(list_t* list) {
    node_t* temp = list->head;
    assert(temp != NULL);
    list->head = list->head->next;
    free(temp->data);
    temp->data = NULL;
    free(temp);
    temp = NULL;
}

// TODO
// inline void delete_after(const list_t* list, const int32_t index) {
// }

inline void free_list(list_t* list) {
    while (list->head != NULL) {
        node_t* next = list->head->next;
        free(list->head->data);
        list->head->data = NULL;
        free(list->head);
        list->head = next;
    }
    free(list);
    list = NULL;
}

#endif // LINKED_LIST_IMPL