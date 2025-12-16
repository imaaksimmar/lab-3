#include "heap_sort.h"

void push(my_deque* dq, int value) {
    add_back(dq, value);
    int k= dq->size-1;
    
    while(k>0) {
        int parent = (k-1)/2;
        if(get_value_at_index(dq,k) >= get_value_at_index(dq, parent)) {
            break;
        }
        int val_k = get_value_at_index(dq,k);
        int val_p = get_value_at_index(dq, parent);
        
        pop_at_index(dq,k);
        add_at_index(dq,k,val_p);
        
        pop_at_index(dq,parent);
        add_at_index(dq,parent, val_k);
        
        k = parent;
    }
}


int pop(my_deque *dq) {
    int val_last = get_value_at_index(dq,dq->size-1);
    int val_first = get_value_at_index(dq,0);
    
    pop_front(dq);
    add_front(dq, val_last);
    pop_back(dq);
    
    int i = 0;
    while(2*i+1 < dq->size) {
        int min_index = i;
        int left_index = 2*i+1;
        int right_index = 2*i+2;

        if(left_index< dq->size && get_value_at_index(dq,left_index)< get_value_at_index(dq,min_index)) min_index = left_index;
        
        if(right_index < dq->size && get_value_at_index(dq,right_index) < get_value_at_index(dq,min_index)) min_index = right_index;

        if(min_index == i) break;

        int temp = get_value_at_index(dq,min_index);
        
        pop_at_index(dq,min_index);
        add_at_index(dq,min_index, get_value_at_index(dq,i));
        pop_at_index(dq,i);
        add_at_index(dq,i,temp);
        i = min_index;
    }
  return val_first;
}


void heap_sort(my_deque *dq) {
    if(dq->size <= 1) {
        return;
    }
    my_deque *heap = create_deque();

    elem *current = dq->start;
    while(current) { 
        push(heap, current->data);
        current = current->next;
    }

    while(dq->start) {
        pop_front(dq);
    }

    while(heap->size > 0) {
        int val = pop(heap);
        add_back(dq, val);
    }

    free_deque(heap);
}
