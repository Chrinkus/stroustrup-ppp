#include "../text_lib/std_lib_facilities.h"

// LOOKING BACK: This was straight out of my Java textbook in the semester of 
// computer science I took.

int main()
{
    // Program
    int pennies;
    int nickels;
    int dimes;
    int quarters;
    int half_dollars;
    int dollars;

    double total;

    cout << "How many pennies do you have?\n";
    cin >> pennies;
    total += pennies * 0.01;
    cout << "How many nickels do you have?\n";
    cin >> nickels;
    total += nickels * 0.05;
    cout << "How many dimes do you have?\n";
    cin >> dimes;
    total += dimes * 0.1;
    cout << "How many quarters do you have?\n";
    cin >> quarters;
    total += quarters * 0.25;
    cout << "How many half-dollars do you have?\n";
    cin >> half_dollars;
    total += half_dollars * 0.5;
    cout << "How many dollars do you have?\n";
    cin >> dollars;
    total += dollars * 1;

    cout << "You have " << pennies << " pennies.\n"
         << "You have " << nickels << " nickels.\n"
         << "You have " << dimes << " dimes.\n"
         << "You have " << quarters << " quarters.\n"
         << "You have " << half_dollars << " half-dollars.\n"
         << "You have " << dollars << " dollars.\n"
         << "The value of all of your coins is $" << total << ".\n";
}
