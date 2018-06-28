//
// Stroustrup - Programming Principles & Practice
//
// Chapter 9 Exercise 12
//
// Source file
//

#include "date.h"

namespace Chrono_days {

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    Month operator++(Month& m)                  // prefix increment operator
    {
        m = (m == Month::dec) ? Month::jan : Month(int(m) + 1); // wrap around

        return m;
    }

    std::ostream& operator<<(std::ostream& os, const Month& m)
    {
        return os << Month_tbl[int(m)];
    }

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    Date::Date(long int dd)
        : days{dd}
    {
        if (!is_date(dd)) throw Invalid{};
    }

    // No need for default_date function

    // non-modifying operations
    int Date::day() const
    {
        if (!cache_valid)
            update_cache();

        return cache.day;
    }

    Month Date::month() const
    {
        if (!cache_valid)
            update_cache();

        return cache.month;
    }

    int Date::year() const
    {
        if (!cache_valid)
            update_cache();

        return cache.year;
    }

    void Date::update_cache() const
    {
        int n = days + 1;               // +1 to count Jan 1
        cache.year = 1970;
        cache.month = Month::jan;

        // remove years
        int x;
        while ((x = is_leapyear(cache.year) ? 366 : 365) && n > x) {
            n -= x;
            ++cache.year;
        }

        // remove months
        while ((x = days_in_month(cache.year, cache.month)) && n > x) {
            n -= x;
            ++cache.month;
        }

        cache.day = n;
        cache_valid = true;
    }

    // modifying operations
    void Date::add_day(int n)
        // works for negativedays
    {
        cache_valid = false;
        days += n;
    }

    void Date::add_month(int n)
        // does not work for negative n
    {
        if (!cache_valid)
            update_cache();

        cache_valid = false;                // going to be modifying days
        days -= (cache.day - 1);            // set day to 1st of current month

        for ( ; n > 0; --n) {
            days += days_in_month(cache.year, cache.month);

            ++cache.month;
            if (cache.month == Month::jan)
                ++cache.year;
        }

        days += (cache.day - 1);            // give back taken days
    }

    void Date::add_year(int n)
    {
        if (!cache_valid)
            update_cache();

        cache_valid = false;

        for ( ; n > 0; --n) {
            bool leap = (cache.month > Month::feb)
                ? is_leapyear(cache.year + 1)
                : is_leapyear(cache.year);

            days += leap ? 366 : 365;
            ++cache.year;
        }
    }

    // helper functions
    bool is_date(long int dd)
    {
        return (dd < 0) ? false : true;
    }

    bool is_leapyear(int y)
    {
        return ((y % 4) == 0) ? true : false;
    }

    int days_in_month(int y, Month m)
    {
        switch (m) {
            case Month::feb:
                return is_leapyear(y) ? 29 : 28;
            case Month::apr:
            case Month::jun:
            case Month::sep:
            case Month::nov:
                return 30;
            default:
                return 31;
        }
    }

    bool operator==(const Date& a, const Date& b)
    {
        return a.get_days() == b.get_days();
    }

    bool operator!=(const Date& a, const Date& b)
    {
        return !(a == b);
    }

    std::ostream& operator<<(std::ostream& os, const Date& d)
    {
        return os << '(' << d.year() << ", "
                  << d.month() << ", "
                  << d.day() << ')';
    }

    std::istream& operator>>(std::istream& is, Date& dd)
        // need to burn a day since 'days' is the number of days since Jan 1,
        // 1970. (Jan 1 is not counted)
    {
        int y, m, d;
        char ch1, ch2, ch3, ch4;
        is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
        if (!is) return is;
        if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') {
            is.clear(std::ios_base::failbit);           // set the fail bit
            return is;
        }

        long int days = -1;                             // burnt day
        for (int i = 1970; i < y; ++i)
            days += is_leapyear(i) ? 366 : 365;

        for (int i = 1; i < m; ++i)
            days += days_in_month(y, Month(i));

        days += d;

        dd = Date{days};

        return is;
    }

}
