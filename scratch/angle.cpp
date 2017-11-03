#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const double PI = 3.14159;
    // atan2(y, x)
    cout << atan2(-8, 1) * 180 / PI << '\n';
    cout << atan2(-5, -5) * 180 / PI << '\n';
    cout << atan2(-2, 4) * 180 / PI << '\n';
    cout << atan2(7, 2) * 180 / PI << '\n';
    cout << atan2(0, 10) * 180 / PI << '\n';
}
