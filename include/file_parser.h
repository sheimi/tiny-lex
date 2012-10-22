#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct RegexEntry {
  RegexEntry(){}
  RegexEntry(string regex, int priority, string handler):
    regex(regex), priority(priority), handler(handler){}
  void to_c(ostream& os);

  string regex;
  int priority;
  string handler;

  friend inline istream& operator>>(istream& is, RegexEntry& t) {
    char buffer[256];
    is.getline(buffer, 256);
    string buffer_tmp(buffer);
    t.regex = buffer_tmp;
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
    os << "regex: \'" << t.regex << "'"<< endl;
    os << "priority: " << t.priority << endl;
    os << "hander: " << endl;
    os << t.handler << endl;
    os << "====" << endl;
    os << "*/" << endl;
    return os;
  }
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
