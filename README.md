# Linked List

Singly-linked list implementation in "stb" format

## Example usage:
```c
#define LINKED_LIST_IMPL
#include "linked_list.h"

void print_list(const list_t* list) {
    static int32_t step = 1;
    const node_t* temp = list->head;
    printf("%d) ", step);
    while(temp != NULL) {
        // Data is void* pointers, cast them as needed
        printf("%s", (char*)temp->data);
        temp = temp->next;
    }
    puts("\n");
    step++;
}

int main(void) {
    list_t* my_list = list_init();

    insert_at_head(my_list, "bar", sizeof(char) * 4); // 3 letters + null terminator = 4 chars
    insert_at_head(my_list, "foo ", sizeof(char) * 5);
    insert_at_tail(my_list, " baz", sizeof(char) * 5);
    print_list(my_list);

    // Delete baz
    delete(my_list, 2);
    print_list(my_list);

    // Insert baz inbetween foo and bar
    insert_after(my_list, 0, "baz ", sizeof(char) * 5);
    print_list(my_list);

    // Delete foo
    delete_head(my_list);
    print_list(my_list);

    free_list(my_list);

    return EXIT_SUCCESS;
}
```
