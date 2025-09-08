#include <math.h>
#include "structures_consts.h"

bool double_is_equal(double param1, double param2){
    return fabs(param1 - param2) < EPSILON;
}