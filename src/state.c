#include "mylex.h"


/* print state information
 */
void state_print(State * state) {
  fprintf(stderr, "State %c \n", state->c);
  if (state->out1 != NULL) {
    fprintf(stderr, "state out1 %c \n", state->out1->c);
  }
  if (state->out2 != NULL) {
    fprintf(stderr, "state out2 %c\n", state->out2->c);
  }
  fprintf(stderr, "\n");
}

/* create new nfa
 */
NFA * nfa_new() {
  NFA * nfa = (NFA *)(malloc(sizeof(NFA)));
  nfa->array = array_new(DEFAULT_SIZE);
  return nfa;
}

/* free nfa
 */
void nfa_free(NFA * nfa) {
  Array * array = nfa->array;
  State * s;
  nfa_travel(nfa, state_print);
  while(array_length(array) > 0) {
    s = array_popback(array);
    free(s);
  }
  array_free(array);
}

/* travel nfa status
 */
static void nfa_state_travel(State * state, nfa_travel_func func) {
  if (state->flag != 0)
    return;
  state->flag = 1;
  func(state);
  if (state->out1 != NULL)
    nfa_state_travel(state->out1, func);
  if (state->out2 != NULL)
    nfa_state_travel(state->out2, func);
}

/* travel nfa
 */
void nfa_travel(NFA * nfa, nfa_travel_func func) {
  int i;
  int length = array_length(nfa->array);
  State * s;
  for (i = 0; i < length; i++) {
    s = array_get_element(nfa->array, i);
    s->flag = 0;
  }
  nfa_state_travel(nfa->start, func);
}

State * nfa_state_new(NFA * nfa, int c, State * out1, State * out2) {
  State * state = (State *) (malloc(sizeof(State)));
  state->c = c;
  state->out1 = out1;
  state->out2 = out2;
  state->flag = 0;
  array_pushback(nfa->array, state);
  state->array = nfa->array;
  return state;
}

StateFrag * state_frag_new(State * start, State ** out1, State ** out2) {
  StateFrag * sf = (StateFrag *)(malloc(sizeof(StateFrag)));
  sf->start = start;
  sf->out1 = out1;
  sf->out2 = out2;
  return sf;
}

void state_frag_free(StateFrag * sf) {
  free(sf);
}

static void connect_state(StateFrag * sf, State * s) {
  if (sf->out1 != NULL)
    *(sf->out1) = s;
  if (sf->out2 != NULL)
    *(sf->out2) = s;
}

NFA * post2nfa(char * postfix) {
  char * p = postfix;

  NFA * nfa = nfa_new();
  Stack * stack = stack_new(DEFAULT_SIZE);

  State * state;
  StateFrag * s1, * s2, * sf;
  while(*p != '\0') {
    switch(*p) {
      case '.':
        s2 = (StateFrag *)stack_pop(stack);
        s1 = (StateFrag *)stack_pop(stack);
        // connect two state fragment
        connect_state(s1, s2->start);
        // create new fragment
        sf = state_frag_new(s1->start, s2->out1, s2->out2);
        state_frag_free(s1);
        state_frag_free(s2);
        stack_push(stack, sf);
        break;
      case '|':
        s1 = (StateFrag *)stack_pop(stack);
        s2 = (StateFrag *)stack_pop(stack);
        // init new state
        state = nfa_state_new(nfa, *p, s1->start, s2->start);
        // create new statement
        sf = state_frag_new(state, s1->out1, s2->out1);
        state_frag_free(s1);
        state_frag_free(s2);
        stack_push(stack, sf);
        break;
      case '?':
        s1 = (StateFrag *)stack_pop(stack);
        // init new state
        state = nfa_state_new(nfa, *p, s1->start, NULL);
        // create new statement
        sf = state_frag_new(state, s1->out1, &state->out1);
        state_frag_free(s1);
        stack_push(stack, sf);
        break;
      case '*':
        s1 = (StateFrag *)stack_pop(stack);
        // init new state
        state = nfa_state_new(nfa, *p, s1->start, NULL);
        // connect two state fragment
        connect_state(s1, state);
        // create new state fragment, there's only one output
        sf = state_frag_new(state, &(state->out2), NULL);
        state_frag_free(s1);
        stack_push(stack, sf);
        break;
      case '+':
        s1 = (StateFrag *)stack_pop(stack);
        // init new state
        state = nfa_state_new(nfa, *p, s1->start, NULL);
        // connect two state fragment
        connect_state(s1, state);
        // create new state fragment
        sf = state_frag_new(s1->start, &(state->out2), NULL);
        state_frag_free(s1);
        stack_push(stack, sf);
        break;
      default:
        state = nfa_state_new(nfa, *p, NULL, NULL);
        sf = state_frag_new(state, &state->out1, &state->out2);
        stack_push(stack, sf);
        break;
    }
    p++;
  }
  sf = stack_pop(stack);
  state = sf->start;
  free(sf);
  stack_free(stack);
  nfa->start = state;
  return nfa;
}
