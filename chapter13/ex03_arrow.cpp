#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"
#include "./Arrow.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main()
try {
    // Window
    const Point tl {100, 100};
    Simple_window win {tl, 600, 400, "Chapter 12 Ex 3"};

    Arrow a1 {Point{100, 100}, Point{250, 200}};
    win.attach(a1);

    Arrow a2 {Point{500, 300}, Point{500, 100}};
    a2.set_color(Color::dark_green);
    win.attach(a2);

    Arrow a3 {Point{525, 100}, Point{525, 300}};
    a3.set_color(Color::blue);
    win.attach(a3);

    Arrow a4 {Point{300, 50}, Point{100, 300}};
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
g++ -w -Wall -std=c++11 ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp Arrow.cpp ex03_arrow.cpp `fltk-config --ldflags --use-images` -o a.out
*/
