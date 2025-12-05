struct element {
    int data;
    struct element *prev;
    struct element *next;
};
typedef struct element elem;


typedef struct my_deque {
    elem *start;
    elem *end;
    int size;
} my_deque;

my_deque* create_deque(void);

void add_front(my_deque *dq, int data);
void add_back(my_deque *dq, int data);
void add_at_index(my_deque *dq, int index, int data);


void pop_front(my_deque *dq);
void pop_back(my_deque *dq);
void pop_at_index(my_deque *dq, int index);

void print_deque(my_deque *dq);
void free_deque(my_deque *dq);

