#include "heap_sort.h"
#include <stdio.h>
#include "bubble_sort.h"

void heapify_helper(my_deque* dq, int heap_size, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    elem* node_i = get_elem_at_index(dq, i);
    if (!node_i) return;

    elem* node_left = NULL;
    if (left < heap_size) {
        node_left = get_elem_at_index(dq, left);
    }

    elem* node_right = NULL;
    if (right < heap_size) {
        node_right = get_elem_at_index(dq, right);
    }

    if (node_left != NULL && node_left->data > node_i->data) {
        largest = left;
    }

    if (node_right != NULL) {
        elem* current_largest_node = NULL;
        if (largest == i) {
            current_largest_node = node_i;
        } else {
            current_largest_node = get_elem_at_index(dq, largest);
        }
        if (current_largest_node != NULL && node_right->data > current_largest_node->data) {
            largest = right;
        }
    }

    if(largest != i) {
        elem* node_largest = get_elem_at_index(dq, largest);
        if (node_largest != NULL) {
            swap_nodes(dq, node_i, node_largest);
            heapify_helper(dq, heap_size, largest);
        }
    }
}


void heap_sort(my_deque* dq) {
    if (!dq || !dq->start || !dq->start->next) return;
    
    int n = 0;
    for (elem* cur = dq->start; cur; cur = cur->next) n++;

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify_helper(dq, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        elem* first = get_elem_at_index(dq, 0);
        elem* last = get_elem_at_index(dq, i);
        swap_nodes(dq, first, last);
        heapify_helper(dq, i, 0);
    }

}

