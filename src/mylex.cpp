#include "mylex.h"
#include "dfa.h"
#include <iostream>

int main(int argc, char ** args) {
  NFA * nfa = NFA::post2nfa("abb.+.a.a.");
  //nfa->print_all();
  DFA * dfa = nfa->construct_DFA();
  delete nfa;
  delete dfa;
  return 0;
}
