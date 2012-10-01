#include "mylex.h"
#include "dfa.h"
#include <iostream>

int main(int argc, char ** args) {
  NFA * nfa = new NFA("a(bb)+aa");
  //nfa->print_all();
  DFA * dfa = nfa->construct_DFA();
  cout << dfa->match("abbaa") << endl;
  cout << dfa->match("abbbbaa") << endl;
  cout << dfa->match("aaa") << endl;
  cout << dfa->match("abbbaa") << endl;
  delete nfa;
  delete dfa;
  return 0;
}
