#include "lib_g.h"
#include <iostream>

int main() {
    int result = lib_g_func();
    if (result == 77) {
        std::cout << "Test PASSED: lib_g_func() returned " << result << std::endl;
        return 0;
    } else {
        std::cout << "Test FAILED: Expected 77, got " << result << std::endl;
        return 1;
    }
}
