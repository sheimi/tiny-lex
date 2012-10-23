#include "mylex.h"

void RegexEntry::_set_regex(string& reg_str) {
  bool escape = false;
  vector<int> escape_free;
  foreach(char c, reg_str) {
    if (escape) {
      switch(c) {
        default:
          escape_free.push_back(c);
          break;
        case 'n':
          escape_free.push_back('\n');
          break;
        case 'r':
          escape_free.push_back('\r');
          break;
        case 's':
          escape_free.push_back(' ');
          break;
      }
      escape = false;
    } else {
      switch(c) {
        default:
          escape_free.push_back(c);
          break;
        case '\\':
          escape = true;
          break;
        case '+':
          escape_free.push_back(PLUS);
          break;
        case '*':
          escape_free.push_back(STAR);
          break;
        case '|':
          escape_free.push_back(OR);
          break;
        case '.':
          escape_free.push_back(CAT);
          break;
        case '?':
          escape_free.push_back(QUEST);
          break;
        case '(':
          escape_free.push_back(LEFT_PTH);
          break;
        case ')':
          escape_free.push_back(RIGHT_PTH);
          break;
        case '[':
          escape_free.push_back(LEFT_BCT);
          break;
        case ']':
          escape_free.push_back(RIGHT_BCT);
          break;
        case '-':
          escape_free.push_back(HYPHEN);
          break;
      }
    }
  }
  regex = _parse_bracket(escape_free);
#ifdef DEBUG
  PRINT_VECTOR_INT(cerr, regex);
  cerr << endl;
#endif
}

vector<int> RegexEntry::_parse_bracket(vector<int>& reg) {
  bool bracket = false;
  bool hyphen = false;
  int last_char;
  vector<int> result;
  foreach(int c, reg) {
    if (bracket) {
      switch (c) {
        default:
          if (hyphen) {
            hyphen = false;
            for (int i = last_char + 1; i != c;
                 last_char < c ? i++ : i--) {
              result.push_back(i);
              result.push_back(OR);
            }
          } else {
            last_char = c;
          }
          result.push_back(c);
          result.push_back(OR);
          break;
        case HYPHEN:
          hyphen = true;
          break;
        case RIGHT_BCT:
          bracket = false;
          result.pop_back();
          result.push_back(RIGHT_PTH);
          break;
      }
    } else {
      switch (c) {
        default:
          result.push_back(c);
          break;
        case LEFT_BCT:
          result.push_back(LEFT_PTH);
          bracket = true;
          break;
      }
    }
  }
  return result;
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
  if (nfas.size() > 1) {
    foreach (NFA* n, nfas) {
      delete n;
    }
  }
  DFA* dfa = nfa->construct_DFA();
  delete nfa;
  dfa->minimize();
  return dfa;
}
