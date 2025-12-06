#include "deque.h"
#include "bubble_sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


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
        elem *prev_a = a->prev;
        
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
    if (dq->size <= 1) return;

    for (int i = 0; i < dq->size - 1; i++) {
        elem *current = dq->start;
        for (int j = 0; j < dq->size - 1 - i; j++) {

            if (current->data > current->next->data) {
                swap_elements(dq, current);
            }
            current = current->next;
        }
    }
}


