#include "../text_lib/std_lib_facilities.h"

int main()
{
    double input;
    double smallest = 0;
    double largest = 0;

    while (cin >> input) {
        if (smallest == 0 && largest == 0) {
            smallest = input;
            largest = input;
        }

        if (input < smallest) {
            smallest = input;
            cout << "smallest so far" << '\n';
        } else if (input > largest) {
            largest = input;
            cout << "largest so far" << '\n';
        }
    }
}
