#include "../text_lib/std_lib_facilities.h"

int main()
{
    // Example of logic errors
    vector<double> temps;

    for (double temp; cin >> temp; )
        temps.push_back(temp);

    double sum = 0;
    double high_temp = 0;       // zero init may affect assignment
    double low_temp = 0;        // zero init may affect assignment

    for (int x : temps)
    {
        if (high_temp == 0 && low_temp == 0) {
            high_temp = x;
            low_temp = x;
        }

        if (x > high_temp) high_temp = x;   // find high
        if (x < low_temp) low_temp = x;     // find low
        sum += x;
    }

    cout << "High temperature: " << high_temp << '\n';
    cout << "Low temperature: " << low_temp << '\n';
    cout << "Average temperature: " << sum / temps.size() << '\n';
}
