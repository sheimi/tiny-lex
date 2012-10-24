#include "mylex.h"
#include <stack>
#include <iostream>
#include <queue>
using namespace std;


/*
* Functions for NState
*/
NState::NState():end_id(-1){}
NState::NState(vector<NState*>& v, int c, NState* out1,
               NState* out2, int end_id)
  : c(c), out1(out1), out2(out2), out_num(0), end_id(end_id){
  index = v.size();
  v.push_back(this);
}
NState::~NState() {}


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
  foreach(NState* it, _states) {
    delete it;
  }
}

NFA::NFA() {}

NFA::NFA(vector<int> regex, int end_id) {
  vector<int>& postfix = _reg2post(regex);
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

  foreach(int c, postfix) {
    switch (c) {
      default:
        STATE_NEW(state, c, NULL, NULL);
        PUSH(state, &state->out1, &state->out2);
        break;
      case RegexEntry::CAT:
        POP(sf2);
        POP(sf1);
        sf1.connect_state(sf2.start);
        PUSH(sf1.start, sf2.out1, sf2.out2);
        break;
      case RegexEntry::OR:
        POP(sf2);
        POP(sf1);
        STATE_NEW(state, NState::LAMBDA, sf1.start, sf2.start);
        STATE_NEW(state1, NState::LAMBDA, NULL, NULL);
        sf1.connect_state(state1);
        sf2.connect_state(state1);
        PUSH(state, &state1->out1, &state1->out2);
        break;
      case RegexEntry::QUEST:
        POP(sf1);
        STATE_NEW(state, NState::LAMBDA, sf1.start, NULL);
        PUSH(state, sf1.out1, &state->out1);
        break;
      case RegexEntry::STAR:
        POP(sf1);
        STATE_NEW(state, NState::LAMBDA, sf1.start, NULL);
        sf1.connect_state(state);
        PUSH(state, &(state->out2), NULL);
        break;
      case RegexEntry::PLUS:
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
  state->end_id = end_id;
  sf1.connect_state(state);
}

void NFA::_set_flag(int flag) {
  foreach(NState* state, _states) {
    state->flag = flag;
  }
}

NFA* NFA::connect_NFA(NFA* nfa1, NFA* nfa2) {
  NFA* nfa = new NFA();
  vector<NState*>& states = nfa->_states;
  nfa1->_set_flag(-1);
  nfa2->_set_flag(-1);
  NState* state = new NState(states, NState::LAMBDA, NULL, NULL);
  state->out1 = _connect_NFA_inner(states, nfa1->_start.out1);
  state->out2 = _connect_NFA_inner(states, nfa2->_start.out1);
  nfa->_start.out1 = state;
  return nfa;
}

NState* NFA::_connect_NFA_inner(vector<NState*>& states, NState* o_state) {
  if (o_state->flag != -1)
    return states[o_state->flag];
  NState* state = new NState(states, o_state->c, NULL, NULL, o_state->end_id);
  o_state->flag = state->index;
  if (o_state->out1 != NULL) {
    state->out1 = _connect_NFA_inner(states, o_state->out1);
  }
  if (o_state->out2 != NULL) {
    state->out2 = _connect_NFA_inner(states, o_state->out2);
  }
  return state;
}
NFA* NFA::connect_NFA(vector<NFA*>& nfas) {
  NFA* nfa = NULL;
  foreach(NFA* n, nfas) {
    nfa = nfa == NULL ? n : connect_NFA(nfa, n);
  }
  return nfa;
}

vector<int>& NFA::_reg2post(vector<int>& reg) {
  stack<int> symbol_stack;
  vector<int>  reg2;
  bool add = false;
  bool first = true;
  foreach(int c, reg) {
    if (add && !first
        && c != RegexEntry::RIGHT_PTH
        && c != RegexEntry::OR
        && c != RegexEntry::STAR
        && c != RegexEntry::PLUS
        && c != RegexEntry::QUEST) {
      reg2.push_back(RegexEntry::CAT);
    }
    reg2.push_back(c);
    if (!add)
      add = true;
    if (c == RegexEntry::OR)
      add = false;
    if (first && c)
      first = false;
    if (c == RegexEntry::LEFT_PTH)
      first = true;
  }

  #define POP_SYMBOL()\
    if (symbol_stack.size() != 0\
        && symbol_stack.top() != RegexEntry::LEFT_PTH) {\
      result.push_back(symbol_stack.top());\
      symbol_stack.pop();\
    }

  reg.clear();
  vector<int>& result = reg;
  foreach(int c, reg2) {
    switch(c) {
      default:
        result.push_back(c); 
        break;
      case RegexEntry::RIGHT_PTH:
        POP_SYMBOL();
        while (symbol_stack.top() != RegexEntry::LEFT_PTH ) {
          POP_SYMBOL();
        }
        symbol_stack.pop();
        break;
      case RegexEntry::PLUS:
      case RegexEntry::STAR:
        result.push_back(c);
        POP_SYMBOL();
        break;
      case RegexEntry::OR:
      case RegexEntry::CAT:
        POP_SYMBOL();
      case RegexEntry::LEFT_PTH:
        symbol_stack.push(c);
        break;
    }
  }
  POP_SYMBOL();
#ifdef DEBUG
  cerr << "================= SPLIT LINE ==============" <<endl;
  PRINT_VECTOR_INT(cerr, reg2);
  cerr << endl;
  PRINT_VECTOR_INT(cerr, result);
  cerr<< endl;
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
  _set_flag(0);
  _nfa_travel(_start.out1, func);
}

/*j
// this is help function for print_all()
void print_state(NState* state) {
  cout << state->index << " " << state->c << " " << state->end_id << endl;

  set<int> l;
  FA::get_lambda(state, l);
  foreach(int item, l) {
    cout << item << " ";
  }
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
*/

// get the lambda closure of a state
set<int>& NFA::_get_lambda(NState* state, set<int>& result) {
  if (result.find(state->index) != result.end())
    return result;
  
  map<int, set<int> >::iterator map_find = _lambda_cache.find(state->index);
  if (map_find != _lambda_cache.end()) {
    set<int>& fr = (*map_find).second; // find result value
    result.insert(fr.begin(), fr.end());
    return fr;
  }

  result.insert(state->index);
  if (state->c == NState::LAMBDA) {
    if (state->out1 != NULL) {
      _get_lambda(state->out1, result);
    }
    if (state->out2 != state->out1 && state->out2 != NULL) {
      _get_lambda(state->out2, result);
    }
  }
  _lambda_cache[state->index] = result;
  return _lambda_cache[state->index];
}

set<int>& NFA::get_lambda(NState* state) {
  map<int, set<int> >::iterator map_find = _lambda_cache.find(state->index);
  if (map_find != _lambda_cache.end()) {
    set<int>& fr = (*map_find).second; // find result value
    return fr;
  }
  set<int> result;
  return _get_lambda(state, result);
}

set<int>& NFA::get_lambda(set<int>& states) {
  map<set<int>, set<int> >::iterator map_find = _lambda_set_cache.find(states);
  if (map_find != _lambda_set_cache.end()) {
    set<int>& fr = (*map_find).second; // find result value
    return fr;
  }
  set<int> result;
  foreach(int item, states) {
    _get_lambda(_states[item], result);
  }
  _lambda_set_cache[states] = result;
  return _lambda_set_cache[states];
}

DFA* NFA::construct_DFA() {
  map<set<int>, DState*> states;

  queue<set<int> > squeue;
  set<set<int> > dstate_id_logger; // to log the id of state
  #define SQUEUE_PUSH(item)\
    squeue.push(item);\
    dstate_id_logger.insert(item);\

  NState* start = _start.out1;
  set<int>& result = get_lambda(start);
  SQUEUE_PUSH(result);
  bool first = true;
  while(!squeue.empty()) {
    set<int>& s_set = squeue.front();
    DState* d_state = new DState(s_set);
    d_state->is_first = first;
    first = false;
    map<int, set<int> >& next_states = d_state->next_states;
    states[s_set] = d_state;
    foreach(int item, s_set) {
      NState* state = _states[item];
      if (state->c == NState::LAMBDA)
        continue;
      int convert_c = state->c;
      if (state->out1 != NULL) {
        set<int>& next_set = next_states[convert_c];
        next_set.insert(state->out1->index);
      } else {
        d_state->is_end = true;
        // smaller end_id preferred
        if (d_state->end_id == -1 || d_state->end_id > state->end_id) {
          d_state->end_id = state->end_id;
        }
      }
      if (state->out1 != NULL && state->out2 != NULL)
        assert(state->out1 == state->out2);
    }

    typedef map<int, set<int> > map_t;
    foreach(map_t::value_type& item, next_states) {
      set<int>& tmp = get_lambda(item.second);
      item.second = tmp;
      if (dstate_id_logger.find(tmp) == dstate_id_logger.end()) {
        SQUEUE_PUSH(tmp);
      }
    }
    squeue.pop();
  }

#ifdef DEBUG
  cerr << endl << endl << endl;
  cerr << "================= SPLIT LINE ==============" <<endl;
  #define PRINT_SET(s)\
    cerr << "<";\
    foreach(int item_s, s) {\
      cerr << item_s << ", ";\
    }\
    cerr << ">";\

  typedef map<set<int>, DState*> map_t1;
  typedef map<int, set<int> > map_t2;
  foreach(map_t1::value_type& item1, states) {
    const set<int>& s = item1.first;
    cerr << " end?: " << item1.second->is_end << "    ";
    cerr << " end_id: " << item1.second->end_id << "    ";
    PRINT_SET(s);
    foreach(map_t2::value_type& item2, item1.second->next_states) {
      cerr << "\t\t" << (char)item2.first << " => ";
      PRINT_SET(item2.second);
    }
    cerr << endl;
  }
#endif
  DFA* dfa = new DFA(states);

  // free DStates may use smart_ptr in the future
  // TODO
  typedef map<set<int>, DState*> map_t;
  foreach (map_t::value_type& item, states) {
    DState* ds = item.second;
    delete ds;
  }

  return dfa;
  
}
