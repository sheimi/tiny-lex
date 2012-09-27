#ifndef STATE_H
#define STATE_H

#include "array.h"

typedef struct _State {
  int c;
  struct _State * out1;
  struct _State * out2;
  Array * array;
  int flag;
} State;

typedef struct _StateFrag {
  State * start;
  State ** out1;
  State ** out2;
} StateFrag;

typedef struct _NFA {
  State * start;
  Array * array;
} NFA;


void nfa_free(NFA * nfa);
NFA * nfa_new();

State * nfa_state_new(NFA * nfa, int c, State * out1, State * out2);
typedef void (* nfa_travel_func)(State * state);
void nfa_travel(NFA * nfa, nfa_travel_func func);

StateFrag * state_frag_new(State * start, State ** out1, State ** out2);
void state_frag_free(StateFrag * sf);


NFA * post2nfa(char * postfix);

#endif
