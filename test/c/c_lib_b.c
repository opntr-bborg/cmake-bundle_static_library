#include "c_lib_b.h"
#include "c_lib_a.h"

int c_lib_b_func(void) {
    return c_lib_a_func() + 23;
}
