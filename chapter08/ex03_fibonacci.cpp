#include "../text_lib/std_lib_facilities.h"
#include "./ex02_int_print.h"

void fibonacci(int x, int y, vector<int>& v, int n)
{
    if (n < 2) error("desired size of vector is smaller than 2\n");

    v.push_back(x);
    v.push_back(y);

    int pre = y;
    int cur = x + y;
    int temp = 0;
    for (int i = 2; i < n; ++i) {
        v.push_back(cur);
        temp = cur;
        cur = pre + cur;
        pre = temp;
    }
}

int main()
{
    int val1 = 1;
    int val2 = 2;
    vector<int> ints;

    cout << "How many fibonacci numbers would you like to see?\n";
    int number_of_fibs;
    cin >> number_of_fibs;

    fibonacci(val1, val2, ints, number_of_fibs);

    int_printer("fibonacci", ints);

    return 0;
}
