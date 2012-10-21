#include "mylex.h"
#include "dfa.h"
#include <iostream>

int main(int argc, char ** args) {

  string filename = args[1];
  FileParser fp(filename);

  /*
  //NFA * nfa = new NFA("(((ab*)(a|b*))*|ab*)*(a|b)?");
  NFA * nfa = new NFA("(((ab*)(a|b*))*|(ab*))*");
  //NFA * nfa = new NFA("(a|b*)*");
  nfa->print_all();
  DFA * dfa = nfa->construct_DFA();
  dfa->minimize();
  cout << dfa->match("abbaa") << endl;
  cout << dfa->match("abbbbaa") << endl;
  cout << dfa->match("baa") << endl;
  cout << dfa->match("abbbaa") << endl;
  cout << dfa->match("abcdefgaa") << endl;
  cout << dfa->match("abbcdadefga") << endl;
  delete nfa;
  delete dfa;
  */

  /*
  NFA* nfa1 = new NFA("a*", 1);
  //nfa1->print_all();
  //cout << "--------------------------" << endl;
  NFA* nfa2 = new NFA("a|b", 2);
  //nfa2->print_all();
  //cout << "--------------------------" << endl;
  NFA* nfa3 = new NFA("a", 3);
  vector<NFA*> v;
  v.push_back(nfa1);
  v.push_back(nfa2);
  v.push_back(nfa3);
  NFA* nfa = NFA::connect_NFA(v);
  nfa->print_all();
  DFA* dfa = nfa->construct_DFA();
  dfa->minimize();
  NFA* nf2 = new NFA("(a*)|(a|b)|a");
  nf2->construct_DFA();
  delete nfa;
  delete nfa2;
  delete nfa1;
  */
  /*
  NFA* nfa1 = new NFA("a|bc", 1);
  NFA* nfa2 = new NFA("ab|c", 2);
  vector<NFA*> v;
  v.push_back(nfa1);
  v.push_back(nfa2);
  NFA* nfa = NFA::connect_NFA(v);
  DFA* dfa = nfa->construct_DFA();
  dfa->minimize();
  cout << dfa->match("ab") << endl;
  delete nfa1;
  delete nfa2;
  delete nfa;
  */
  return 0;
}
