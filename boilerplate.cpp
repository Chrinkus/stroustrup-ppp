#include "../text_lib/std_lib_facilities.h"

int main()
try {
    // Program
    
    return 0;
}
catch(exception& e) {
    cerr << "error: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Unknown exception!\n";
    return 2;
}
