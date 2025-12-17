#include <stdio.h>
#include "bubble_sort.h"

void swap_nodes(my_deque *dq, elem *a, elem *b) {
    if(!dq || !a || !b || a == b) return;

    if(a->next == b) {
        swap_elements(dq, a);
        return;
    }
    if b->next == a) {
        swap_elements(dq, b);
        return;
    }

    elem *a_prev = a->prev;
    elem *a_next = a->next;
    elem *b_prev = b->prev;
    elem *b_next = b->next;

    if(a_prev) a_prev->next = b; else dq->start = b;
    if(a_next) a_next->prev = b; else dq->end = b;

    if(b_prev) b_prev->next = a; else dq->start = a;
    if(b_next) b_next->prev = a; else dq->end = a;

    a->prev = b_prev;
    a->next = b_next;
    b->prev = a_prev;
    b->next = a_next;
}

void swap_elements(my_deque *dq, elem *a){
    if(a == NULL || a->next == NULL ) {
        return;
    }
    elem *b = a->next;
    elem *prev_a = a->prev;
    elem *next_b = b->next;
    
    if(prev_a == NULL) {
        dq->start = b;
        b->prev = NULL;
        b->next = a;
        a->prev = b;
        
        if(next_b == NULL) {
            a->next = NULL;
            dq->end = a;
        }
        else {
            a->next = next_b;
            next_b->prev = a;
        }
        return;
    }
    
    else if(next_b == NULL) {
        dq->end = a;
        
        prev_a->next = b;
        b->prev = prev_a;
        b->next = a;
        
        a->prev = b;
        a->next = NULL;
        return;
    }
    
    else {
        a->next = b->next;
        next_b->prev = a;
        
        b->next = a;
        b->prev = prev_a;
        
        a->prev = b;
        prev_a->next = b;
    }
}


void bubble_sort(my_deque *dq) {
    int n = get_deque_size(dq);
    if (n <= 1) {
        printf("Сортировать нечего \n");
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        elem *current = dq->start;
        for (int j = 0; j < n- 1 - i; j++) {
            if (!current || !current->next) break;
            if(current->data > current->next->data) {
                swap_elements(dq, current);
            }
            current = current->next;
        }
    }
}



