#include "lib_c.h"
#include "lib_b.h"

int lib_c_func() {
    return lib_b_func() + 50;
}
