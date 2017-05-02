#include "../text_lib/std_lib_facilities.h"

int main()
{
    // Program
    constexpr double yen_to_dollars = 0.0089381;
    constexpr double krona_to_dollars = 0.11;
    constexpr double pounds_to_dollars = 1.29;

    double amount = 1;

    char unit = ' ';

    cout << "Enter a foreign currency to convert (y, k, p):\n";
    cin >> amount >> unit;

    switch (unit) {
        case 'y':
            cout << amount << unit << " equals $"
                 << amount * yen_to_dollars << '\n';
            break;
        case 'k':
            cout << amount << unit << " equals $"
                 << amount * krona_to_dollars << '\n';
            break;
        case 'p':
            cout << amount << unit << " equals $"
                 << amount * pounds_to_dollars << '\n';
            break;
        default:
        cout << "Sorry, I'm not able to convert that currency.\n";
    }
}
