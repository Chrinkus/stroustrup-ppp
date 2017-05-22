#include "../text_lib/std_lib_facilities.h"

double ctof(double c)
{
    double f = 9.0/5 * c + 32;
    return f;
}

double ftoc(double f)
{
    double c = (f - 32) / (9.0 / 5);
    return c;
}

int main()
{
    cout << "Enter a temperature in Celsius or Fahrenheit: (ex: 20 C)\n";
    double temp;
    char unit;
    cin >> temp >> unit;

    double ret_temp = 0;
    char ret_unit = ' ';

    switch (unit) {
        case 'F':
            ret_temp = ftoc(temp);
            ret_unit = 'C';
            break;
        case 'C':
            ret_temp = ctof(temp);
            ret_unit = 'F';
            break;
        default:
            break;
    }

    cout << temp << unit << " converts to " << ret_temp << ret_unit << '\n';
}
