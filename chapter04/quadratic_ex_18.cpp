#include "../text_lib/std_lib_facilities.h"

int main()
{
    // Program
    double a;
    double b;
    double c;

    cout << "Lets do a quadratic equation!\n"
         << "Please enter an 'a', 'b', and 'c' value:\n";
    cin >> a >> b >> c;

    double negB = 0 - b;

    double x1 = (negB + sqrt(b * b - 4 * a * c)) / (2 * a);
    double x2 = (negB - sqrt(b * b - 4 * a * c)) / (2 * a);

    cout << "The solution values are: x1 = " << x1
         << ", x2 = " << x2 << '\n';
}
