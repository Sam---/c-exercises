#include <math.h>
#include "vars.h"

double vars[NVARS] = {NAN};

double putvar(char var, double val) {
    vars[var] = val;
    return val;
}
double getvar(char var) {
    return vars[var];
}
