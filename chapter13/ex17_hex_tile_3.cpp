#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"
#include "./ch13_tools.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main()
try {
    // Hexagon tile
    const Point tl {100, 100};
    Simple_window win {tl, 600, 400, "Chapter 13 Ex 17"};

    Vector_ref<Reg_hex> vr;
    int r = 25;

    for (int i = 0; i < win.y_max() / r; ++i)
        for (int j = 0; j < win.x_max() / (2 * r); ++j) {

            int x = j * r * 3;
            int y = i * sin(60*PI/180) * r;

            if (i % 2 == 1) x += r + cos(60*PI/180) * r;

            vr.push_back(new Reg_hex{Point{x, y}, r});
            vr[vr.size()-1].set_fill_color(Color((i+j)%8));
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
g++ -w -Wall -std=c++11 ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp ch13_tools.cpp ex17_hex_tile_3.cpp `fltk-config --ldflags --use-images` -o a.out
*/
