#include "../text_lib/std_lib_facilities.h"

int maxv(const vector<double>& v)
{
    int ele = 0;
    double max = v[0];

    for (int i = 0; i < v.size(); ++i) {
        if (v[i] > max) {
            max = v[i];
            ele = i;
        }
    }

    return ele;
}

int main()
{
    vector<double> test1 = { 1.2, 3.8, -1.5, 5, 2.2 };
    vector<double> test2 = { 20, 16, 8, 2, 12 };
    vector<double> test3 = { -12, -4.6, -10, -31.8 };

    cout << "Test 1's max ele is at " << maxv(test1) << '\n'
         << "Test 2's max ele is at " << maxv(test2) << '\n'
         << "Test 3's max ele is at " << maxv(test3) << '\n';
}
