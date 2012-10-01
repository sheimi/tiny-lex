#include "dfa.h"
#include "nfa.h"
#include <iostream>

DFA::DFA(map<set<int>, DState*>& states) {
  map<set<int>, DState*>::iterator it;
  map<set<int>, int> id_map;

  #define GET_STATE_BY_ID(state, old_state)\
    if (id_map.find(old_state->identifier) == id_map.end()) {\
      state = new DFAState();\
      state->identifier = _states.size();\
      state->is_end = old_state->is_end;\
      _states.push_back(state);\
      id_map[old_state->identifier] = state->identifier;\
    } else {\
      state = _states[id_map[old_state->identifier]];\
    }

  for(it = states.begin(); it != states.end(); it++) {
    DState* dstate = (*it).second;
    DFAState* dfa_state;
    GET_STATE_BY_ID(dfa_state, dstate);

    map<int, set<int> >::iterator it_next;
    map<int, set<int> >& next_map = dstate->next_states;
    for(it_next = next_map.begin(); it_next != next_map.end(); it_next++) {
      const int convert_char = (*it_next).first;
      const set<int>& next_id = (*it_next).second;
      DFAState* next_dfa_state;
      GET_STATE_BY_ID(next_dfa_state, states[next_id]);
      dfa_state->nexts[convert_char] = next_dfa_state->identifier;
    }
  }

#ifdef DEBUG
  cout << endl << endl << endl;
  cout << "================= SPLIT LINE ==============" <<endl;
  vector<DFAState*>::iterator it_v;
  for (it_v = _states.begin(); it_v != _states.end(); it_v++) {
    cout << (*it_v)->identifier << " " << (*it_v)->is_end << "\t\t";
    map<int, int>::iterator it_m;
    map<int, int>& m = (*it_v)->nexts;
    for (it_m = m.begin(); it_m != m.end(); it_m++) {
      cout << (char)(*it_m).first << " => " << (*it_m).second << "\t";
    }
    cout << endl;
  }
#endif

}

DFA::~DFA() {
  vector<DFAState*>::iterator it_v;
  for (it_v = _states.begin(); it_v != _states.end(); it_v++) {
    delete (*it_v);
  }
}

bool DFA::match(string input) {
  int id = 0;
  string::iterator it;
  for (it = input.begin(); it != input.end(); it++) {
    DFAState* state = _states[id];
    if (state->nexts.find(*it) == state->nexts.end())
      return false;
    id = state->nexts[*it];
  }
  return _states[id]->is_end;
}
