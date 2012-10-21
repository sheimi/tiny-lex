#include "mylex.h"

void RegexEntry::to_c(ostream& os) {
  cout << "void end_handler_" << priority << "(char* shm_str) {" << endl;
  cout << handler << endl;
  cout << "}" << endl;
}

FileParser::FileParser(string& filename) {
  ifstream ifs(filename.c_str());
  int N;
  ifs >> N;
  for (int i = 0; i < N; i++) {
    RegexEntry re;
    ifs >> re;
    re.priority = i;
    cout << re << endl;
    _entries.push_back(re);
  }
  ifs.close();
  _dfa = _construct_DFA(_entries);
  _dfa->c_include(cout);
  foreach (RegexEntry& entry, _entries) {
    entry.to_c(cout);
  }
  _dfa->to_c(cout);
  _dfa->c_main(cout);
}

FileParser::~FileParser() {
  delete _dfa;
}

DFA* FileParser::_construct_DFA(vector<RegexEntry>& entries) {
  vector<NFA*> nfas;
  foreach (RegexEntry& entry, entries) {
    nfas.push_back(new NFA(entry.regex, entry.priority));
  }
  NFA* nfa = NFA::connect_NFA(nfas);
  DFA* dfa = nfa->construct_DFA();
  delete nfa;
  foreach (NFA* n, nfas) {
    delete n;
  }
  dfa->minimize();
  return dfa;
}
