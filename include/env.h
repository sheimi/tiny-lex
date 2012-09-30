#ifndef ENV_H
#define ENV_H

#define max(a, b) (a > b ? a : b)
#define str_equal(a, b) (strcmp(a, b) == 0)
#define strcase_equal(a, b) (strcasecmp(a, b) == 0)
#define str_nequal(a, b) (strcmp(a, b) != 0)
#define strcase_nequal(a, b) (strcasecmp(a, b) != 0)

#endif
