#include "../text_lib/std_lib_facilities.h"

int main()
{
    // Program
    int smallest = 0;
    int largest = 0;
    int mode = 0;
    int mode_count = 0;
    int test_mode = 0;
    int test_mode_count = 0;

    vector<int> input_set;

    int input;
    cout << "Fill the set with ints!\n";
    while (cin >> input) {
        input_set.push_back(input);

        if (smallest == 0 && largest == 0) {
            smallest = input;
            largest = input;
        } else {
            if (input < smallest) {
                smallest = input;
                cout << "New smallest!\n";
            }

            if (input > largest) {
                largest = input;
                cout << "New largest!\n";
            }
        }
    }

    sort(input_set);

    // Compute
    for (int i = 0; i < input_set.size(); ++i)
        if (i == 0 || input_set[i - 1] == input_set[i]) {
            test_mode = input_set[i];
            ++test_mode_count;
        } else {
            if (test_mode_count > mode_count) {
                mode = test_mode;
                mode_count = test_mode_count;
            }
            test_mode_count = 1;
        }

    // Print
    for (int i : input_set)
        cout << i << "  ";

    cout << '\n';

    cout << "The smallest of this set is: " << smallest << '\n'
         << "The largest of this set is: " << largest << '\n';

    if (mode_count > 1)
        cout << "The mode of this set is: " << mode << '\n';
    else
        cout << "There were no repeated values." << '\n';
}
