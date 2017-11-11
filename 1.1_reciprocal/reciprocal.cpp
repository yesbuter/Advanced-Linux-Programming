#include <cassert>
#include "reciprocal.hpp"

double reciprocal (int i) {
    //i不能为0
    assert(i != 0);
    return 1.0/i;
}
