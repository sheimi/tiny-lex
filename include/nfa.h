#ifndef NFA_H
#define NFA_H

/*
 *  include/nfa.c
 *  
 *  This file contains the interface of my nfa, it contains:
 *
 *    NState:         the interface of nfa state
 *    NStateFrag      the interface of nfa state fragment (nfa frag)
 *    NFA:            the interface of nfa
 *
 */  

#include <vector>

using namespace std;

struct NState {
  NState();
  NState(vector<NState*>& v, int c=0, NState* out1=NULL, NState* out2=NULL);

  int c;         // char to enter this state
  int flag;      // travel flag
  NState*  out1; // out1
  NState* out2;  // out2
  int index;     // index of the state vector
  int out_num;
};

struct NStateFrag {
  NStateFrag();
  NStateFrag(NState* start, NState** out1, NState** out2=NULL);

  NState* start;   // point to the Start
  NState** out1;   // point to the State's out addrees
  NState** out2;   // point to the State's out address

  void connect_state(NState* state);
};

class NFA {
  public:
    typedef void (* travel_func)(NState * state);

    // create nfa from postfix expression
    static NFA* post2nfa(char * postfix);
    
    virtual ~NFA();
    // traval states in the NFA
    void nfa_travel(travel_func func);
    void print_all();
  private:
    NState _start;
    vector<NState*> _states;

    void _nfa_travel(NState* state, travel_func func); 

};

#endif
