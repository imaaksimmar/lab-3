#ifndef DEQUE_H
#define DEQUE_H

typedef struct element {
    int data;
    struct element *prev;
    struct element *next;
} elem;

typedef struct my_deque {
    elem *start;
    elem *end;
} my_deque;

void add_front(my_deque *dq, int data);
void add_back(my_deque *dq, int data);
void add_at_index(my_deque *dq, int index, int data);

void pop_front(my_deque *dq);
void pop_back(my_deque *dq);
void pop_at_index(my_deque *dq, int index);

my_deque* create_deque(void);
void print_deque(my_deque *dq);
void free_deque(my_deque *dq);
int get_value_at_index(my_deque *dq, int index);

my_deque* read_deque_from_input(void);
my_deque* read_deque_from_file(const char *filename);
void write_deque_to_file(my_deque *dq, const char *filename);
int is_valid_integer(const char *str);

#endif


