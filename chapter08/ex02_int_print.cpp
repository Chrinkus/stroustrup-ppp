#include "../text_lib/std_lib_facilities.h"

void int_printer(string label, vector<int>& ints)
{
    cout << label << ": ";

    for (int i : ints)
        cout << i << ' ';

    cout << '\n';
}
