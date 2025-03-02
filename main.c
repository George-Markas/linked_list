#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    struct Node* next;
    void* data;
} node_t;

typedef struct List {
    node_t* head;
    node_t* tail;
} list_t;

list_t* list_init() {
    list_t *new_list = malloc(sizeof(list_t));
    if(new_list == NULL) {
        free(new_list);
        return NULL;
    }

    *new_list = (list_t){NULL, NULL};
    return new_list;
}

void insert_at_head(list_t* list, const void* data, const  size_t bytes) {
    node_t* new_node = malloc(sizeof(node_t));
    if(new_node == NULL) {
        goto alloc_fail_2;
    }

    new_node->data = malloc(bytes);
    if(new_node->data == NULL)
        goto alloc_fail_1;

    memcpy(new_node->data, data, bytes);
    new_node->next = list->head;
    if(list->tail == NULL)
        list->tail = list->head;
    list->head = new_node;

    return;

    alloc_fail_1:
    free(new_node->data);
    alloc_fail_2:
    free(new_node);
}

void free_list(list_t* list) {
    while(list->head != NULL) {
        node_t* temp = list->head;
        list->head = list->head->next;
        free(temp->data);
        temp->data = NULL;
        free(temp);
        temp = NULL;
    }
    free(list);
    list = NULL;
}

void print_list(list_t* list) {
    node_t* temp = list->head;
    while (temp != NULL) {
        printf("%s", (char*)temp->data);
        temp = temp->next;
    }
}

int main(void) {
    list_t* my_list = list_init();
    insert_at_head(my_list, "snafu\n", sizeof("snafu\n"));
    insert_at_head(my_list, "bar ", sizeof("bar "));
    insert_at_head(my_list, "foo ", sizeof("foo "));
    print_list(my_list);
    free_list(my_list);

    return EXIT_SUCCESS;
}