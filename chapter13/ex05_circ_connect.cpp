#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"
#include "./ch13_tools.h"

#include <iostream>

using namespace Graph_lib;

int main()
try {
    // Program
    const Point tl {100, 100};
    Simple_window win {tl, 600, 400, "Chapter 13 Ex 11"};

    Circle c1 {Point{100, 100}, 40};
    win.attach(c1);

    Circle c2 {Point{100, 300}, 40};
    win.attach(c2);

    Circle c3 {Point{500, 100}, 40};
    win.attach(c3);

    Circle c4 {Point{500, 300}, 40};
    win.attach(c4);

    Ellipse e1 {Point{300, 200}, 80, 40};
    win.attach(e1);

    Line l1 {s(c1), n(c2)};
    win.attach(l1);

    Line l2 {s(c3), n(c4)};
    win.attach(l2);

    Arrow a1 {e(c1), w(c3)};
    win.attach(a1);

    Arrow a2 {e(c2), w(c4)};
    win.attach(a2);

    Arrow a3 {nw(e1), se(c1)};
    win.attach(a3);

    Arrow a4 {ne(e1), sw(c3)};
    win.attach(a4);

    Line l3 {se(e1), nw(c4)};
    win.attach(l3);

    Line l4 {sw(e1), ne(c2)};
    win.attach(l4);

    win.wait_for_button();
}
catch(exception& e) {
    std::cerr << "exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "error\n";
    return 2;
}
/* Compile command
g++ -w -Wall -std=c++11 ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp ch13_tools.cpp ex05_circ_connect.cpp `fltk-config --ldflags --use-images` -o a.out
*/

