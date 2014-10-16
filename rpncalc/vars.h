#ifndef VARS_H
#define VARS_H

#include <limits.h>

#define NVARS CHAR_BIT

extern double vars[NVARS];

double putvar(char var, double val);
double getvar(char var);

#endif /* VARS_H */
