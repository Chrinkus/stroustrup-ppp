#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"
#include "./ch13_tools.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main()
try {
    // Program
    const Point tl {100, 100};
    Simple_window win {tl, 600, 400, "Chapter 13 Ex 8"};

    Reg_hex h1 {Point{300, 200}, 100};
    win.attach(h1);

    Reg_hex h2 {Point{100, 100}, 25};
    h2.set_style(Line_style(Line_style::dash, 4));
    win.attach(h2);

    win.wait_for_button();
}
catch(exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "error\n";
    return 2;
}
/* Compile command
g++ -w -Wall -std=c++11 ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp ch13_tools.cpp ex08_reg_hex.cpp `fltk-config --ldflags --use-images` -o a.out
*/
