#include <iostream>
#include <cmath>

using std::cout;

int main()
{
    cout << "Pointer fun:\n\n";

    int x = 37;
    int* p1 = &x;

    cout << "address " << p1 << " contains " << *p1 << '\n'
         << "address " << &x << " contains " << x << '\n';
    cout << '\n';

    cout << "Array fun:\n\n";

    int sz = 10;
    int* p2 = new int[sz];

    for (int i = 0; i < sz; ++i)
        p2[i] = pow(2, i);

    int n = 7;
    cout << "Cherry picking " << n << "th element: \n"
         << "address " << p2 + (n-1) << " contains " << p2[n-1] << '\n';

    int* p3 = p2;

    cout << "Array copying:\n";
    for (int j = 0; j < sz; ++j) {
        cout << "address " << p2 + j << " contains " << p2[j] << '\n';
        cout << "address " << p3 + j << " contains " << p3[j] << '\n';
    }
    cout << '\n';
}
