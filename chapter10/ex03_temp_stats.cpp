#include "../text_lib/std_lib_facilities.h"

struct Reading {
    int hour;
    double temp;
    char unit;
};

double celsius_to_fahrenheit(double temp_c)
{
    return 9.0/5 * temp_c + 32;
}

istream& operator>>(istream& is, Reading& r)
{
    const double min_plausible = -200;
    const double max_plausible = 200;
    const char celsius = 'c';
    const char fahrenheit = 'f';

    int h;
    double t;
    char u;
    is >> h >> t >> u;
    if (!is) {
        if (is.eof()) return is;
        error("bad reading");
    }

    if (t < min_plausible || max_plausible < t) error("bad temperature");
    if (u != celsius && u != fahrenheit) error("bad unit", u);

    if (u == celsius) {
        t = celsius_to_fahrenheit(t);
        u = fahrenheit;
    }
    r.hour = h;
    r.temp = t;
    r.unit = u;
    return is;
}

ostream& operator<<(ostream& os, Reading& r)
{
    return os << "hour: " << r.hour << " temp: " << r.temp << r.unit;
}

void fill_from_file(vector<Reading>& v, string& s)
    // fills a vector of Readings from a given file of raw data
{
    ifstream ist { s };
    if (!ist) error("Could not read from file ", s);
    ist.exceptions(ist.exceptions()|ios_base::badbit);

    for (Reading r; ist >> r; )
        v.push_back(r);
}

double get_median(vector<double>& sorted)
    // gets the median value of either an odd or even sized vector
{
    int i = 0;
    int l = sorted.size();
    double median = 0;

    if (l % 2) {
        i = (l + 1) / 2;
        median = sorted[i];
    } else {
        i = l / 2;
        median = (sorted[i] + sorted[i + 1]) / 2;
    }

    return median;
}

int main()
try {
    string fname = "raw_temps.txt";
    vector<Reading> raw_readings;
    fill_from_file(raw_readings, fname);

    // calculate mean and median from readings
    vector<double> temps;
    double temps_sum = 0;
    for (Reading r : raw_readings) {
        temps.push_back(r.temp);
        temps_sum += r.temp;
    }
    sort(temps);

    double mean = temps_sum / temps.size();
    double median = get_median(temps);

    cout << "mean: " << mean << '\n'
         << "median: " << median << '\n';
}
catch (exception& e) {
    cerr << "Error: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Something awful happened..\n";
    return 2;
}
