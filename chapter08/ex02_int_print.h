#include "../text_lib/std_lib_facilities.h"

// QA EDIT: changed this file to a header that ex03 includes and removed the
// identical ex_fac.h file.

void int_printer(string label, vector<int>& ints)
{
    cout << label << ": ";

    for (int i : ints)
        cout << i << ' ';

    cout << '\n';
}
