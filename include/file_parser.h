#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;

/*
* This struct contains the basic information about entry in .mylex file
*/
struct RegexEntry {
  // store the int value of the regex
  vector<int> regex;
  // the priority of regex, that is, the position in .mylex file
  int priority;
  // the handler defined in .mylex file
  string handler;

  RegexEntry(){}
  RegexEntry(vector<int>& regex, int priority, string handler):
    regex(regex), priority(priority), handler(handler){}

  /*
  * Convert handler in RegexEntry to C code
  * If the priority is N, the C code will be:
  *   void end_handler_N(char* shm_str) {
  *     handler;
  *   }
  * If scanner find input match the regex string, it will call
  * this handler automatically
  */
  void to_c(ostream& os);

  /*
  * Set the regex of RegexEntry.
  * It will convert regex string to an int array
  */
  void _set_regex(string& reg_str);
  
  /*
  * Parse The string in square bracket
  */
  vector<int> _parse_bracket(vector<int>& reg);

  /*
  * Read RegexEntry from input stream
  */
  friend inline istream& operator>>(istream& is, RegexEntry& t) {
    char buffer[256];
    is.getline(buffer, 256);
    string buffer_tmp(buffer);
    t._set_regex(buffer_tmp);
    is.getline(buffer, 256);
    while (string(buffer).substr(0, 4) != "====") {
      t.handler.append(buffer);
      is.getline(buffer, 256);
    }
    return is;
  }

  /*
  * Map of Regex Operator
  */
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

/*
* Parser of .mylex file and generate c Code
*/
class FileParser {
  public:
    FileParser(string& filename);
    virtual ~FileParser();
    /*
    * convert dfa to c code (to stdout)
    */ 
    void to_c();
    /*
    * couvert dfa to c code (to file "filename")
    */
    void to_c(string& filename);
  private:
    // entries
    vector<RegexEntry> _entries;
    // the min dfa
    DFA* _dfa;
    // innner to c code
    void _to_c(ostream& os);
    DFA* _construct_DFA(vector<RegexEntry>& entries);
};

#endif
