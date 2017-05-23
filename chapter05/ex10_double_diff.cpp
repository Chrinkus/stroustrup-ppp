#include "../text_lib/std_lib_facilities.h"

int main()
try {
    // Program
    cout << "Please enter the number of values you'd like to sum: \n";
    int how_many = 0;
    cin >> how_many;

    vector<double> values;
    cout << "Please enter some integers (press '|' to stop): \n";
    for (double x; cin >> x; )
        values.push_back(x);
    if (values.size() < how_many)
        error("Less values provided than initially indicated.\n");

    vector<double> diffs;
    for (int j = 1; j < values.size(); ++j)
        diffs.push_back(values[j] - values[j - 1]);

    double sum = 0;
    cout << "The sum of the first " << how_many << " numbers ( ";

    for (int i = 0; i < how_many; ++i) {
        cout << values[i] << " ";
        sum += values[i];
    }

    cout << ") is " << sum << ".\n";

    cout << "The differences between entries were:\n" << "( ";
    for(double d : diffs)
        cout << d << ' ';
    cout << ")\n";

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
