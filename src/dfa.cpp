#include "mylex.h"
#include <iostream>
#include <queue>

DFA::DFA(map<set<int>, DState*>& states) {
  #define GET_STATE_BY_ID(state, old_state)\
    if (id_map.find(old_state->identifier) == id_map.end()) {\
      state = new DFAState();\
      state->identifier = _states.size();\
      state->is_end = old_state->is_end;\
      state->is_first = old_state->is_first;\
      state->end_id = old_state->end_id;\
      if (state->is_first)\
        _first = state->identifier;\
      _states.push_back(state);\
      id_map[old_state->identifier] = state->identifier;\
    } else {\
      state = _states[id_map[old_state->identifier]];\
    }

  typedef map<set<int>, DState*> map_t;
  map<set<int>, int> id_map;

  foreach(map_t::value_type& item, states) {
    DState* dstate = item.second;
    DFAState* dfa_state;
    GET_STATE_BY_ID(dfa_state, dstate);

    typedef map<int, set<int> > map_set_t;
    foreach(map_set_t::value_type& item_ms, dstate->next_states) {
      const int convert_char = item_ms.first;
      const set<int>& next_id = item_ms.second;
      DFAState* next_dfa_state;
      GET_STATE_BY_ID(next_dfa_state, states[next_id]);
      dfa_state->nexts[convert_char] = next_dfa_state->identifier;
    }
  }

#ifdef DEBUG
  print(_states);
#endif

}

DFA::~DFA() {
  _release_states(_states);
}

int DFA::match(string input) {
  int id = _first;
  foreach(char c, input) {
    DFAState* state = _states[id];
    if (state->nexts.find(c) == state->nexts.end())
      return false;
    id = state->nexts[c];
  }
  return _states[id]->end_id;
}

void DFA::print(vector<DFAState*>& states) {
  cout << endl << endl << endl;
  cout << "================= SPLIT LINE ==============" <<endl;

  typedef map<int, int> map_t;
  foreach (DFAState* state, states) {
    cout << state->identifier << " end?:" << state->is_end << "\t";
    cout << state->identifier << " end_id:" << state->end_id << "\t";
    cout << " first?:" << state->is_first<< "\t";
    foreach (map_t::value_type item_m, state->nexts) {
      cout << (char)item_m.first << " => " << item_m.second << "\t";
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
  foreach(DFAState* state, _states) {
    _construct_min_dfa(state, min_states, id_map, set_log);
  }

  _release_states(_states);
  _states.resize(min_states.size());
  copy(min_states.begin(), min_states.end(), _states.begin());
 
#ifdef DEBUG
  print(_states);
#endif

  delete[] set_log;
}

int DFA::_construct_min_dfa(DFAState* o_state, vector<DFAState*>& min_states,
                           map<int, int>& id_map, int* set_log) {
  int o_id = o_state->identifier;
  map<int, int>::iterator result = id_map.find(set_log[o_id]);
  // TODO to be verified
  if (result != id_map.end()) {
    DFAState* tmp = min_states[(*result).second];
    if (o_state->end_id < tmp->end_id)
      tmp->end_id = o_state->end_id;
    return (*result).second;
  }
  int id = min_states.size();
  DFAState* state = new DFAState();
  state->identifier = id;
  id_map[set_log[o_id]] = id;
  state->is_end = o_state->is_end;
  state->is_first = o_state->is_first;
  state->end_id = o_state->end_id;
  if (state->is_first)
    _first = state->identifier;
  min_states.push_back(state);

  typedef map<int, int> map_t;
  foreach(map_t::value_type item_m, o_state->nexts) {
    int next_key = item_m.first;
    DFAState* next = _states[item_m.second];
    int next_value = _construct_min_dfa(next, min_states, id_map, set_log);
    state->nexts[next_key] = next_value;
  }
  return id;
}

/* make the differ kind of state in different set: end or not end */
void DFA::_divide_by_end(int& set_iterator, int* set_log) {
  set_iterator++;
  foreach(DFAState* state, _states) {
    int id = state->identifier;
    if (state->is_end) {
      set_log[id] = set_iterator;
    }
  }
}

/* make state with different next states key in different set */
void DFA::_divide_by_outkey(int& set_iterator, int* set_log) {
  map<set<int>, int> output_log;
  foreach(DFAState* state, _states) {
    int id = state->identifier;
    map<int, int>& output = state->nexts;

    // get next states key set
    set<int> output_set;
    typedef map<int, int> map_t;
    foreach(map_t::value_type& item_m, output) {
      output_set.insert(item_m.first);
    }
    // put previous set_identifier into the set
    //if (output_set.empty() && state->is_end)
    if (state->is_end)
      output_set.insert(state->end_id);
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
  typedef map<int, set<int> > map_t;
  foreach(map_t::value_type& item, equal_sets) {
    _divide_by_next_inner(set_iterator, set_log, item.second);
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
  // divider the set                                 
  foreach(int item, equal_set) {
    DFAState* state = _states[item];
    typedef map<int, int> map_t;
    map<int, int> tmp_map;
    foreach(map_t::value_type& item_m, state->nexts) {
      tmp_map[item_m.first] = set_log_old[item_m.second];
    }
    map<map<int, int>, int>::iterator result = next_log.find(tmp_map);
    if (result != next_log.end()) {
      set_log[item] = (*result).second;
      next_log_set[(*result).second].insert(item);
    } else {
      set_iterator++;
      set_log[item] = set_iterator;
      next_log[tmp_map] = set_iterator;
      set<int> tmp_set;
      tmp_set.insert(item);
      next_log_set[set_iterator] = tmp_set;
    }
  }
  if (next_log_set.size() <= 1)
    return;
  typedef map<int, set<int> > map_set_t;
  foreach(map_set_t::value_type item_m, next_log_set) {
    _divide_by_next_inner(set_iterator, set_log, item_m.second);
  }
  delete[] set_log_old;
}

void DFA::_release_states(vector<DFAState*>& states) {
  foreach(DFAState* state, states) {
    delete state;
  }
  states.clear();
}
