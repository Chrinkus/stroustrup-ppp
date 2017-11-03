#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main()
try {
    // File diagram from pg 436
    Point tl {100, 100};
    Simple_window win {tl, 600, 800, "Chapter 12 Ex 10"};

    // Point.h
    Text pl {Point{52, 48}, "Point.h"};
    pl.set_font_size(16);
    win.attach(pl);

    Rectangle pr {Point{50, 50}, 100, 30};
    pr.set_fill_color(Color::yellow);
    win.attach(pr);

    // Graph.h
    Text gl {Point{52, 148}, "Graph.h"};
    gl.set_font_size(16);
    win.attach(gl);

    Rectangle gr {Point{50, 150}, 100, 70};
    gr.set_fill_color(Color::yellow);
    win.attach(gr);

    // Graph.cpp
    Text gct {Point{27, 288}, "Graph.cpp"};
    gct.set_font_size(16);
    win.attach(gct);

    Rectangle gcr {Point{25, 290}, 50, 30};
    gcr.set_fill_color(Color::yellow);
    win.attach(gcr);

    // to be continued...

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
g++ -w -Wall -std=c++11 GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp ex10_file_diagram.cpp `fltk-config --ldflags --use-images` -o a.out
*/
