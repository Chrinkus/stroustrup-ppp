#include "../text_lib/std_lib_facilities.h"

struct Vector_data {
    double small = 0;
    double large = 0;
    double mean = 0;
    double median = 0;
};

double get_median(vector<double> v)
{
    sort(v);
    double median = 0;
    int size = v.size();

    if (size % 2 == 0) {
        int half = size / 2;
        median = (v[half] + v[half + 1]) / 2;
    } else {
        median = v[(size - 1) / 2];
    }

    return median;
}

Vector_data get_data(vector<double> v)
{
    Vector_data data;
    double sum = 0;

    sort(v);

    for (double val : v)
        sum += val;

    data.small = v[0];
    data.large = v[v.size() - 1];
    data.mean = sum / v.size();
    data.median = get_median(v);

    return data;
}

int main()
{
    vector<double> data_set = { 2.6, -1, 15.3, 8.8, 17.1, -6.9 };

    Vector_data data = get_data(data_set);

    cout << "Smallest is: " << data.small << '\n'
         << "Largest is: " << data.large << '\n'
         << "Mean is: " << data.mean << '\n'
         << "Median is: " << data.median << '\n';
}
