#include "mylex.h"
#include <iostream>

int main(int argc, char ** args) {
  NFA * nfa = NFA::post2nfa("abb.+.a.a.");
  nfa->print_all();
  cout << "================= SPLIT LINE ==============" <<endl;
  nfa->construct_DFA();
  delete nfa;
  return 0;
}
