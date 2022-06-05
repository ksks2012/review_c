/*
 * https://hackmd.io/@sysprog/linux2021-quiz1
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib/sort.h"
#include "lib/list_node.h"
#include "lib/ks_random.h"

static bool list_is_ordered(ListNode *list) {
    bool first = true;
    int value;
    while (list) {
        if (first) {
            value = *((int *)(list->value));
            first = false;
        } else {
            if (*((int *)(list->value)) < value)
                return false;
            value = *((int *)(list->value));
        }
        list = list->next;
    }
    return true;
}

static void list_display(ListNode *list) {
    printf("%s IN ORDER : ", list_is_ordered(list) ? "   " : "NOT");
    while (list) {
        printf("%d ", *((int *)(list->value)));
        list = list->next;
    }
    printf("\n");
}

int main(int argc, char **argv) {
    ListNode *list = NULL;
    int array[100] = {0};
    int count = 100;

    init_rand(time(NULL));
    while (count--) {
        array[count] = rand_range(0, 1024);
    }

    list = array_to_list(array, 5);

    list_display(list);
    list_quick_sort(&list);
    list_display(list);

    if (!list_is_ordered(list))
        return EXIT_FAILURE;

    delete_linking_list(&list);
    return EXIT_SUCCESS;
}        