#include "mylex.h"

// extend array size
static void array_extend(Array * array) {
  if (array->length < array->size)
    return;
  int o_size = array->size;
  array->size *= 2;
  void ** _array = (void **)(malloc(sizeof(void *) * array->size));
  memcpy(_array, array->nodes, o_size * sizeof(void *));
  array->nodes = _array;
}

// init an array
Array * array_new(int size) {
  if (size <= 0)
    size = DEFAULT_SIZE;
  Array * array = (Array *)(malloc(sizeof(Array)));
  array->nodes = (void **)(malloc(sizeof(void *) * size));
  array->size = size;
  array->length = 0;
  return array;
}

// get array length
int array_length(Array * array) {
  return array->length;
}

// distory array
void array_free(Array * array) {
  free(array->nodes);
  free(array);
}

// get element from array
void * array_get_element(Array * array, int i) {
  assert(array->length > i);
  return array->nodes[i];
}

// push back element
void array_pushback(Array * array, void * element) {
  int index = array->length;
  array_extend(array);
  array->nodes[index] = element;
  array->length++;
}

// pop back 
void * array_popback(Array * array) {
  void * e = array_get_element(array, array->length - 1);
  array->length--;
  return e;
}

// init a stack
Stack * stack_new(int size) {
  return (Stack *)array_new(size);
}

// distory stack
void stack_push(Stack * stack, void * node) {
  array_pushback(stack, node);
}

// peek stack
void * stack_peek(Stack * stack) {
  assert(stack->length > 0);
  return array_get_element(stack, stack->length - 1);
}

// pop stack
void * stack_pop(Stack * stack) {
  assert(stack->length > 0);
  return array_popback(stack);
}

// free stack
void stack_free(Stack * stack) {
  if (stack->length != 0)
    err_msg("There's elements which remains in the stack");
  array_free(stack);
}
