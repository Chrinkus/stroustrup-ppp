#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"
#include "./ch13_tools.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main()
try {
    // Window
    const Point tl {100, 100};
    Simple_window win {tl, 600, 400, "Chapter 13 Ex 6"};

    Text_box shape {Point{50, 50}, 100, 50, "Shape"};
    win.attach(shape);

    Text_box rect {Point{50, 200}, 100, 50, "Rectangle"};
    win.attach(rect);

    Text_box tb {Point{50, 300}, 100, 50, "Textbox"};
    win.attach(tb);

    Text_box circ {Point{200, 200}, 100, 50, "Circle"};
    win.attach(circ);

    Arrow a1 {n(rect), s(shape)};
    win.attach(a1);

    Arrow a2 {n(tb), s(rect)};
    win.attach(a2);

    Arrow a3 {nw(circ), se(shape)};
    win.attach(a3);

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
g++ -w -Wall -std=c++11 ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp ch13_tools.cpp ex06_diagram.cpp `fltk-config --ldflags --use-images` -o a.out
*/
