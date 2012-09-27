#ifndef ERROR_H
#define ERROR_H

#include "env.h"

void err_msg(const char * msg);
void err_quit(const char * msg);
void assert(bool b);

#endif 
