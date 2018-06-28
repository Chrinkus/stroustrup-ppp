//
// Stroustrup - Programming Principles & Practice
//
// Chapter 9 Exercise 12
//
// Day Zero and Off By One - Is January 1, 1970 day 0 or 1? The text refers to
// it as day 0 so that's what I will go with. However the long int stores the
// number of days SINCE day 0 so the following should hold true:
// - Date{0} --> (1970, January, 1)
// - Date{1} --> (1970, January, 2)
// - Date{365} --> (1971, January, 1)
//
// Y/M/D - Not sure if this is appropriate, the exercise indicates a "Date"
// should be represented by a single variable (the number of days). Still, when
// accessing a Date often we ask for both year and month so rather than running
// similar calculations (counting through the years), I'm caching the result.
//
// There are two ways the memory footprint could be improved if we were storing
// many dates but not querying y/m/d as often:
// 1. Make the Date_rep member a pointer to a heap allocated object and store
// only an 8-byte unique_ptr to it.
// 2. Store the y/m/d quantities in a 32-bit bitfield. This works since month
// and day have smaller maximum values, leaving room in the field for whatever
// else may be wanted (perhaps the cache_valid object as well). Reduces memory
// of cache to 4 bytes (down from 16!).
//
// struct Date_rep {
//     unsigned int year: 12,       // max value 4095
//     unsigned int month: 4,       // max value 15
//     unsigned int day: 5,         // max value 31
//     bool valid: 1
// };
// 
// Actually solution 2 is better in all regards. The only issue is overloading
// the increment operator of Month since you can't take a reference to a
// bitfield value.
//

#ifndef EX_12_DATE_H
#define EX_12_DATE_H

#include <iostream>
#include <vector>

namespace Chrono_days {

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    enum class Month {
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    const std::vector<std::string> Month_tbl { "unused",    // burn 0 index
        "January", "February", "March", "April", "May", "June", "July",
        "August", "September", "October", "November", "December"
    };

    Month operator++(Month& m);

    std::ostream& operator<<(std::ostream& os, const Month& m);

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    enum class Day {
        sun, mon, tue, wed, thu, fri, sat
    };

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    struct Date_rep {
        int year = 1970;
        Month month = Month::jan;
        int day = 1;
    };

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    class Date {
    public:
        class Invalid { };              // to throw as exception

        Date(long int);                 // check for valid date and initialize
        Date() : days{0} { }            // default constructor

        // non-modifying operations:
        int day() const;
        Month month() const;
        int year() const;

        // modifying operations (invalidate cache):
        void add_day(int n);
        void add_month(int n);
        void add_year(int n);

        // added to this implementation
        long int get_days() const { return days; }
        void update_cache() const;

    private:
        long int days;

        mutable bool cache_valid = false;
        mutable Date_rep cache;
    };

    bool is_date(long int);             // true for valid date
    bool is_leapyear(int y);            // true if y is a leap year
    int days_in_month(int y, Month m);


    bool operator==(const Date& a, const Date& b);
    bool operator!=(const Date& a, const Date& b);

    std::ostream& operator<<(std::ostream& os, const Date& d);
    std::istream& operator>>(std::istream& is, Date& d);

    /*
    Day day_of_week(const Date& d);
    Date next_sunday(const Date& d);
    Date next_weekday(const Date& d);
    */

}       // Chrono_days

#endif  // EX_12_DATE_H
