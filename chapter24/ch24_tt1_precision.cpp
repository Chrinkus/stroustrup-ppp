//
// Stroustrup - Programming Principles & Practice
//
// Chapter 24 Try This - Precision
//

#include <iostream>
#include <stdexcept>
#include <iomanip>

int main()
try {
    const float divisor = 333;
    float x = 1.0/divisor;
    float sum = 0;
    for (int i=0; i<divisor; ++i) sum+=x;
    std::cout << std::setprecision(15) << sum << '\n';
    // divisor == 333: 0.999999463558197 
    // divisor ==  10: 1.00000011920929 
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

