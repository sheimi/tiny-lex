#ifndef DFA_H
#define DFA_H

#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;


struct DState;

struct DFAState {
  int identifier;
  map<int, int> nexts;
  bool is_end;
  bool is_first;
  int end_id;
};

class DFA {
  public:
    DFA(map<set<int>, DState*>& states);
    virtual ~DFA();

    int match(string input);
    void minimize();
    void print(ostream& os, vector<DFAState*>&);
    void c_include(ostream& os);
    void c_main(ostream& os);
    void to_c(ostream& os);
  private:
    vector<DFAState*> _states;
    int _first;

    void _divide_by_end(int& set_iterator, int* set_log);
    void _divide_by_outkey(int& set_iterator, int* set_log);
    void _divide_by_next(int& set_iterator, int* set_log); 
    void _divide_by_next_inner(int&, int*, set<int>&);
    int _construct_min_dfa(DFAState* o_state, vector<DFAState*>& min_states,
                          map<int, int>& id_map, int* set_log);
    void _release_states(vector<DFAState*>& states);

    void _c_header(ostream& os);
    void _c_footer(ostream& os);
    void _c_state_change(ostream& os, DFAState* state);
    void _c_state_reset(ostream& os);
    void _c_state_end(ostream& os, int end_point);
};

#endif
