#include "../text_lib/std_lib_facilities.h"

int main()
{
    vector<double> temps;
    double median = 0;

    for (double temp; cin >> temp; )
        temps.push_back(temp);

    int above_mid = temps.size() / 2;
    double sum = 0;
    for (double x : temps) sum += x;
    cout << "Average temperature: " << sum / temps.size() << '\n';

    sort(temps);

    if (temps.size() % 2 == 0) {
        median = (temps[above_mid] + temps[above_mid - 1]) / 2;
    } else {
        median = temps[above_mid];
    }

    cout << "Median temperature: " << median << '\n';
}
