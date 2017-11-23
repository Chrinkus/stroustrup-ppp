#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"

#include <iostream>

using namespace Graph_lib;

int main()
try {
    // Boilerplate
    constexpr int xmax = 600;
    constexpr int ymax = 400;
    constexpr int xc = xmax / 2;
    constexpr int yc = ymax / 2;
    constexpr int xscale = 20;
    constexpr int yscale = 20;
    constexpr int xlength = xmax - 40;
    constexpr int ylength = ymax - 40;

    Simple_window win {Point{100, 100}, xmax, ymax, "Chapter 15"};

    Axis x {Axis::x, Point{20, yc},
            xlength, xlength/xscale, "x"};
    Axis y {Axis::y, Point{xc, ylength + 20},
            ylength, ylength/yscale, "y"};
    x.set_color(Color::dark_red);
    y.set_color(Color::dark_red);

    win.attach(x);
    win.attach(y);
    win.wait_for_button();

    // Ex 4 - all the sin's & cos's
    constexpr double r_min = -10;
    constexpr double r_max = 11;
    const Point origin {xc, yc};

    Function f1 {sin, r_min, r_max, origin, 100, 25, 25};
    f1.set_color(Color::red);
    win.attach(f1);

    Function f2 {cos, r_min, r_max, origin, 100, 25, 25};
    f2.set_color(Color::blue);
    win.attach(f2);

    Function f3 {[](double x) { return sin(x) + cos(x); },
            r_min, r_max, origin, 100, 25, 25};
    f3.set_color(Color::green);
    win.attach(f3);

    Function f4 {[](double x) { return sin(x)*sin(x)+cos(x)*cos(x); },
            r_min, r_max, origin, 100, 25, 25};
    f4.set_color(Color::yellow);
    win.attach(f4);

    win.wait_for_button();
}
catch (exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch (...) {
    std::cerr << "Unknown exception\n";
    return 2;
}
/* Compile command
g++ -w -Wall -std=c++11 ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp ex04_sin_cos.cpp `fltk-config --ldflags --use-images` -o a.out
*/
