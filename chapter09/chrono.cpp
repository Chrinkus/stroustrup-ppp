#include "chrono.h"

namespace Chrono {

    ostream& operator<<(ostream& os, const Month m)
    {
        vector<string> month_tbl = {
            "", "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
        };

        return os << month_tbl[int(m)];
    }

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
        d{default_date().day()}
    {
    }

    void Date::add_day(int n)
    {
        // ...
    }

    void Date::add_month(int n)
    {
        // ...
    }

    void Date::add_year(int n)
    {
        if (m==Month::feb && d==29 && !leapyear(y+n)) {
            m = Month::mar;
            d = 1;
        }
        y += n;
    }

    // helper functions
    bool is_date(int y, Month m, int d)
    {
        // assume that y is valid

        if (d <= 0) return false;
        if (m < Month::jan || Month::dec < m) return false;

        int days_in_month = 31;     // set default days to 31

        switch(m) {
            // handle feb
            case Month::feb:
                days_in_month = (leapyear(y)) ? 29 : 28;
                break;
            // handle 30 day months
            case Month::apr:
            case Month::jun:
            case Month::sep:
            case Month::nov:
                days_in_month = 30;
                break;
            // do nothing for 31 day months
            case Month::jan:    case Month::mar:    case Month::may:
            case Month::jul:    case Month::aug:    case Month::oct:
            case Month::dec:
            default:
                break;
        }

        if (days_in_month < d) return false;

        return true;
    }

    bool leapyear(int y)
    {
        // Exercise 10
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
            is.clear(std::ios_base::failbit);                // set the fail bit
            return is;
        }

        dd = Date(y, Month(m), d);

        return is;
    }

    /*
    Day day_of_week(const Date& d)
    {
        // ...
    }

    Date next_Sunday(const Date& d)
    {
        // ...
    }

    Date next_weekday(const Date& d)
    {
        // ...
    }
    */
}   // Chrono
