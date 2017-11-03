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

    Circle c {Point{300, 200}, 125};
    c.set_style(Line_style(Line_style::solid, 2));
    c.set_color(Color::white);
    win.attach(c);

    int ox = c.center().x + c.radius();
    int oy = c.center().y;
    Mark m {Point{ox, oy}, 'x'};
    win.attach(m);

    win.wait_for_button();

    for (int i = 0; i < 360; i += 15) {
        int dx = ox - (c.center().x + cos(i*PI/180)*c.radius());
        int dy = oy - (c.center().y + sin(i*PI/180)*c.radius());

        m.move(-dx, -dy);
        win.wait_for_button();

        ox -= dx;
        oy -= dy;
    }

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
g++ -w -Wall -std=c++11 ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp ex12_circ_mark.cpp `fltk-config --ldflags --use-images` -o a.out
*/
