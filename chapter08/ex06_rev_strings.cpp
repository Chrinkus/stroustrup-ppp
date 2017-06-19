#include "../text_lib/std_lib_facilities.h"

vector<string> reverse(const vector<string>& v)
{
    vector<string> rev;

    for (int i = v.size() - 1; i >= 0; --i)
        rev.push_back(v[i]);

    return rev;
}

void reverse_in_place(vector<string>& v)
{
    int j = v.size() - 1;

    for (int i = 0; i < j - i; ++i) {
        swap(v[i], v[j - i]);
    }
}

void str_printer(string label, vector<string>& words)
{
    cout << label << ": ";

    for (string s : words)
        cout << s << ' ';

    cout << '\n';
}

int main()
{
    vector<string> test_odd = { "one", "three", "five", "seven", "nine" };
    vector<string> test_even = { "two", "four", "six", "eight" };

    cout << "Original Vectors\n"
         << "================\n";

    str_printer("odd", test_odd);
    str_printer("even", test_even);
    cout << '\n';

    cout << "Reversed Vectors\n"
         << "================\n";

    vector<string> rev_odd = reverse(test_odd);
    vector<string> rev_even = reverse(test_even);

    str_printer("odd", rev_odd);
    str_printer("even", rev_even);
    cout << '\n';

    cout << "Originals Again\n"
         << "===============\n";

    str_printer("odd", test_odd);
    str_printer("even", test_even);
    cout << '\n';

    cout << "Originals Reversed\n"
         << "==================\n";

    reverse_in_place(test_odd);
    reverse_in_place(test_even);

    str_printer("odd", test_odd);
    str_printer("even", test_even);
}
