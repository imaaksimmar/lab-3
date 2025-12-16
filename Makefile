.PHONY: all clean run

PROGRAM = lab-3
FILES = main.o deque.o bubble_sort.o heap_sort.o benchmark_utils.o

all: $(PROGRAM)

$(PROGRAM): $(FILES)
	gcc $^ -o $@

main.o: main.c deque.h bubble_sort.h heap_sort.h benchmark_utils.h
	gcc -c main.c

deque.o: deque.c deque.h
	gcc -c deque.c

bubble_sort.o: bubble_sort.c bubble_sort.h deque.h
	gcc -c bubble_sort.c

heap_sort.o: heap_sort.c heap_sort.h deque.h
	gcc -c heap_sort.c

benchmark_utils.o: benchmark_utils.c benchmark_utils.h deque.h
	gcc -c benchmark_utils.c

run: $(PROGRAM)
	./$(PROGRAM)

clean:
	rm -f $(PROGRAM) *.o
	
