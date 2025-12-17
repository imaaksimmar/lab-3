#include "deque.h"
#include "bubble_sort.h"
#include "benchmark_utils.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]) {
    
    if (argc == 3 && strcmp(argv[1], "--benchmark") == 0) {
        my_deque *orig = read_deque_from_file(argv[2]);
        if (orig == NULL || get_deque_size(orig) == 0) {
            printf("Ошибка чтения %s \n", argv[2]);
            return 1;
        }

        my_deque *bubble = create_deque(), *heap = create_deque();
        elem *current = orig->start;
        while(current){
            add_back(bubble, current->data);
            add_back(heap, current->data);
            current = current->next;
        }

        double time_bubble = get_time_bubble_sort(bubble);
        double time_heap = get_time_heap_sort(heap);

        printf("%d,%.6f,%.6f\n", get_deque_size(orig), time_bubble, time_heap);

        free_deque(orig);
        free_deque(bubble);
        free_deque(heap);
        return 0;
    }
    
    if (argc==3 && strcmp(argv[1], "--file")== 0) {
        my_deque *dq = read_deque_from_file(argv[2]);
        if (dq == NULL) {
            printf("Не удалось прочитать файл \n");
            return 1;
        }

        write_deque_to_file(dq, "input.txt");
        printf("Исходный ряд: \n");
        print_deque(dq);
        printf("\n");

        my_deque *sorted = create_deque();
        elem *current = dq->start;
        while(current) {
            add_back(sorted, current->data);
            current = current->next;
        }
        bubble_sort(sorted);

        write_deque_to_file(sorted, "sorted.txt");
        printf("Отсортированный ряд: \n");
        print_deque(sorted);
        printf("\n");
        
        free_deque(dq);
        free_deque(sorted);
        return 0;
    }

    
    if (argc != 1) {
        printf("Неверный формат \n");
        return 1;
    }
    while(1) {
        printf("Введите последовательность чисел через пробел: ");
        my_deque *dq = read_deque_from_input();
        if (dq==NULL || get_deque_size(dq)==0) {
                printf("Ошибка: введены некорректные значения \n");
            continue;
        }

        my_deque *sorted = create_deque();
        elem *current = dq->start;
        while(current) {
            add_back(sorted, current->data);
            current = current->next;
        }
        bubble_sort(sorted);

        printf("Исходный ряд: \n");
        print_deque(dq);
        printf("\nОтсортированный ряд: \n");
        print_deque(sorted);
        printf("\n");

        free_deque(dq);
        free_deque(sorted);

        printf("Повторить? Введите 1, если да: ");
        char choice;
        
        if(scanf(" %c", &choice)!= 1 || choice!='1') {
            int c;
            while((c = getchar()) != '\n' && c != EOF); //-
            break;
        }
        int c;
        while((c = getchar()) != '\n' && c != EOF);
    }

    return 0;
}
