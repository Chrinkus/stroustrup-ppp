#include "../text_lib/std_lib_facilities.h"

class Imaginary_number { };
double under_root(double a, double b, double c)
{
    double val = b * b - 4 * a * c;
    if (val < 0) throw Imaginary_number{};

    return val;
}

int main()
try {
    // Program
    double a;
    double b;
    double c;

    cout << "Lets do a quadratic equation!\n"
         << "Please enter an 'a', 'b', and 'c' value:\n";
    cin >> a >> b >> c;

    double negB = 0 - b;

    double x1 = (negB + sqrt(under_root(a, b, c))) / (2 * a);
    double x2 = (negB - sqrt(under_root(a, b, c))) / (2 * a);

    cout << "The solution values are: x1 = " << x1
         << ", x2 = " << x2 << '\n';
}
catch(Imaginary_number) {
    cout << "Oops! Can't get the square root of a negative number.\n";
}
catch(...) {
    cout << "Exception: something went wrong.\n";
}
