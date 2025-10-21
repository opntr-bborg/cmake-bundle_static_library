#include "lib_d.h"
#include <iostream>

int main() {
    int result = lib_d_func();
    if (result == 13) {
        std::cout << "Test PASSED: lib_d_func() returned " << result << std::endl;
        return 0;
    } else {
        std::cout << "Test FAILED: Expected 13, got " << result << std::endl;
        return 1;
    }
}
