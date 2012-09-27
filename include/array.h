#ifndef ARRAY_H 
#define ARRAY_H

#define DEFAULT_SIZE 10

struct _Array {
  void ** nodes;
  int size;
  int length;
};

typedef struct _Array Array;
typedef Array Stack;

Array * array_new(int size);
void array_free(Array * array);
void array_pushback(Array * array, void * element);
void * array_get_element(Array * array, int i); 
void * array_popback(Array * array);
int array_length(Array * array);

Stack * stack_new(int size);
void stack_free(Stack * stack);
void stack_push(Stack * stack, void * node);
void * stack_peek(Stack * stack);
void * stack_pop(Stack * stack);

#endif
