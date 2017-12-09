#include <iostream>

using std::cout;

// Replace all uppercase characters with lowercase in a C-style string. No
// standard library functions.

void to_lower(char* s)
    // If any char code falls between A & Z increase their code by 32, the
    // difference between upper and lower-case counterparts in ASCII.
{
    constexpr int A = 65;
    constexpr int Z = 90;
    constexpr int diff = 32;

    for (int i = 0; s[i]; ++i) {
        int code = int(s[i]);

        if (A <= code && code <= Z)
            s[i] += diff;
    }
}

int main()
{
    char ac1[] = "HowdY";
    to_lower(ac1);

    cout << ac1 << '\n';

    char ac2[] = "ThiS serIAl KiLleR leTTeR iS sCarY, OR NOT!!";
    to_lower(ac2);

    cout << ac2 << '\n';
}

// BEGIN STRIKEOUT
// I had to look up C-style strings and found this method of initialization.
// The chapter does not actually indicate how to create a C-style string so
// I've gone with this. If it's wrong its wrong.
//
// The print out still prints the '0' but as it is a C-style string I assume it
// should stay.
// END STRIKEOUT
//
// EDIT: I looked ahead in the text and found this C-string solution.
//
// The original test for '0' was incorrect as the terminating character is NULL
// and not zero. The truthy check is great!
