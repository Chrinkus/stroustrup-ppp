// sin example from cplusplus.com
#include <iostream>
#include <cmath>

int main()
{
    constexpr double PI = 3.14159265;
    double param, result;
    param = 30.0;
    result = sin(param*PI/180);
    std::cout << "The sine of " << param << " degrees is " << result << '\n';
}
