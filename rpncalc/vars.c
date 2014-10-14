#include "vars.h"

double vars[NVARS] = {0.0/0.0};

double putvar(char var, double val) {
    vars[var] = val;
    return val;
}
double getvar(char var) {
    return vars[var];
}
