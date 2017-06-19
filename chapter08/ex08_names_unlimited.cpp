#include "../text_lib/std_lib_facilities.h"

int main()
{
    vector<string> names;
    vector<int> ages;

    cout << "Enter some names(terminate with 'DONE'):\n";

    while (true) {
        string n;
        cin >> n;
        if (n == "DONE") break;
        names.push_back(n);
    }

    for (string n : names) {
        cout << "How old is " << n << "? ";
        int a;
        cin >> a;
        ages.push_back(a);
    }

    if (names.size() != ages.size())
        error("Somehow ages and names do not match up");

    cout << '\n'
         << "List of names and ages:\n";
    for (int i = 0; i < names.size(); ++i)
        cout << names[i] << ' ' << ages[i] << '\n';

    vector<string> unordered_names = names;
    vector<int> ordered_ages;

    sort(names.begin(), names.end());

    for (string n : names)
        for (int i = 0; i < unordered_names.size(); ++i)
            if (n == unordered_names[i]) ordered_ages.push_back(ages[i]);

    cout << '\n'
         << "Sorted by name:\n";
    for (int i = 0; i < names.size(); ++i)
        cout << names[i] << ' ' << ordered_ages[i] << '\n';
}
