//
// Stroustrup - Programming Principles & Practice
//
// Chapter 18 Vector Drill
//

#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

vector<int> gv {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(vector<int> v)
{
    vector<int> lv(10);
    lv = v;
    for (auto& a : lv)
        cout << a << '\t';
    cout << '\n';

    vector<int> lv2 = v;
    for (auto& a : lv2)
        cout << a << '\t';
    cout << '\n';
}

int fac(int n) { return n > 1 ? n * fac(n - 1) : 1; }

int main()
try {
    // code
    f(gv);

    vector<int> vv(10);
    for (int i = 0; i < vv.size(); ++i)
        vv[i] = fac(i + 1);
    f(vv);
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

