#include "../text_lib/std_lib_facilities.h"

int main()
{
    // Program
    cout << "Please enter 3 integer values to sort:\n";
    int val1;
    int val2;
    int val3;
    int greatest = 0;
    int middlest = 0;
    int smallest = 0;
    cin >> val1 >> val2 >> val3;

    if (val1 < val2 && val1 < val3) {

        smallest = val1;

        if (val2 < val3) {
            middlest = val2;
            greatest = val3;
        } else {
            middlest = val3;
            greatest = val2;
        }

    } else if (val2 < val3){

        smallest = val2;

        if (val1 < val3) {
            middlest = val1;
            greatest = val3;
        } else {
            middlest = val3;
            greatest = val1;
        }

    } else {

        smallest = val3;

        if (val1 < val2) {
            middlest = val1;
            greatest = val2;
        } else {
            middlest = val2;
            greatest = val3;
        }
    }

    cout << smallest << " " << middlest << " " << greatest << '\n';
}
