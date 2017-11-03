#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main()
try {
    Point tl {100, 100};
    Simple_window win {tl, 600, 400, "Chapter 12 Ex 8"};

    // Olympic rings
    Circle bl {Point{100, 100}, 75};
    bl.set_style(Line_style(Line_style::solid, 12));
    bl.set_color(Color::blue);
    win.attach(bl);

    Circle yl {Point{180, 175}, 75};
    yl.set_style(Line_style(Line_style::solid, 12));
    yl.set_color(Color::yellow);
    win.attach(yl);

    Circle bk {Point{260, 100}, 75};
    bk.set_style(Line_style(Line_style::solid, 12));
    bk.set_color(Color::black);
    win.attach(bk);

    Circle gn {Point{340, 175}, 75};
    gn.set_style(Line_style(Line_style::solid, 12));
    gn.set_color(Color::green);
    win.attach(gn);

    Circle rd {Point{420, 100}, 75};
    rd.set_style(Line_style(Line_style::solid, 12));
    rd.set_color(Color::red);
    win.attach(rd);

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
g++ -w -Wall -std=c++11 GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp ex08_olympic.cpp `fltk-config --ldflags --use-images` -o a.out
*/
