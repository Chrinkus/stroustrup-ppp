#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"
#include "./ch14_tools.h"

#include <iostream>

int main()
try {
    const Point tl {100, 100};
    Simple_window win {tl, 600, 400, "Chapter 14 Ex 1"};

    Group grp;

    Circle circ {Point{100, 100}, 50};
    win.attach(circ);
    grp.add(circ);

    Rectangle rect {Point{200, 200}, 60, 120};
    win.attach(rect);
    grp.add(rect);

    Octagon oct {Point{400, 100}, 48};
    win.attach(oct);
    grp.add(oct);

    win.wait_for_button();

    grp.set_color(Color::red);
    win.wait_for_button();

    grp.set_fill_color(Color::yellow);
    win.wait_for_button();

    grp.move(100, 25);
    win.wait_for_button();

    grp.set_style(Line_style(Line_style::dot, 4));
    win.wait_for_button();
}
catch (exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch (...) {
    std::cerr << "Unknown error!\n";
    return 2;
}
/* Compile command
g++ -w -Wall -std=c++11 ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp ch14_tools.cpp ex09_group.cpp `fltk-config --ldflags --use-images` -o a.out
*/
