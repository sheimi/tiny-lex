#ifndef ENV_H
#define ENV_H

#define max(a, b) (a > b ? a : b)
#define str_equal(a, b) (strcmp(a, b) == 0)
#define strcase_equal(a, b) (strcasecmp(a, b) == 0)
#define str_nequal(a, b) (strcmp(a, b) != 0)
#define strcase_nequal(a, b) (strcasecmp(a, b) != 0)

#define foreach BOOST_FOREACH

#define PRINT_VECTOR_INT(out, v) \
  foreach(int i, v) {\
    if (i > 0) {\
      out << (char)i << " ";\
    } else {\
      out << i << " ";\
    }\
  }

const int BUFFER_SIZE = 128;
const int BUFFER_SIZE_SMALL = 64;
const int BUFFER_SIZE_SMALLER = 32;


#endif
