#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"
#include "./ch13_tools.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main()
try {
    // Program
    const Point tl {100, 100};
    Simple_window win {tl, 600, 400, "Chapter 13 Ex 8"};

    Vector_ref<Reg_hex> vr;

    int grid_size = 8;
    int hex_r = 25;

    for (int i = 0; i < grid_size; ++i)
        for (int j = 0; j < grid_size; ++j) {
            int x = 50 + j * hex_r * 3;
            int y = 50 + i * hex_r * 2;
            vr.push_back(new Reg_hex{Point{x, y}, hex_r});
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
g++ -w -Wall -std=c++11 ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp ch13_tools.cpp ex09_hex_tile.cpp `fltk-config --ldflags --use-images` -o a.out
*/
