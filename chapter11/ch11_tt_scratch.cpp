#include "../text_lib/std_lib_facilities.h"

// This includes many of the 'Try This's from the chapter
// The final 'try this' is in the chapter drill

int main()
try {
    // Integer output
    /*
    cout << "decimal\t\t" << 1979 << '\t' << 38 << '\n' << hex
         << "hexadecimal\t" << 1979 << '\t' << 38 << '\n' << oct
         << "octal\t\t" << 1979 << '\t' << 38 << '\n';
    */

    // Integer input
    /*
    int a;
    int b;
    int c;
    int d;
    cin >> a >> hex >> b >> oct >> c >> d;
    cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';
    */

    // Floating point output
    cout << 1234.56789 << "\t\t(defaultfloat)\n" << fixed
         << 1234.56789 << "\t(fixed)\n" << scientific
         << 1234.56789 << "\t(scientific)\n";

    return 0;
}
catch(exception& e) {
    cerr << "Error: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Something terribad happened..\n";
    return 2;
}
