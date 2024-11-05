#include "lib.h"
#include <private_lib.h>

void print_hello(){
    std::cout << "Hello CMake!" << std::endl;
    print_private();
}