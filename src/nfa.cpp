#include "mylex.h"
#include <stack>
#include <iostream>
#include <queue>
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
        STATE_NEW(NState::LAMBDA, sf1.start, sf2.start);
        PUSH(state, sf1.out1, sf2.out1);
        break;
      case '?':
        POP(sf1);
        STATE_NEW(NState::LAMBDA, sf1.start, NULL);
        PUSH(state, sf1.out1, &state->out1);
        break;
      case '*':
        POP(sf1);
        STATE_NEW(NState::LAMBDA, sf1.start, NULL);
        sf1.connect_state(state);
        PUSH(state, &(state->out2), NULL);
        break;
      case '+':
        POP(sf1);
        STATE_NEW(NState::LAMBDA, sf1.start, NULL);
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
  STATE_NEW(NState::END, NULL, NULL);
  sf1.connect_state(state);
  return nfa;
}

// actrual recursive travel
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

// this is help function for print_all()
void print_state(NState* state) {
  cout << state->index << endl;

  set<int> l = NFA::get_lambda(state);
  set<int>::iterator it;
  for ( it=l.begin() ; it != l.end(); it++ )
    cout << *it << " ";
  cout << endl;
  if (state->out1 != NULL)
    cout << "out 1: " << state->out1->index << endl;
  if (state->out2 != NULL)
    cout << "out 2: " << state->out2->index << endl;
  cout << endl;
}

void NFA::print_all() {
  nfa_travel(print_state);
}

// get the lambda closure of a state
set<int> NFA::get_lambda(NState* state) {
  set<int> result;
  result.insert(state->index);
  if (state->c == NState::LAMBDA) {
    if (state->out1 != NULL) {
      set<int> r = get_lambda(state->out1);
      result.insert(r.begin(), r.end());
    }
    if (state->out2 != state->out1 && state->out2 != NULL) {
      set<int> r = get_lambda(state->out2);
      result.insert(r.begin(), r.end());
    }
  }
  return result;
}

set<int> NFA::get_lambda(set<int> states) {
  set<int> result;
  for(set<int>::iterator it = states.begin(); it != states.end(); it++) {
    set<int> r = get_lambda(_states[*it]);
      result.insert(r.begin(), r.end());
  }
  return result;
}

void NFA::construct_DFA() {
  map<set<int>, DState*> states;
  queue<set<int> > squeue;
  NState* start = _start.out1;
  squeue.push(get_lambda(start));
  while(!squeue.empty()) {
    cout << endl;
    set<int> s_set =squeue.front();
    squeue.pop();

    // for debug
    set<int>::iterator it;
    for ( it=s_set.begin() ; it != s_set.end(); it++ )
      cout << *it << " ";
    cout << endl;
    // for debug end

    DState* d_state = new DState(s_set);
    map<int, set<int> >& next_states = d_state->next_states;
    bool& is_end = d_state->is_end;
    states[s_set] = d_state;
    for(set<int>::iterator it = s_set.begin(); it != s_set.end(); it++) {
      NState* state = _states[*it];
      if (state->c == NState::LAMBDA)
        continue;
      int convert_c = state->c;
      if (state->out1 != NULL) {
        set<int>& next_set = next_states[convert_c];
        next_set.insert(state->out1->index);
      } else {
        is_end = true;
      }
      assert(state->out1 == state->out2);
    }
    for(map<int, set<int> >::iterator it = next_states.begin();
        it != next_states.end(); it++) {
      (*it).second = get_lambda((*it).second);
      if (states.find((*it).second) == states.end())
        squeue.push((*it).second);
    }
  }
  // for debug
  cout << endl << endl << endl;

  #define PRINT_SET(s)\
    cout << "<";\
    for(set<int>::iterator its = s.begin(); its != s.end(); its++) {\
      cout << *its << ", ";\
    }\
    cout << ">";\

  for(map<set<int>, DState*>::iterator it = states.begin();
      it != states.end(); it++) {
    const set<int>& s = (*it).first;
    cout << " end?: " << (*it).second->is_end << "    ";
    PRINT_SET(s);
    for(map<int, set<int> >::iterator itm = (*it).second->next_states.begin();
        itm != (*it).second->next_states.end(); itm++) {
      cout << "\t\t" << (char)(*itm).first << " => ";
      PRINT_SET((*itm).second);
    }
    cout << endl;
  }
  
}