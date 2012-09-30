#include "mylex.h"

int main(int argc, char ** args) {
  NFA * nfa = NFA::post2nfa("abb.+.a.");
  nfa->print_all();
  delete nfa;
  return 0;
}
