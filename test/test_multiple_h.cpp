#include "lib_h.h"
#include <iostream>

int main() {
    int result = lib_h_func();
    if (result == 88) {
        std::cout << "Test PASSED: lib_h_func() returned " << result << std::endl;
        return 0;
    } else {
        std::cout << "Test FAILED: Expected 88, got " << result << std::endl;
        return 1;
    }
}
