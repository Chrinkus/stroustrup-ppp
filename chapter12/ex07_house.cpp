#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main()
try {
    // window setup
    Point tl {200, 200};
    Simple_window win {tl, 600, 400, "Chapter 12 Exercises"};
    win.wait_for_button();

    // body
    Rectangle body{Point{200, 200}, 200, 100};
    body.set_color(Color::blue);
    body.set_fill_color(Color::blue);
    win.attach(body);

    // chimney
    Rectangle chimney{Point{225, 125}, 25, 75};
    chimney.set_color(Color::red);
    chimney.set_fill_color(Color::red);
    win.attach(chimney);

    // roof
    Polygon roof;
    roof.add(Point{300, 100});
    roof.add(Point{420, 200});
    roof.add(Point{180, 200});
    roof.set_color(Color::black);
    roof.set_fill_color(Color::black);
    win.attach(roof);

    // door
    Rectangle door{Point{280, 240}, 40, 60};
    door.set_color(Color::white);
    door.set_fill_color(Color::white);
    win.attach(door);

    Mark m{Point{290, 270}, 'o'};
    win.attach(m);

    // windows
    Rectangle window1{Point{235, 235}, 30, 30};
    window1.set_color(Color::white);
    window1.set_fill_color(Color::dark_blue);
    window1.set_style(Line_style(Line_style::solid, 4));
    win.attach(window1);

    Rectangle window2{Point{335, 235}, 30, 30};
    window2.set_color(Color::white);
    window2.set_fill_color(Color::dark_blue);
    window2.set_style(Line_style(Line_style::solid, 4));
    win.attach(window2);

    win.set_label("Ch 12 Ex 7");
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
g++ -w -Wall -std=c++11 GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp ex07_house.cpp `fltk-config --ldflags --use-images` -o a.out
*/
