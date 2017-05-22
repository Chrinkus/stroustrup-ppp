#include "../text_lib/std_lib_facilities.h"

double ctok(double c)       // converts Celsius to Kelvin
{
    constexpr double k_conversion = 273.15;

    double k = c + k_conversion;
    return k;
}

int main()
{
    constexpr double abs_0_c = -273.15;

    double c = 0;           // declare input variable
    cin >> c;               // retrieve temperature to input variable

    if (c < abs_0_c) error("Input temp is lower than absolute 0.\n");

    double k = ctok(c);   // convert temperature
    cout << k << '\n';      // print out temperature
}
