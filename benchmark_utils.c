#include "deque.h"
#include "bubble_sort.h"
#include "heap_sort.h"
#include <time.h>

double get_time_bubble_sort(my_deque *dq) {
    clock_t start = clock();
    bubble_sort(dq);
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

double get_time_heap_sort(my_deque *dq) {
    clock_t start = clock();
    heap_sort(dq);
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}
