#include "../text_lib/std_lib_facilities.h"

double ctok(double c)       // converts Celsius to Kelvin
{
    constexpr double k_conversion = 273.15;

    double k = c + k_conversion;
    return k;
}

int main()
{
    double c = 0;           // declare input variable
    cin >> c;               // retrieve temperature to input variable
    double k = ctok(c);   // convert temperature
    cout << k << '\n';      // print out temperature
}

/* Errors:
 * ctok: references a magic constant
 * ctok: k declared as int instead of double
 * ctok: returned int instead of k
 * ctok: omits ;
 * main: inits c then inputs into d
 * main: passes a string arg to a function expecting a double
 * main: output is minimally vague
 * main: cout had capital 'C'
 */

/* Original code
double ctok(double c)       // converts Celsius to Kelvin
{
    int k = c + 273.15;
    return int
}

int main()
{
    double c = 0;           // declare input variable
    cin >> d;               // retrieve temperature to input variable
    double k = ctok("c");   // convert temperature
    Cout << k << '\n';      // print out temperature
}
*/
