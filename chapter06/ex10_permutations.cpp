#include "../text_lib/std_lib_facilities.h"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
int get_fac(int num)
{
    // Check for negative num
    if (num < 0) error("Cannot find factorials of negative numbers.");

    int fac = num;
    if (fac == 0)
        fac = 1;
    else
        for (int i = num - 1; i > 0; --i)
            fac *= i;

    cout << fac << '\n';
    return fac;
}
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
int find_perms(int a, int b)
{
    // Calculate the number of permutations of (a,b)
    if (a == 0 || b == 0) error("No permutations found for 0");
    if (a < b) error("Not enough numbers for set size");

    int answer = get_fac(a) / get_fac(a - b);

    return answer;
}
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
int find_combs(int a, int b)
{
    // Calculate the number of combinations of (a,b)
    int answer = find_perms(a, b) / get_fac(b);

    return answer;
}
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

int main()
try {
    // Program
    cout << "Please enter two numbers representing the number of possibles\n"
         << " and the size of the sets. Then indicate whether you want the\n"
         << " number of permutations ('p') or combinations ('c').\n";

    int a;
    int b;
    char f;
    cin >> a >> b >> f;

    string func;
    int answer;
    switch (f) {
        case 'p':
            func = "permutations";
            answer = find_perms(a, b);
            break;
        case 'c':
            func = "combinations";
            answer = find_combs(a, b);
            break;
        default:
            error("Invalid function request\n");
    }

    cout << "The number of " << func << " of " << a << " & " << b
        << " are " << answer << ".\n";
}
catch(exception& e) {
    cerr << "Error: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "undefined thing, yo!\n";
    return 2;
}
