#include "mylex.h"
#include <stdarg.h>

void c_code(ostream& os, ...) {
  va_list ap;
  const char* s;
  va_start(ap, os); 
  while (str_nequal("", s = va_arg(ap, char*))) {
    os << s << endl;
  }
  va_end(ap);
}
