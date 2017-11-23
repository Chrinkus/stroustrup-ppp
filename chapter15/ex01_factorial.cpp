#include <iostream>

using namespace std;

int recur_fac(int n) { return n > 1 ? n * recur_fac(n - 1) : 1; }

int iter_fac(int n)
{
    int r = 1;
    while (n > 1) {
        r *= n;
        --n;
    }
    return r;
}

int main()
{
    cout << "Recursive factorial: " << recur_fac(10) << '\n'
         << "Iterative factorial: " << iter_fac(10) << '\n';
}
