#include "../text_lib/std_lib_facilities.h"

int main()
{
    cout << "Please enter an integer: ";
    int n;
    double m;
    cin >> n;
    m = n;
    cout << "n == " << n
         << "\nn+1 == " << n+1
         << "\nthree times n == " << 3*n
         << "\ntwice n == " << n+n
         << "\nn squared == " << n*n
         << "\nhalf of n == " << n/2
         << "\nn mod 5 == " << n%5
         << "\nsquare root of n == " << sqrt(m)
         << '\n';
}
