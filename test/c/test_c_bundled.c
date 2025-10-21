#include "c_lib_b.h"
#include <stdio.h>

int main(void) {
    int result = c_lib_b_func();
    if (result == 123) {
        printf("Test PASSED: c_lib_b_func() returned %d\n", result);
        return 0;
    } else {
        printf("Test FAILED: Expected 123, got %d\n", result);
        return 1;
    }
}
