#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"
#include "./ch13_tools.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main()
try {
    // Star
    const Point tl {100, 100};
    Simple_window win {tl, 600, 400, "Chapter 13 Ex 19"};

    Star s1 {Point{300, 200}, 100, 5, 2};
    s1.set_fill_color(Color::red);
    win.attach(s1);

    Star s2 {Point{100, 100}, 50, 7, 3};
    s2.set_color(Color::blue);
    s2.set_fill_color(Color::white);
    s2.set_style(Line_style(Line_style::dash, 2));
    win.attach(s2);

    Star s3 {Point{400, 300}, 60, 10, 3};
    s3.set_color(Color::dark_green);
    win.attach(s3);

    Star s4 {Point{350, 100}, 40, 8, 3};
    s4.set_color(Color::invisible);
    s4.set_fill_color(Color::magenta);
    win.attach(s4);

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
g++ -w -Wall -std=c++11 ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp ch13_tools.cpp ex19_star.cpp `fltk-config --ldflags --use-images` -o a.out
*/
