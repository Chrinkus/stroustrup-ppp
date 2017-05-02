#include "../text_lib/std_lib_facilities.h"

// Implement a squaring function without using multiplication. Use this
// function to print all values from 0-99 and their square, separated by a tab
// character.

int archaic_square(int v) {
    int total = 0;

    for (int i = 0; i < v; ++i) {
        total += v;
    }

    return total;
}

int main()
{
    for (int i = 0; i < 100; ++i) {
        cout << i << '\t' << archaic_square(i) << '\n';
    }
}
