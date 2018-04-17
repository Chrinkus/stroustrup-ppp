//
// Stroustrup - Programming Principles & Practice
//
// Chapter 23 Scratch - std::copy_if() use
//

#include <iostream>
#include <stdexcept>
#include <array>
#include <vector>

int main()
try {
    std::array<int,10> ai { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    std::vector<double> vd (ai.size());

    auto it = std::copy_if(ai.begin(), ai.end(), vd.begin(),
            [](int x) { return x % 2; });
    
    vd.resize(std::distance(vd.begin(), it));

    for (const auto& d : vd)
        std::cout << d << ' ';
    std::cout << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

