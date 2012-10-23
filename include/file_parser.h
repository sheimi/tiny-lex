#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct RegexEntry {
  RegexEntry(){}
  RegexEntry(vector<int>& regex, int priority, string handler):
    regex(regex), priority(priority), handler(handler){}

  void to_c(ostream& os);

  vector<int> regex;
  string regex_str;
  int priority;
  string handler;

  void _set_regex(string& reg_str);
  vector<int> _parse_bracket(vector<int>& reg);

  friend inline istream& operator>>(istream& is, RegexEntry& t) {
    char buffer[256];
    is.getline(buffer, 256);
    string buffer_tmp(buffer);
    t.regex_str = buffer_tmp;
    t._set_regex(buffer_tmp);
    is.getline(buffer, 256);
    while (string(buffer).substr(0, 4) != "====") {
      t.handler.append(buffer);
      is.getline(buffer, 256);
    }
    return is;
  }

  friend inline ostream& operator<<(ostream& os, const RegexEntry& t) {
    os << "/*" << endl;
    os << "====" << endl;
    os << "regex: \'" << t.regex_str << "'"<< endl;
    os << "priority: " << t.priority << endl;
    os << "hander: " << endl;
    os << t.handler << endl;
    os << "====" << endl;
    os << "*/" << endl;
    return os;
  }

  // regex tag such as + | . ( ) * ?
  enum RegexTag {
    PLUS      = -1,  // '+'
    STAR      = -2,  // '*'
    OR        = -3,  // '|'
    CAT       = -4,  // '.'
    LEFT_PTH  = -5,  // '('
    RIGHT_PTH = -6,  // ')'
    QUEST     = -7,  // '?'
    LEFT_BCT  = -8,  // '['
    RIGHT_BCT = -9,  // ']'
    HYPHEN    = -10, // '-'
  };

};

class FileParser {
  public:
    FileParser(string& filename);
    virtual ~FileParser();
  private:
    vector<RegexEntry> _entries;
    DFA* _dfa;

    DFA* _construct_DFA(vector<RegexEntry>& entries);
};

#endif
