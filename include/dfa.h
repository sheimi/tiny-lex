#ifndef DFA_H
#define DFA_H

#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;


struct DState;

/*
 * The State of DFA
 */
struct DFAState {
  int identifier;       // the id of dfa
  map<int, int> nexts;  // next states
  bool is_end;          // if the state is the final state
  bool is_first;        // if the state is the original state
  int end_id;           // the end_id of state (regex priority),
                        // if is end == 0, end_id = -1
};

/*
 * It contains all the information of dfa
 */
class DFA {
  public:
    DFA(map<set<int>, DState*>& states);
    virtual ~DFA();

    /*
     * To use dfa to match the input string
     *
     * :return: the end_id or -1
     */
    int match(string input);
    /*
     * minimize the dfa
     */
    void minimize();
    /* convert DFA to c code */
    void to_c(ostream& os);
    void print(ostream& os, vector<DFAState*>&);
  private:
    vector<DFAState*> _states;      // All the States in DFA
    int _first;                     // the id of first state in DFA

    
    /*
     * Following 5 are helper functions to construct min dfa
     */
    /*
     * Divide states to different equivalent sets by checking if a
     * state is the final state
     */
    void _divide_by_end(int& set_iterator, int* set_log);
    /*
     * Divide states to different equivalent sets by checking if the
     * states have the same output key
     */
    void _divide_by_outkey(int& set_iterator, int* set_log);
    /* 
     * Divide states to different equivalent sets by checking if the
     * states have the same output value (same next states)
     */
    void _divide_by_next(int& set_iterator, int* set_log); 
    void _divide_by_next_inner(int&, int*, set<int>&);
    /* Construct min dfa */
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
