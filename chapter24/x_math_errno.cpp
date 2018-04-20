//
// Stroustrup - Programming Principles & Practice
//
// Chapter 24 Scratch - errno
//
// This was an attempt to see how errno worked but for whatever reason math
// errors are not setting errno, it remains 0.
//

#include <iostream>
#include <stdexcept>
#include <cmath>
#include <cerrno>

int main()
try {
    errno = 0;
    double bad_num = sqrt(-1.0);
    if (errno == EDOM) {
        std::cout << "sqrt(-1) failed: " << std::strerror(errno) << '\n';
    }
    std::cout << errno << ' ' << bad_num << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

