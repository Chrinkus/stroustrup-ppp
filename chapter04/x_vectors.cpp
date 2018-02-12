#include "../text_lib/std_lib_facilities.h"

int main()
{
    /*
    vector<int> v = { 5, 7, 9, 4, 6, 8 };
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << '\n';
    */

    /*
    vector<char> c = { 'a', 'c', 'e', 'b', 'd' };
    for (char x : c)
        cout << x << '\n';
    */

    vector<double> v;
    v.push_back(2.7);
    v.push_back(5.6);
    v.push_back(7.9);

    for (double x : v)
        cout << x << '\n';
}
