#include "mylex.h"
#include "dfa.h"
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


NFA::NFA(string regex) {
  string postfix = _reg2post(regex);
  vector<NState*>& states = _states;
  NStateFrag sf1, sf2;

  stack<NStateFrag> nfrag_stack;
  #define POP(sf) \
    sf = nfrag_stack.top();\
    nfrag_stack.pop();
  #define PUSH(p, s1, s2) \
    nfrag_stack.push(NStateFrag(p, s1, s2));
  NState* state;
  NState* state1;
  #define STATE_NEW(state, c, out1, out2)\
    state = new NState(states, c, out1, out2);

  string::iterator it;
  for (it = postfix.begin(); it != postfix.end(); it++) {
    switch (*it) {
      default:
        STATE_NEW(state, *it, NULL, NULL);
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
        STATE_NEW(state, NState::LAMBDA, sf1.start, sf2.start);
        STATE_NEW(state1, NState::LAMBDA, NULL, NULL);
        sf1.connect_state(state1);
        sf2.connect_state(state1);
        PUSH(state, &state1->out1, &state1->out2);
        break;
      case '?':
        POP(sf1);
        STATE_NEW(state, NState::LAMBDA, sf1.start, NULL);
        PUSH(state, sf1.out1, &state->out1);
        break;
      case '*':
        POP(sf1);
        STATE_NEW(state, NState::LAMBDA, sf1.start, NULL);
        sf1.connect_state(state);
        PUSH(state, &(state->out2), NULL);
        break;
      case '+':
        POP(sf1);
        STATE_NEW(state, NState::LAMBDA, sf1.start, NULL);
        sf1.connect_state(state);
        PUSH(sf1.start, &(state->out2), NULL);
        break;
    }
  }
  POP(sf1);
  // the stack should be empty
  assert(nfrag_stack.empty()); 
  // connect the first state to the nfa
  _start.out1 = sf1.start;
  STATE_NEW(state, NState::END, NULL, NULL);
  sf1.connect_state(state);
}

string NFA::_reg2post(string& reg) {
  stack<char> symbol_stack;
  string reg2;
  string::iterator it;
  bool add = false;
  bool first = true;
  for (it = reg.begin(); it != reg.end(); it++) {
    if (add && !first && *it != ')' && *it != '|'
        && *it != '*' && *it != '+' && *it != '?') {
      reg2.push_back('.');
    }
    reg2.push_back(*it);
    if (!add)
      add = true;
    if (*it == '|')
      add = false;
    if (first && *it)
      first = false;
    if (*it == '(')
      first = true;
  }

  #define POP_SYMBOL()\
    if (symbol_stack.size() != 0\
        && symbol_stack.top() != '(') {\
      result.push_back(symbol_stack.top());\
      symbol_stack.pop();\
    }

  string result;
  for (it = reg2.begin(); it != reg2.end(); it++) {
    switch(*it) {
      default:
        result.push_back(*it); 
        it++;
        if (*it != '*') {
          POP_SYMBOL();
        }
        it--;
        break;
      case ')':
        while (symbol_stack.top() != '(') {
          result.push_back(symbol_stack.top());
          symbol_stack.pop();
        }
        symbol_stack.pop();
        break;
      case '+':
      case '*':
        result.push_back(*it);
        POP_SYMBOL();
        break;
      case '|':
      case '(':
      case '.':
        symbol_stack.push(*it);
        break;
    }
  }
#ifdef DEBUG
  cout << "================= SPLIT LINE ==============" <<endl;
  cout << reg2 << endl;
  cout << result << endl;
#endif
  assert(symbol_stack.empty());
  return result;
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
  cout << state->index << " " << state->c << endl;

  set<int> l;
  NFA::get_lambda(state, l);
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
void NFA::get_lambda(NState* state, set<int>& result) {
  if (result.find(state->index) != result.end())
    return;
  result.insert(state->index);
  if (state->c == NState::LAMBDA) {
    if (state->out1 != NULL) {
      get_lambda(state->out1, result);
    }
    if (state->out2 != state->out1 && state->out2 != NULL) {
      get_lambda(state->out2, result);
    }
  }
}

void NFA::get_lambda(set<int> states, set<int>& result) {
  for(set<int>::iterator it = states.begin(); it != states.end(); it++) {
    get_lambda(_states[*it], result);
  }
}

DFA* NFA::construct_DFA() {
  map<set<int>, DState*> states;
  queue<set<int> > squeue;
  NState* start = _start.out1;
  set<int> result;
  get_lambda(start, result);
  squeue.push(result);
  bool first = true;
  while(!squeue.empty()) {
    set<int> s_set =squeue.front();
    squeue.pop();

    DState* d_state = new DState(s_set);
    d_state->is_first = first;
    first = false;
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
      if (state->out1 != NULL && state->out2 != NULL)
        assert(state->out1 == state->out2);
    }
    for(map<int, set<int> >::iterator it = next_states.begin();
        it != next_states.end(); it++) {
      set<int> tmp;
      get_lambda((*it).second, tmp);
      (*it).second = tmp;
      if (states.find((*it).second) == states.end())
        squeue.push((*it).second);
    }
  }

#ifdef DEBUG
  cout << endl << endl << endl;
  cout << "================= SPLIT LINE ==============" <<endl;
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
#endif


  DFA* dfa = new DFA(states);

  // free DStates [may use smart_ptr in the future
  for(map<set<int>, DState*>::iterator it = states.begin();
      it != states.end(); it++) {
    DState* ds = (*it).second;
    delete ds;
  }

  return dfa;
  
}
