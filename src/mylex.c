#include "mylex.h"

int main(int argc, char ** args) {
  /*
  State * state;
  int i = 20;
  
  Stack * stack = new_stack(20);

  for (i = 0; i < 50; i++) {
    state = new_state(i, NULL, NULL);
    fprintf(stderr, "PUSH BEFOR %d %d\n", stack->length, stack->size);
    push_stack(stack, state);
    fprintf(stderr, "PUSH END %d %d\n\n", stack->length, stack->size);
  }
  for (i = 0; i < 50; i++) {
    fprintf(stderr, "POP BEFOR %d %d\n", stack->length, stack->size);
    state = (State *)pop_stack(stack);
    fprintf(stderr, "POP END %d %d\n\n", stack->length, stack->size);
    free_state(state);
  }
  peek_stack(stack);
  free_stack(stack);
  */
  NFA * nfa = post2nfa("abc.*.d.");
  nfa_free(nfa);
  return 0;
}
