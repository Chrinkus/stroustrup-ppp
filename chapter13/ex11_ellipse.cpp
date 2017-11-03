#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"

#include <string>
#include <iostream>
#include <cmath>

using namespace Graph_lib;

constexpr double PI = 3.14159265;

int main()
try {
    // Program
    const Point tl {100, 100};
    Simple_window win {tl, 600, 400, "Chapter 13 Ex 11"};

    Axis xa {Axis::x, Point{100, 200}, 400, 10, "x axis"};
    xa.set_color(Color::white);
    win.attach(xa);

    Axis ya {Axis::y, Point{300, 350}, 300, 10, "y axis"};
    ya.set_color(Color::white);
    win.attach(ya);

    Ellipse el {Point{300, 200}, 150, 100};
    el.set_color(Color::blue);
    el.set_style(Line_style(Line_style::solid, 4));
    win.attach(el);

    Mark f1 {el.focus1(), 'f'};
    win.attach(f1);

    Mark f2 {el.focus2(), 'f'};
    win.attach(f2);

    // Some point on the ellipse
    double angle = -60;
    double Px = el.center().x + el.major() * cos(angle*PI/180);
    double Py = el.center().y + el.minor() * sin(angle*PI/180);
    Mark P {Point{int(Px), int(Py)}, 'x'};
    win.attach(P);

    Line l1 {el.focus1(), Point{int(Px), int(Py)}};
    l1.set_color(Color::red);
    l1.set_style(Line_style(Line_style::dot, 2));
    win.attach(l1);

    Line l2 {el.focus2(), Point{int(Px), int(Py)}};
    l2.set_color(Color::red);
    l2.set_style(Line_style(Line_style::dot, 2));
    win.attach(l2);

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
g++ -w -Wall -std=c++11 ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp ex11_ellipse.cpp `fltk-config --ldflags --use-images` -o a.out
*/
