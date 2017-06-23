#include<iostream>

using namespace std;

unsigned long long int fibonacciFinderN(int n)
{
    unsigned long long int pre = 0;
    unsigned long long int cur = 1;
    unsigned long long int fib = 0;

    for (int i = 2; i < n; ++i) {
        fib = pre + cur;
        pre = cur;
        cur = fib;
    }

    return fib;
}

int main()
{
    cout << fibonacciFinderN(300) << '\n';

    return 0;
}
