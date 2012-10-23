#include "mylex.h"
#include "dfa.h"
#include <iostream>

int main(int argc, char ** args) {
  if (argc < 2) {
    err_msg("USAGE: mylex input(.lex) [output(.c)]");
  }
  string input = args[1];
  FileParser fp(input);
  if (argc == 2) {
    fp.to_c();
  } else {
    string output = args[2];
    fp.to_c(output);
  }
  return 0;
}
