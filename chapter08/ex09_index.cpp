#include "../text_lib/std_lib_facilities.h"

// QA OBSERVATION: std::inner_product!

double get_index(const vector<double>& p, const vector<double>& w)
{
    if (p.size() != w.size()) error("get_index: different sized vectors");

    double sum = 0;
    for (int i = 0; i < p.size(); ++i)
        sum += p[i] * w[i];
    return sum;
}

int main()
{
    vector<double> price = { 1.23, 3.18, 0.93, 2.80, 6.75 };
    vector<double> weight = { 1.2, 1.6, 1.4, 1.9, 1.1 };

    cout << get_index(price, weight) << '\n';
}
