#include "chrono.h"
#include <iostream>

using namespace Chrono;
using std::cout;

/* My Big Fat Mistake
 * ==================
 * So I struggled here forEVER because I kept getting an error when compiling
 * that my x86 architecture blah-blah-blah couldn't do anything. As it turned
 * out, I had added the chrono header file to my library project but forgot
 * to compile the chrono source file with the other sources. So much time lost.
 */

int main()
{
    // Basic functionality
    Date d{2017, Month::jul, 17};

    cout << d << '\n';

    // Exercise 10 - leapyear
    Date l{2016, Month::feb, 27};

    cout << "Was " << d << " a leapyear?: " << leapyear(d.year()) << '\n';
    cout << "Was " << l << " a leapyear?: " << leapyear(l.year()) << '\n';
}
