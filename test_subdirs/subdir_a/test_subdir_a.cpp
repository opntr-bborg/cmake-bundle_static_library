#include "lib2.h"
#include <iostream>

int main() {
    int result = subdir_a_func2();
    std::cout << "Subdir A result: " << result << std::endl;
    return (result == 150) ? 0 : 1;
}
