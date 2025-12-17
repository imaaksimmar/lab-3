#include "deque.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int get_deque_size(my_deque* dq) {
    int count = 0;
    elem *current = dq->start;
    while(current) {
        count++;
        current = current->next;
    }
    return count;
}

elem* get_elem_at_index(my_deque *dq, int index) {
    if(!dq || index < 0) return NULL;
    
    elem *current = dq->start;
    int i = 0;
    while (current && i < index) {
        current = current->next;
        i++;
    }
    return current;
}


void add_front(my_deque *dq, int data) {
    elem *new_elem = malloc(sizeof(elem));
    if(new_elem == NULL) {
        printf("Ошибка. Память не выделилась \n");
        return;
    }
    new_elem->data = data;
    new_elem->prev = NULL;
    new_elem->next = dq->start;
    
    if(dq->start == NULL) {
        dq->end = dq->start = new_elem;
    }
    else {
        dq->start->prev = new_elem;
        dq->start = new_elem;
    }
}

void add_back(my_deque *dq, int data) {
    elem *new_elem = malloc(sizeof(elem));
    if(new_elem == NULL) {
        printf("Ошибка. Память не выделилась \n");
        return;
    }
    new_elem->data = data;
    new_elem->next = NULL;
    new_elem->prev = dq->end;
    
    if(dq->end == NULL) {
        dq->end = dq->start = new_elem;
    }
    else {
        dq->end->next = new_elem;
        dq->end = new_elem;
    }
}

void pop_front(my_deque *dq) {
    if(dq->start == NULL) {
        printf("Ошибка. Дек пуст \n");
        return;
    }
    
    elem *old = dq->start;
    dq->start = dq->start->next;
    
    if( dq->start == NULL) {
        dq->end = NULL;
    }
    else {
        dq->start->prev = NULL;
    }
    
    free(old);
}

void pop_back(my_deque *dq) {
    if(dq->end == NULL) {
        printf("Ошибка. Дек пуст \n");
        return;
    }
    elem *old = dq->end;
    dq->end = dq->end->prev;
    
    if(dq->end == NULL) {
        dq->start = NULL;
    }
    else {
        dq->end->next = NULL;
    }
    
    free(old);
}

void add_at_index(my_deque *dq, int index, int data) {
    int n = get_deque_size(dq);
    if (index<0 || index>n) {
        printf("Ошибка. Нельзя добавить элемент по этому индексу \n");
        return;
    }
    
    if (index == 0) {
        add_front(dq, data);
        return;
    }
    if (index == n) {
        add_back(dq, data);
        return;
    }

    elem *new_elem = malloc(sizeof(elem));
    if (new_elem == NULL) {
        printf("Ошибка. Память не выделилась \n");
        return;
    }
    
    new_elem->data = data;
    elem *current;
    if (index <= n / 2) {
        current = dq->start;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
    }
    else {
        current = dq->end;
        for (int i = n - 1; i > index - 1; i--) {
            current = current->prev;
        }
    }

    new_elem->prev = current;
    new_elem->next = current->next;
    
    if(current->next != NULL) {
        current->next->prev = new_elem;
    }
    current->next = new_elem;
}
    
void pop_at_index(my_deque *dq,  int index) {
    int n = get_deque_size(dq);
    if(index<0 || index>=n) {
        printf("Ошибка. Нельзя удалить элемент по этому индексу \n");
        return;
    }
    if(index == 0){
        pop_front(dq);
        return;
    }
    if(index == n-1) {
        pop_back(dq);
        return;
    }
    elem *current;
    
    if(index < n/2) {
        current = dq->start;
        for(int i=0; i<index; i++) {
            current = current->next;
        }
    }
    else {
        current = dq->end;
        for(int i = n-1 ; i>index; i--){
            current = current->prev;
        }
    }
    
    current->prev->next = current->next;
    current->next->prev = current->prev;
    
    free(current);
}


my_deque *create_deque() {
    my_deque *dq = malloc(sizeof(my_deque));
    if(dq == NULL) {
        return NULL;
    }
    dq->start = dq->end = NULL;
    return dq;
}

void print_deque(my_deque *dq) {
    elem *current = dq->start;
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

void free_deque(my_deque *dq) {
    while(dq->start != NULL) {
        pop_front(dq);
    }
    free(dq);
}


int get_value_at_index(my_deque *dq, int index) {
    int n = get_deque_size(dq);
    if (index<0 || index>=n)
        return 0;

    elem *current;

    if (index < n / 2) {
        current = dq->start;
        for (int i = 0; i<index; i++)
            current = current->next;
    }

    else {
        current = dq->end;
        for (int i = n - 1; i>index; i--)
            current = current->prev;
    }

    return current->data;
}




int is_valid_integer(const char *str) {
    if(str==NULL || *str == '\0') return 0;

    char *endptr;
    errno = 0;
    long val = strtol(str, &endptr, 10);
    return (errno == 0) && (*endptr == '\0') && (str != endptr);
}


my_deque *read_deque_from_input(void) {
    char buffer[4096];
    if (!fgets(buffer, sizeof(buffer), stdin)) {
        return NULL;
    }

    my_deque *dq = create_deque();
    char *token = strtok(buffer, " \t\n\r");

    while (token) {
        if (*token != '\0') {
            if (is_valid_integer(token)) {
                long num = strtol(token, NULL, 10);
                add_back(dq, (int)num);
            } else {
                free_deque(dq);
                return NULL;
            }
        }
        token = strtok(NULL, " \t\n\r");
    }
    return dq;
}


my_deque *read_deque_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if(file == NULL) return NULL;

    my_deque *dq = create_deque();
    int value;
    while(fscanf(file, "%d", &value)== 1) {
        add_back(dq, value);
    }
    
    fclose(file);
    return dq;
}


void write_deque_to_file(my_deque *dq, const char *filename) {
    FILE *file = fopen(filename, "w");
    if(file == NULL) return;

    elem *current = dq->start;
    while(current != NULL) {
        fprintf(file, "%d ", current->data);
        current = current->next;
    }
    fclose(file);
}

