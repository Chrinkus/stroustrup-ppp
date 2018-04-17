//
// Stroustrup - Programming Principles & Practice
//
// Chapter 24 - Matrix multiplication
//

#include <iostream>
#include <stdexcept>
#include <vector>
#include "../text_lib/Matrix.h"
#include "../text_lib/MatrixIO.h"

using namespace Numeric_lib;

int main()
try {
    /*
    int ai1[] = { 1, 2, 3, 4, 5, 6 };
    int ai2[] = { 3, 6, 9, 12, 15, 18 };

    Matrix<int> mi1 {ai1};
    Matrix<int> mi2 {ai2};

    std::cout << mi1 << '\n';
    std::cout << mi2 << '\n';

    Matrix<int> mi3 = scale_and_add(mi1, 2, mi2);

    std::cout << mi3 << '\n';

    std::vector<int> vi1 { 1, 2, 3, 5, 7, 11 };
    Matrix<int> mi4 {vi1.data(), (int)vi1.size()};
    std::cout << mi4 << '\n';

    std::cout << dot_product(mi4, mi3) << '\n';
    */

    double ad1[][2] { { 2, -4 }, { -2, 5 } };
    double ad2[] { 7, 6 };

    Matrix<double,2> md1 {ad1};
    Matrix<double> md2 {ad2};

    std::cout << md1 << '\n';
    std::cout << md2 << '\n';

    Matrix<double> md3 (2);

    for (int i = 0; i < md1.dim1(); ++i)
        md3(i) = dot_product(md1[i], md2);

    std::cout << md3 << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

