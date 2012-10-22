#include "mylex.h"

void RegexEntry::_set_regex(string& reg_str) {
  bool escape = false;
  foreach(char c, reg_str) {
    if (escape) {
      switch(c) {
        default:
          regex.push_back(c);
          break;
        case 'n':
          regex.push_back('\n');
          break;
      }
      escape = false;
    } else {
      switch(c) {
        default:
          regex.push_back(c);
          break;
        case '\\':
          escape = true;
          break;
        case '+':
          regex.push_back(PLUS);
          break;
        case '*':
          regex.push_back(STAR);
          break;
        case '|':
          regex.push_back(OR);
          break;
        case '.':
          regex.push_back(CAT);
          break;
        case '?':
          regex.push_back(QUEST);
          break;
        case '(':
          regex.push_back(LEFT_PTH);
          break;
        case ')':
          regex.push_back(RIGHT_PTH);
          break;
      }
    }
  }
}

void RegexEntry::to_c(ostream& os) {
  cout << "void end_handler_" << priority << "(char* shm_str) {" << endl;
  cout << handler << endl;
  cout << "}" << endl;
}

FileParser::FileParser(string& filename) {
  ifstream ifs(filename.c_str());
  char buffer[32];
  ifs.getline(buffer, 32);
  stringstream ss(buffer);
  int N;
  ss >> N;
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
