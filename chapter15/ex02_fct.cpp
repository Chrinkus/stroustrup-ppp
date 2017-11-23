#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"
#include "./ch15_tools.h"

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
    x.set_color(Color::red);
    y.set_color(Color::red);

    win.attach(x);
    win.attach(y);
    win.wait_for_button();

    // Ex 2 - Fct
    Func f1 {[](double x) { return x/2; }, -10, 11, Point{xc, yc},
            400, xscale, yscale};
    win.attach(f1);
    win.wait_for_button();

    win.detach(f1);

    f1.set_function([](double x) { return x*2; });
    win.attach(f1);

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
g++ -w -Wall -std=c++11 ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp ch15_tools.cpp ex02_fct.cpp `fltk-config --ldflags --use-images` -o a.out
*/
