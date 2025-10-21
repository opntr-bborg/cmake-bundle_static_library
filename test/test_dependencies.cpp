#include "lib_c.h"
#include <iostream>

int main() {
    int result = lib_c_func();
    if (result == 150) {
        std::cout << "Test PASSED: lib_c_func() returned " << result << std::endl;
        return 0;
    } else {
        std::cout << "Test FAILED: Expected 150, got " << result << std::endl;
        return 1;
    }
}
