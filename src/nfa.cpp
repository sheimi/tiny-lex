#include "mylex.h"
#include <stack>
#include <iostream>
using namespace std;

/*
* Functions for NState
*/
NState::NState(){}
NState::NState(vector<NState*>& v, int c, NState* out1, NState* out2)
  : c(c), out1(out1), out2(out2), out_num(0){
  index = v.size();
  v.push_back(this);
}


/*
* Functions for NStateFrag
*/
NStateFrag::NStateFrag(){}
NStateFrag::NStateFrag(NState* start, NState** out1, NState** out2)
  : start(start), out1(out1), out2(out2) {
}

void NStateFrag::connect_state(NState* state) {
  if (this->out1 != NULL) {
    *(this->out1) = state;
  }
  if (this->out2 != NULL) {
    *(this->out2) = state;
  }
}

NFA::~NFA() {
  vector<NState*>& v = _states;
  vector<NState*>::iterator it;
  for (it=v.begin() ; it < v.end(); it++) {
    delete *it;
  }
}

NFA* NFA::post2nfa(char* postfix) {
  NFA * nfa = new NFA();
  vector<NState*>& states = nfa->_states;
  NStateFrag sf1, sf2;

  stack<NStateFrag> nfrag_stack;
  #define POP(sf) \
    sf = nfrag_stack.top();\
    nfrag_stack.pop();
  #define PUSH(p, s1, s2) \
    nfrag_stack.push(NStateFrag(p, s1, s2));
  NState* state;
  #define STATE_NEW(c, out1, out2)\
    state = new NState(states, c, out1, out2);

  for (char* p = postfix; *p != '\0'; p++) {
    switch (*p) {
      default:
        STATE_NEW(*p, NULL, NULL);
        PUSH(state, &state->out1, &state->out2);
        break;
      case '.':
        POP(sf2);
        POP(sf1);
        sf1.connect_state(sf2.start);
        PUSH(sf1.start, sf2.out1, sf2.out2);
        break;
      case '|':
        POP(sf2);
        POP(sf1);
        STATE_NEW(*p, sf1.start, sf2.start);
        PUSH(state, sf1.out1, sf2.out1);
        break;
      case '?':
        POP(sf1);
        STATE_NEW(*p, sf1.start, NULL);
        PUSH(state, sf1.out1, &state->out1);
        break;
      case '*':
        POP(sf1);
        STATE_NEW(*p, sf1.start, NULL);
        sf1.connect_state(state);
        PUSH(state, &(state->out2), NULL);
        break;
      case '+':
        POP(sf1);
        STATE_NEW(*p, sf1.start, NULL);
        sf1.connect_state(state);
        PUSH(sf1.start, &(state->out2), NULL);
        break;
    }
  }
  POP(sf1);
  // the stack should be empty
  assert(nfrag_stack.empty()); 
  // connect the first state to the nfa
  nfa->_start.out1 = sf1.start;
  return nfa;
}

void NFA::_nfa_travel(NState* state, travel_func func) {
  if (state->flag != 0)
    return;
  state->flag = 1;
  func(state);
  if (state->out1 != NULL)
    _nfa_travel(state->out1, func);
  if (state->out2 != NULL)
    _nfa_travel(state->out2, func);
}

void NFA::nfa_travel(travel_func func) {
  vector<NState*>::iterator it;
  for (it=_states.begin() ; it < _states.end(); it++) {
    (*it)->flag = 0;
  }
  _nfa_travel(_start.out1, func);
}

void print_state(NState* state) {
  cout << (char)state->c << endl;
  if (state->out1 != NULL)
    cout << "out 1: " << (char)state->out1->c << endl;
  if (state->out2 != NULL)
    cout << "out 2: " << (char)state->out2->c << endl;
  cout << endl;
}

void NFA::print_all() {
  nfa_travel(print_state);
}

