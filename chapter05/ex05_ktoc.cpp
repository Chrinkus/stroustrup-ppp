#include "../text_lib/std_lib_facilities.h"

double ctok(double c)       // converts Celsius to Kelvin
{
    constexpr double k_conversion = 273.15;
    constexpr double abs_0_c = -273.15;

    if (c < abs_0_c) error("Input temp is lower than absolute zero.\n");

    double k = c + k_conversion;
    return k;
}

double ktoc(double k)
{
    constexpr double k_to_c = 273.15;

    if (k <= 0) error("Input temp is lower than absolute zero.\n");

    double c = k - k_to_c;
    return c;
}

int main()
{
    /*
    double c = 0;           // declare input variable
    cin >> c;               // retrieve temperature to input variable

    double k = ctok(c);   // convert temperature
    cout << k << '\n';      // print out temperature
    */
    cout << "Enter a temperature in Celsius or Kelvin: (ex: 20 C)\n";
    double temp;
    char unit;
    cin >> temp >> unit;

    double ret_temp = 0;
    char ret_unit = ' ';

    switch (unit) {
        case 'K':
            ret_temp = ktoc(temp);
            ret_unit = 'C';
            break;
        case 'C':
            ret_temp = ctok(temp);
            ret_unit = 'K';
            break;
        default:
            break;
    }

    cout << temp << unit << " converts to " << ret_temp << ret_unit << '\n';
}
