#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main()
try {
    // Program
    const Point tl {100, 100};
    Simple_window win {tl, 600, 400, "Chapter 13 Ex 12"};

    Vector_ref<Rectangle> vr;

    for (int i = 0; i < 16; ++i)
        for (int j = 0; j < 16; ++j) {
            vr.push_back(new Rectangle{Point{i*20, j*20}, 20, 20});
            vr[vr.size()-1].set_fill_color(Color{i * 16 + j});
            vr[vr.size()-1].set_color(Color::invisible);
            win.attach(vr[vr.size()-1]);
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
g++ -w -Wall -std=c++11 ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp ex13_color_matrix.cpp `fltk-config --ldflags --use-images` -o a.out
*/
