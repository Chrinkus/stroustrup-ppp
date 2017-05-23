#include "../text_lib/std_lib_facilities.h"

int main()
try {
    // Not sure what this question is asking for. Looked around online, could
    // not find a suitable answer. Seems like I'm supposed to do a post-
    // condition but unsure as to why.

    return 0;
}
catch(exception& e) {
    cerr << "Error: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Unknown exception!\n";
    return 2;
}
