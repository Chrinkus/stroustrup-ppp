#include "../text_lib/std_lib_facilities.h"

int main()
{
    double d = 0;
    while (cin>>d) {

        int i = d;      // squeeze double into int
        char c = i;     // squeeze int into char
        int i2 = c;     // get int value out of char
        cout << "d==" << d
             << " i==" << i
             << " i2==" << i2
             << " char(" << c << ")\n";
    }
}
