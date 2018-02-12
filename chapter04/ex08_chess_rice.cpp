#include "../text_lib/std_lib_facilities.h"

int main()
{
    // Number of rice per square
    int square = 1;
    int rice = 1;
    int target = 0;

    cout << "How many grains do you want?\n";
    cin >> target;

    while (rice < target) {
        rice *= 2;
        square += 1;
    }

    cout << "# of grains of rice: " << rice
         << " chess square #: " << square << '\n';
}
