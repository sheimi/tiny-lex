#ifndef DFA_H
#define DFA_H

#include <map>
#include <set>
#include <vector>
using namespace std;


struct DState;

struct DFAState {
  int identifier;
  map<int, int> nexts;
};

class DFA {
  public:
    DFA(map<set<int>, DState*>& states);
    virtual ~DFA();
  private:
    vector<DFAState*> _states;
};

#endif
