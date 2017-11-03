#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"
#include "./Arc.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main()
try {
    // Window
    Point tl {100, 100};
    Simple_window win {tl, 600, 400, "Chapter 13 Ex 1"};

    // Reference
    Circle c {Point{300, 200}, 75};
    c.set_color(Color::yellow);
    win.attach(c);

    // Arc tests
    Arc a1 {Point{300, 200}, 50, 0, 90};
    a1.set_color(Color::blue);
    win.attach(a1);

    Arc a2 {Point{300, 200}, 100, 90, 180};
    a2.set_color(Color::red);
    win.attach(a2);

    Arc a3 {Point{300, 200}, 150, 90, 360};
    a3.set_color(Color::green);
    win.attach(a3);

    Arc a4 {Point{300, 200}, 100, 270, 360};
    a4.set_color(Color::red);
    win.attach(a4);

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
g++ -w -Wall -std=c++11 ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp Arc.cpp ex01_arc.cpp `fltk-config --ldflags --use-images` -o a.out
*/
