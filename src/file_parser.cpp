#include "mylex.h"

RegexEntry::RegexEntry(string& raw) {
  char buffer[BUFFER_SIZE];
  stringstream ss(raw);
  string reg_str;
  ss >> reg_str;
  _set_regex(reg_str);
  ss.getline(buffer, BUFFER_SIZE);
  while(buffer[strlen(buffer) -1] != '}') {
    handler.append(buffer);
    handler.push_back('\n');
    ss.getline(buffer, BUFFER_SIZE);
  }
  handler.append(buffer);
}

void RegexEntry::_set_regex(string& reg_str) {
  bool escape = false;
  vector<int> escape_free;
  // convert escape char and regex operator
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
  char tmp1[BUFFER_SIZE];
  //char tmp2[BUFFER_SIZE];
  sprintf(tmp1, "void end_handler_%d(Token* shm_token)", priority);
  //sprintf(tmp2, "  strcpy(shm_token->type, \"%s\");", type.c_str());
  c_code(os,
         tmp1,
         //tmp2,
         handler.c_str(),
         "");
}

FileParser::FileParser(string& filename) {
  ifstream ifs(filename.c_str());
  _parse(ifs);
  ifs.close();
  _dfa = _construct_DFA(_entries);
}

FileParser::~FileParser() {
  delete _dfa;
}

void FileParser::_parse(istream& is) {
  //declear section
  #define QUIT err_quit("WRONG LEX FORMAT");
  char buffer[BUFFER_SIZE_SMALL];
  fgetline(is, buffer, BUFFER_SIZE_SMALL);
  if (str_equal(buffer, "%{")) {
    _parse_declear(is);
  } else {
    QUIT;
  }
  fgetline(is, buffer, BUFFER_SIZE_SMALL);
  if (str_equal(buffer, "%%")) {
    _parse_entries(is);
  }
  _parse_code(is);
}
void FileParser::_parse_declear(istream& is) {
  char buffer[BUFFER_SIZE];
  fgetline(is, buffer, BUFFER_SIZE);
  while (str_nequal(buffer, "%}")) {
    _declear.append(buffer);
    _declear.push_back('\n');
    fgetline(is, buffer, BUFFER_SIZE);
  }
}
void FileParser::_parse_entries(istream& is) {
  char buffer[BUFFER_SIZE];
  fgetline(is, buffer, BUFFER_SIZE);
  int i = 0;
  while (str_nequal(buffer, "%%")) {
    string b_str(buffer);
    while(buffer[strlen(buffer) -1] != '}') { 
      b_str.push_back('\n');
      fgetline(is, buffer, BUFFER_SIZE);
      b_str.append(buffer);
    }
    RegexEntry re(b_str);
    re.priority = i;
    _entries.push_back(re);
    fgetline(is, buffer, BUFFER_SIZE);
    i++;
  }
}
void FileParser::_parse_code(istream& is) {
  char buffer[BUFFER_SIZE];
  while (!is.eof()) {
    fgetline(is, buffer, BUFFER_SIZE);
    _code.append(buffer);
    _code.push_back('\n');
  }
}

DFA* FileParser::_construct_DFA(vector<RegexEntry>& entries) {
  vector<NFA*> nfas;
  // create NFA from entries
  foreach (RegexEntry& entry, entries) {
    nfas.push_back(new NFA(entry.regex, entry.priority));
  }
  // connect nfsa to a big NFA
  NFA* nfa = NFA::connect_NFA(nfas);
  if (nfas.size() > 1) {
    foreach (NFA* n, nfas) {
      delete n;
    }
  }
  // construct DFA
  DFA* dfa = nfa->construct_DFA();
  delete nfa;
  // Minimize the DFA
  dfa->minimize();
  return dfa;
}

void FileParser::to_c() {
  _to_c(cout);
}
void FileParser::to_c(string& filename) {
  ofstream ofs(filename.c_str());
  _to_c(ofs);
  ofs.close();
}
void FileParser::_to_c(ostream& os) {
  _c_include(os);
  _c_token(os);
  foreach (RegexEntry& entry, _entries) {
    entry.to_c(os);
  }
  _dfa->to_c(os);
  _c_helper(os);
  _c_main(os);
}
void FileParser::_c_include(ostream& os) {
  c_code(os,
        "#include <stdio.h>",
        "#include <stdlib.h>",
        "#include <string.h>",
        "");
  os << _declear << endl;
}
void FileParser::_c_token(ostream& os) {
  c_code(os,
         "typedef struct _token {",
         "  char type[32];",
         "  char value[32];",
         "  struct _token* next;",
         "} Token;",
         "Token token_list;",
         "Token* tail = &token_list;",
         "#define NEW_TOKEN(t)\\",
         "  t = (Token*)(malloc(sizeof(Token)));\\",
         "  t->next = 0;\\",
         "  strcpy(t->type, \"\");\\",
         "  strcpy(t->value, \"\");",
         "#define INIT_ITER(iter) \\",
         "  iter = token_list.next;",
         "#define ITER_NEXT(iter) (iter = iter->next)",
         "#define ITER_HASNEXT(iter) (iter != NULL && iter->next != NULL)",
         "#define ITER_ISEND(iter) (iter == NULL)",
         "");

}

void FileParser::_c_main(ostream& os) {
  os << _code << endl;
}
void FileParser::_c_helper(ostream& os) {
  c_code(os,
         "void print_token(Token* token) {",
         "  printf(\"('%s', '%s')\\n\", token->type, token->value);",
         "}",
         "void free_tokens() {",
         "  Token* iter;",
         "  INIT_ITER(iter);",
         "  while(!ITER_ISEND(iter)) {",
         "    Token* tmp = iter;",
         "    ITER_NEXT(iter);",
         "    free(tmp);",
         "  }",
         "}",
         "void myylex(char* input, void (*func)()) {",
         "  FILE* infile;",
         "  infile = fopen(input, \"r\");",
         "  shm_parse(infile);",
         "  fclose(infile);",
         "  func();",
         "  free_tokens();",
         "}",
         "void iter_list(void (*trav_func)(Token*)) {",
         "  Token* iter;",
         "  INIT_ITER(iter);",
         "  while (!ITER_ISEND(iter)) {",
         "    trav_func(iter);",
         "    ITER_NEXT(iter);",
         "  }",
         "}",
         "");
}
