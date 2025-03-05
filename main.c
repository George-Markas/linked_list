#define LINKED_LIST_IMPL
#include "linked_list.h"

void print_list(const list_t* list) {
    node_t* temp = list->head;
    while (temp != NULL) {
        printf("%s", (char*)temp->data);
        temp = temp->next;
    }
}

int main(void) {
    list_t* my_list = list_init();

    insert_at_head(my_list, " three", sizeof(" three"));
    insert_at_head(my_list, " two", sizeof(" one"));
    insert_at_head(my_list, "one", sizeof("one"));

    /* index for insert_after() is 0-based, if the provided index goes out of bounds it will just insert at the end of
    the list, aka after the tail node */
    insert_after(my_list, 1, " insertion!", sizeof(" insertion!"));
    insert_after(my_list, 2, " insertion!", sizeof(" insertion!"));

    insert_at_tail(my_list, " four", sizeof(" four"));

    print_list(my_list);
    free_list(my_list);

    return EXIT_SUCCESS;
}