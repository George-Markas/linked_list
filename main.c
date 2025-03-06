#define LINKED_LIST_IMPL
#include "linked_list.h"

void print_list(const list_t* list) {
    const node_t* temp = list->head;
    while (temp != NULL) {
        printf("%s", (char*)temp->data);
        temp = temp->next;
    }
    putc('\n', stdout);
}

int main(void) {
    // Node data is assigned to nodes via void*, use pointer cast to deref
    list_t* my_list = list_init();

    insert_at_head(my_list, " three", sizeof(" three"));
    insert_at_head(my_list, " two", sizeof(" one"));
    insert_at_head(my_list, "one", sizeof("one"));

    /* insert_after() works with 0-based indexing. Index must be =< 0, if the index is greater than the list's length,
    the insertion will be performed after the tail node */
    insert_after(my_list, 1, " insertion_one!", sizeof(" insertion one!"));
    insert_after(my_list, 2, " insertion_two!", sizeof(" insertion two!"));
    insert_at_tail(my_list, " four", sizeof(" four"));

    print_list(my_list);

    // Delete "one"
    delete_head(my_list);

    print_list(my_list);
    free_list(my_list);

    return EXIT_SUCCESS;
}