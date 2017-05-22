#include "../text_lib/std_lib_facilities.h"

int main()
try {
    // Program
    cout << "Please enter the number of values you'd like to sum: \n";
    int how_many = 0;
    cin >> how_many;

    vector<int> values;
    cout << "Please enter some integers (press '|' to stop): \n";
    for (int x; cin >> x; )
        values.push_back(x);
    if (values.size() < how_many)
        error("Less values provided than initially indicated.\n");

    int sum = 0;
    cout << "The sum of the first " << how_many << " numbers ( ";

    for (int i = 0; i < how_many; ++i) {
        cout << values[i] << " ";
        sum += values[i];
    }

    cout << ") is " << sum << ".\n";

    return 0;
}
catch(exception& e) {
    cerr << "Error: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Unknown exception!\n";
    return 2;
}
