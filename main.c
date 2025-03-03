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

    insert_at_head(my_list, " | tad of inbetween | ", sizeof(" | tad of inbetween | "));
    insert_at_head(my_list, "foo", sizeof("foo"));
    insert_at_tail(my_list, "bar", sizeof("bar"));
    print_list(my_list);

    free_list(my_list);

    return EXIT_SUCCESS;
}