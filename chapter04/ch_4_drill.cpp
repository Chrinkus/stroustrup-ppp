#include "../text_lib/std_lib_facilities.h"

bool check_unit(string unit) {

    bool good_unit = false;
    vector<string> acceptable_units = { "cm", "m", "in", "ft" };

    for (string u : acceptable_units)
        if (u == unit)
            good_unit = true;

    return good_unit;
}

double get_meters(double amount, string unit) {

    constexpr double cm_to_m = 0.01;
    constexpr double in_to_m = 0.0254;
    constexpr double ft_to_m = 0.3048;

    double in_meters = 0;

    if (unit == "cm")
        in_meters = amount * cm_to_m;
    else if (unit == "in")
        in_meters = amount * in_to_m;
    else if (unit == "ft")
        in_meters = amount * ft_to_m;
    else if (unit == "m")
        in_meters = amount;

    return in_meters;
}

int main()
{
    double amount;
    double meters;
    double sum_in_meters = 0;
    double values_entered = 0;
    double smallest = 0;
    double largest = 0;

    vector<double> measurements;

    string unit;

    while (cin >> amount >> unit) {

        if (!check_unit(unit))
            cout << "I can't calculate that measurement.\n";
        else {
            meters = get_meters(amount, unit);

            if (smallest == 0 && largest == 0) {
                smallest = meters;
                largest = meters;
            }

            if (meters < smallest) {
                smallest = meters;
                cout << "smallest so far" << '\n';
            } else if (meters > largest) {
                largest = meters;
                cout << "largest so far" << '\n';
            }

            measurements.push_back(meters);
            sum_in_meters += meters;
            values_entered += 1;
        }
    }

    cout << "Results:\n";

    sort(measurements);
    for (double m : measurements)
        cout << m << "m\n";

    cout << "The smallest measurement was: " << smallest << "m\n"
         << "The largest measurement was: " << largest << "m\n"
         << "There were " << values_entered << " values entered\n"
         << "The sum of the values entered is " << sum_in_meters << "m\n";
}
