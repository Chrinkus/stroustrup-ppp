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
    cout << d << '\n';                  // (2017, July, 17)

    // Add month
    Date d2{2018, Month::jan, 31};
    cout << d2 << '\n';                 // (2018, January, 31)
    d2.add_month(1);
    cout << d2 << '\n';                 // (2018, February, 28)
    d2.add_month(1);
    cout << d2 << '\n';                 // (2018, March, 28)

    // Exercise 10 - leapyear
    Date l{2016, Month::feb, 27};

    cout << "Was " << d << " a leapyear?: " << leapyear(d.year()) << '\n';
    cout << "Was " << l << " a leapyear?: " << leapyear(l.year()) << '\n';

    // day_of_week
    Date d3 {2018, Month::jun, 22};
    cout << d3 << " was a " << day_of_week(d3) << '\n';

    Date d4{1979, Month::feb, 27};
    cout << d4 << " was a " << day_of_week(d4) << '\n';

    // add_day
    d3.add_day(10);
    cout << d3 << " <-- Should be July 2, 2018\n";

    d4.add_day(15000);
    cout << d4 << " <-- Should be March 23, 2020\n";
    cout << day_of_week(d4) << " <-- Should be Monday\n";

    // add_month negatives
    Date d5{2020, Month::feb, 29};
    d5.add_month(-1);
    cout << d5 << " <-- Should be January 29, 2020\n";
    d5.add_month(-5);
    cout << d5 << " <-- Should be August 29, 2019\n";
}
