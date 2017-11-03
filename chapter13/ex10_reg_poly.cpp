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

    Reg_poly rp1 {Point{300, 200}, 8, 25};
    win.attach(rp1);

    Reg_poly rp2 {Point{300, 200}, 10, 40};
    rp2.set_style(Line_style(Line_style::dot, 2));
    win.attach(rp2);

    Reg_poly rp3 {Point{300, 200}, 13, 70};
    rp3.set_style(Line_style(Line_style::solid, 4));
    rp3.set_color(Color::red);
    win.attach(rp3);

    Reg_poly rp4 {Point{300, 200}, 3, 100};
    rp4.set_style(Line_style(Line_style::solid, 6));
    rp4.set_color(Color::dark_green);
    win.attach(rp4);

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
g++ -w -Wall -std=c++11 ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp ch13_tools.cpp ex10_reg_poly.cpp `fltk-config --ldflags --use-images` -o a.out
*/
