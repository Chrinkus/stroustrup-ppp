#include "../text_lib/std_lib_facilities.h"

int main()
{
    cout << "Please enter your name and age\n";

    string first_name = "???";
    double age = 0;

    cin >> first_name >> age;

    int months = age * 12;

    cout << "Hello, " << first_name << " (age " << months << " months)\n";
    return 0;
}
