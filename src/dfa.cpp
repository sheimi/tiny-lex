#include "dfa.h"
#include "nfa.h"
#include <iostream>
#include <queue>

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
  print();
#endif

}

DFA::~DFA() {
  _release_states(_states);
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

void DFA::print() {
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
  cout << endl << endl << endl;
}

/* to minimize the DFA */
void DFA::minimize() {
  int set_iterator = 256;
  int* set_log = new int[_states.size()];
  memset(set_log, set_iterator, sizeof(int) * _states.size());
  _divide_by_end(set_iterator, set_log);
  _divide_by_outkey(set_iterator, set_log);
  _divide_by_next(set_iterator, set_log);

  vector<DFAState*> min_states;
  map<int, int> id_map;
  vector<DFAState*>::iterator vi;
  for (vi = _states.begin(); vi != _states.end(); vi++) {
    _construct_min_dfa(*vi, min_states, id_map, set_log);
  }

  _release_states(_states);
  _states.resize(min_states.size());
  copy(min_states.begin(), min_states.end(), _states.begin());
 
#ifdef DEBUG
  print();
#endif

  delete[] set_log;
}

int DFA::_construct_min_dfa(DFAState* o_state, vector<DFAState*>& min_states,
                           map<int, int>& id_map, int* set_log) {
  int o_id = o_state->identifier;
  map<int, int>::iterator result = id_map.find(set_log[o_id]);
  if (result != id_map.end())
    return (*result).second;
  int id = min_states.size();
  DFAState* state = new DFAState();
  state->identifier = id;
  id_map[set_log[o_id]] = id;
  state->is_end = o_state->is_end;
  min_states.push_back(state);

  map<int, int>::iterator mi;
  for (mi = o_state->nexts.begin(); mi != o_state->nexts.end(); mi++) {
    int next_key = (*mi).first;
    DFAState* next = _states[(*mi).second];
    int next_value = _construct_min_dfa(next, min_states, id_map, set_log);
    state->nexts[next_key] = next_value;
  }
  return id;
}

/* make the differ kind of state in different set: end or not end */
void DFA::_divide_by_end(int& set_iterator, int* set_log) {
  vector<DFAState*>::iterator it_v;
  set_iterator++;
  for (it_v = _states.begin(); it_v != _states.end(); it_v++) {
    int id = (*it_v)->identifier;
    if ((*it_v)->is_end) {
      set_log[id] = set_iterator;
    }
  }
}

/* make state with different next states key in different set */
void DFA::_divide_by_outkey(int& set_iterator, int* set_log) {
  map<set<int>, int> output_log;
  vector<DFAState*>::iterator it_v;
  for (it_v = _states.begin(); it_v != _states.end(); it_v++) {
    int id = (*it_v)->identifier;
    map<int, int>& output = (*it_v)->nexts;

    // get next states key set
    set<int> output_set;
    map<int, int>::iterator it_m;
    for (it_m = output.begin(); it_m != output.end(); it_m++) {
      output_set.insert((*it_m).first);
    }
    // put previous set_identifier into the set
    output_set.insert(set_log[id]);
    map<set<int>, int>::iterator result = output_log.find(output_set);
    if (result != output_log.end()) {
      set_log[id] = (*result).second; 
    } else {
      set_iterator++;
      set_log[id] = set_iterator; 
      output_log[output_set] = set_iterator;
    }
  }
}

/* divide the set by the next states */
void DFA::_divide_by_next(int& set_iterator, int* set_log) {
  map<int, set<int> > equal_sets;
  for (unsigned int i = 0; i < _states.size(); i++) {
    map<int, set<int> >::iterator result = equal_sets.find(set_log[i]);
    if (result != equal_sets.end()) {
      (*result).second.insert(i);
    } else {
      set<int> tmp;
      tmp.insert(i);
      equal_sets[set_log[i]] = tmp;
    }
  }
  map<int, set<int> >::iterator mi;
  for (mi = equal_sets.begin(); mi != equal_sets.end(); mi++) {
    _divide_by_next_inner(set_iterator, set_log, (*mi).second);
  }
}

/* recursively divide the set */
void DFA::_divide_by_next_inner(int& set_iterator, int* set_log,
                               set<int>& equal_set) {
  if (equal_set.size() == 1)
    return;
  int* set_log_old = new int[_states.size()];
  memcpy(set_log_old, set_log, sizeof(int) * _states.size());

  map<map<int, int>, int> next_log;
  map<int, set<int> > next_log_set;
  set<int>::iterator equal_set_i;
  // divider the set                                 
  for (equal_set_i = equal_set.begin();
       equal_set_i != equal_set.end();
       equal_set_i++) {
    DFAState* state = _states[*equal_set_i];
    map<int, int> tmp_map;
    map<int, int>& nexts = state->nexts;
    map<int, int>::iterator it_m;
    for (it_m = nexts.begin(); it_m != nexts.end(); it_m++) {
      tmp_map[(*it_m).first] = set_log_old[(*it_m).second];
    }
    map<map<int, int>, int>::iterator result = next_log.find(tmp_map);
    if (result != next_log.end()) {
      set_log[*equal_set_i] = (*result).second;
      next_log_set[(*result).second].insert(*equal_set_i);
    } else {
      set_iterator++;
      set_log[*equal_set_i] = set_iterator;
      next_log[tmp_map] = set_iterator;
      set<int> tmp_set;
      tmp_set.insert(*equal_set_i);
      next_log_set[set_iterator] = tmp_set;
    }
  }
  if (next_log_set.size() <= 1)
    return;
  map<int, set<int> >::iterator mi;
  for (mi = next_log_set.begin(); mi != next_log_set.end(); mi++) {

     _divide_by_next_inner(set_iterator, set_log, (*mi).second);
  }
  delete[] set_log_old;
}

void DFA::_release_states(vector<DFAState*>& states) {
  vector<DFAState*>::iterator it_v;
  for (it_v = states.begin(); it_v != states.end(); it_v++) {
    delete (*it_v);
  }
  states.clear();
}
