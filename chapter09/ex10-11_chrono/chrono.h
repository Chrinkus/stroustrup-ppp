//#include "../text_lib/std_lib_facilities.h"
#include <iostream>
#include <vector>
#include <string>

using std::ostream;
using std::istream;
using std::vector;
using std::string;

namespace Chrono {

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// Month
    enum class Month {
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    const vector<string> Month_tbl { "unused",              // burn 0 index
        "January", "February", "March", "April", "May", "June", "July",
        "August", "September", "October", "November", "December"
    };

    Month operator++(Month& m);

    ostream& operator<<(ostream& os, const Month& m);

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// Day

    enum class Day {
        sun, mon, tues, wed, thur, fri, sat
    };

    const vector<string> Day_tbl { "Sunday", "Monday", "Tuesday",
        "Wednesday", "Thursday", "Friday", "Saturday"
    };

    Day operator++(Day& d);

    ostream& operator<<(ostream& os, const Day& d);

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// Date
    class Date {
        public:
            class Invalid { };              // to throw as exception

            Date(int y, Month m, int d);    // check for valid date and init
            Date();                         // default constructor
            // the default copy operations are fine
            
            // nonmodifying operations:
            int     day()   const { return d; }
            Month   month() const { return m; }
            int     year()  const { return y; }

            // modifying operations
            void add_day(int n);
            void add_month(int n);
            void add_year(int n);
        private:
            int     y;
            Month   m;
            int     d;
    };

    bool is_date(int y, Month m, int d);    // true for valid date
    bool leapyear(int y);                   // true if y is a leapyear
    int  days_in_month(int y, Month m);     // number of days in month
    int  days_in_month(const Date& d);      // overload

    Day  day_of_week(const Date& d);        // day of week of d
    Date day_one(const Date& d);            // first day of first week (Sunday)
    int  week_of_year(const Date& d);

    bool operator==(const Date& a, const Date& b);
    bool operator!=(const Date& a, const Date& b);
    bool operator<(const Date& a, const Date& b);

    ostream& operator<<(ostream& os, const Date& d);
    istream& operator>>(istream& is, Date& dd);

    Date next_sunday(Date d);               // next Sunday after d
    Date next_weekday(Date d);              // next weekday after d
}   // Chrono
