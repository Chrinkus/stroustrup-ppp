#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

ostream& print_array(ostream& os, int* a, int n)
{
    for (int i = 0; i < n; ++i) os << a[i] << '\n';
    return os;
}

int main()
try {
    // Drill 2 - Pointers & Arrays
    int x = 7;
    int* p1 = &x;

    cout << "pointer " << p1 << " points to " << *p1 << '\n';

    int* p2 = new int[7];

    x = 1;
    for (int i = 0; i < 7; ++i) {
        p2[i] = x;
        x *= 2;
    }

    cout << "address " << p2 << '\n';

    for (int j = 0; j < 7; ++j)
        cout << p2[j] << '\t';

    cout << '\n';

    int* p3 = p2;
    p2 = p1;
    p2 = p3;

    cout << "pointer " << p1 << " points to " << *p1 << '\n';
    cout << "pointer " << p2 << " points to " << *p2 << '\n';

    delete[] p2;

    p1 = new int[10] {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    p2 = new int[10];

    for (int m = 0; m < 10; ++m)
        p2[m] = p1[m];
    
    for (int k = 0; k < 10; ++k)
        cout << p2[k] << '\t';
    cout << '\n';

    // vectors
    vector<int> v1 {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    vector<int> v2 (10);
    v2 = v1;

    for (int v : v2) cout << v << '\t';

    cout << '\n';
}
catch(exception& e) {
    cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Unknown exception\n";
    return 2;
}
