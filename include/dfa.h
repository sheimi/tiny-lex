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
};

class DFA {
  public:
    DFA(map<set<int>, DState*>& states);
    virtual ~DFA();

    bool match(string input);
  private:
    vector<DFAState*> _states;
};

#endif
