#include "chrono.h"

namespace Chrono {

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// Month
    Month operator++(Month& m)                  // prefix increment operator
    {
        m = (m == Month::dec) ? Month::jan : Month(int(m) + 1); // wrap around

        return m;
    }

    ostream& operator<<(ostream& os, const Month& m)
    {
        return os << Month_tbl[int(m)];
    }

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// Day
    Day operator++(Day& d)
    {
        d = (d == Day::sat) ? Day::sun : Day(int(d) + 1);

        return d;
    }

    ostream& operator<<(ostream& os, const Day& d)
    {
        return os << Day_tbl[int(d)];
    }

    Day day_of_week(const Date& d)
        // formula found in article from Universtity of Waterloo
        // https://cs.uwaterloo.ca/~alopez-o/math-faq/node73.html
    {
        int k = d.day();
        int m = int(d.month());
        int y = d.year();
        
        if (m > 2) {
            m -= 2;                 // adjust for month 1 = Mar
        }
        else {
            m += 10;
            --y;                    // Jan & Feb belong to previous year
        }

        int c = int(y / 100);       // the century portion
        y %= 100;                   // y becomes just the 2 digit year

        return Day(
            (k + int(2.6*m - 0.2) - 2*c + y + int(y/4) + int(c/4)) % 7
        );
    }

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// Date
    Date::Date(int yy, Month mm, int dd)
        : y{yy}, m{mm}, d{dd}
    {
        if (!is_date(yy, mm, dd)) throw Invalid{};
    }

    const Date& default_date()
    {
        static const Date dd{2001, Month::jan, 1}; // start of 21st century
        return dd;
    }

    Date::Date()
        : y{default_date().year()},
          m{default_date().month()},
          d{default_date().day()} { }

    void Date::add_day(int n)
        // n is positive
    {
        n += d - 1;             // end of months are wonky, all months have 1st
        d = 1;                  // set day to 1st and add offset to n

        while (n > 0) {                         // positive n's
            int days = days_in_month(y, m);

            if (n < days - d) {
                d += n;
                return;
            }

            n -= days;
            add_month(1);
        }

        while (n < 0) {                         // negative n's
            add_month(-1);
            n += days_in_month(y, m);

            if (n > 0) {
                d += n;
                return;
            }
        }
    }

    void Date::add_month(int n)
        // handles negative n
        // increase months and years if necessary
        // if day is out of next month's range set day to next month's last day
    {
        int months = int(m) + n;
        int neg_adj = (months > 0) ? 0 : 1;         // negative adjustment

        m = Month(months % 12 + neg_adj * 12);
        add_year(int(months / 12) - neg_adj * 1);

        if (d > 28) {               // only need to adjust days at end of month
            switch (m) {
                case Month::feb:
                    d = leapyear(y) ? 29 : 28;
                    break;
                case Month::apr:
                case Month::jun:
                case Month::sep:
                case Month::nov:
                    if (d == 31)
                        d = 30;
                    break;
                default:
                    break;
            }
        }
    }

    void Date::add_year(int n)
        // handles negative n
        // changed to maintain end of month consistency
    {
        if (m==Month::feb && d==29 && !leapyear(y+n)) {
            d = 28;
        }
        y += n;
    }

    // helper functions
    bool is_date(int y, Month m, int d)
    {
        // assume that y is valid

        if (d <= 0) return false;
        if (m < Month::jan || Month::dec < m) return false;

        if (days_in_month(y, m) < d) return false;

        return true;
    }

    int days_in_month(int y, Month m)
    {
        switch (m) {
            case Month::feb:
                return (leapyear(y)) ? 29 : 28;
            case Month::apr:
            case Month::jun:
            case Month::sep:
            case Month::nov:
                return 30;
            default:
                return 31;
        }
    }

    int days_in_month(const Date& d)
    {
        return days_in_month(d.year(), d.month());
    }

    bool leapyear(int y)
    {
        // Exercise 10
        // Changed to make conditional test for leapyear return more of an
        // intuitively "positive" result
        if (y % 4 == 0)
            return true;
        else
            return false;
    }

    bool operator==(const Date& a, const Date& b)
    {
        return a.year() == b.year()
            && a.month() == b.month()
            && a.day() == b.day();
    }

    bool operator!=(const Date& a, const Date& b)
    {
        return !(a == b);
    }

    bool operator<(const Date& a, const Date& b)
    {
        if (a.year() < b.year())
            return true;
        if (a.year() == b.year() && a.month() < b.month())
            return true;
        if (a.year() == b.year() && a.month() == b.month() &&
                a.day() < b.day())
            return true;

        return false;
    }

    ostream& operator<<(ostream& os, const Date& d)
    {
        return os << "(" << d.year()
                  << ", " << d.month()
                  << ", " << d.day()
                  << ")";
    }

    istream& operator>>(istream& is, Date& dd)
    {
        int y, m, d;
        char ch1, ch2, ch3, ch4;
        is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
        if (!is) return is;
        if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') {
            is.clear(std::ios_base::failbit);           // set the fail bit
            return is;
        }

        dd = Date(y, Month(m), d);

        return is;
    }

    Date day_one(const Date& d)
    {
        int year = d.year();

        // If d is in last 6 days of December it may belong to the next year.
        // Compare d's day_of_week to the distance from the earliest possible
        // first day of year (where Jan 1 is a Saturday).
        
        const int earliest_first_day = 26;
        if (d.month() == Month::dec && d.day() >= earliest_first_day) {
            if (int(day_of_week(d)) <= (d.day() - earliest_first_day))
                ++year;
        }

        Date d1 {year, Month::jan, 1};

        while (day_of_week(d1) != Day::sun)
            d1.add_day(-1);
        
        return d1;
    }

    // Ex 11
    int week_of_year(const Date& d)
    {
        Date iter{day_one(d)};

        if (iter == d)
            return 1;

        int week = 0;
        while (iter < d) {
            iter.add_day(7);
            ++week;
        }

        return week;
    }

    Date next_sunday(Date d)        // pass by value to operate directly on
    {
        while (day_of_week(d) != Day::sun)
            d.add_day(1);

        return d;
    }

    // Ex 11 - next_workday() alternative
    Date next_weekday(Date d)
    {
        Day weekday;

        do {
            d.add_day(1);
            weekday = day_of_week(d);
        } while (weekday == Day::sat || weekday == Day::sun);

        return d;
    }
}   // Chrono
