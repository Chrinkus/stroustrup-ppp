#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main()
try {
    // program
    Point tl {100, 100};
    Simple_window win {tl, 600, 400, "Chapter 12 Ex 9"};

    Image ii {Point{100, 25}, "./rob_bass.jpg"};
    win.attach(ii);

    Text caption {Point{120, 355}, "A robot playing bass"};
    caption.set_font(Font::helvetica);
    caption.set_font_size(20);
    win.attach(caption);

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
g++ -w -Wall -std=c++11 GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp ex09_image.cpp `fltk-config --ldflags --use-images` -o a.out
*/
