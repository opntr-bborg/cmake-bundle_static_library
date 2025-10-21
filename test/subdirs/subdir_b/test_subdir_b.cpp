#include "lib2.h"
#include <iostream>

int main() {
    int result = subdir_b_func2();
    std::cout << "Subdir B result: " << result << std::endl;
    return (result == 275) ? 0 : 1;
}
