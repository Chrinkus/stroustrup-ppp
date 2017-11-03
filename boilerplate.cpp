#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <string>
#include <iostream>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
#include <stdexcept>

void error(string s)
{
    throw runtime_error(s);
}

void error(string s1, string s2)
{
    throw runtime_error(s1 + s2);
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

using namespace Graph_lib;

int main()
try {
    // program
}
catch(exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "error\n";
    return 2;
}
