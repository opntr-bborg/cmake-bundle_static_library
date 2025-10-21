#include "lib_a.h"
#include <iostream>

int main() {
    int result = lib_a_func();
    if (result == 42) {
        std::cout << "Test PASSED: lib_a_func() returned " << result << std::endl;
        return 0;
    } else {
        std::cout << "Test FAILED: Expected 42, got " << result << std::endl;
        return 1;
    }
}
