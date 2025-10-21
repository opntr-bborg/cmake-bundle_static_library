#include "mylib_b.h"
#include "mylib_a.h"

int mylib_b_func() {
    return mylib_a_func() + 10;
}
