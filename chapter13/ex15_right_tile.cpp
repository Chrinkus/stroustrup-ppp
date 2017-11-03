#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"
#include "./ch13_tools.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main()
try {
    // Right_triangle tile
    const Point tl {100, 100};
    Simple_window win {tl, 600, 400, "Chapter 13 Ex 15"};

    int a = 50;
    int b = 30;

    Vector_ref<Right_triangle> vr;

    for (int i = 0; i < 400 / b; ++i) {
        int y = i * b + b;
        for (int j = 0; j < 600 / a; ++j) {
            int x = j * a;
            vr.push_back(new Right_triangle{Point{x,y}, a, b});
            win.attach(vr[vr.size()-1]);
        }
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
g++ -w -Wall -std=c++11 ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp ch13_tools.cpp ex15_right_tile.cpp `fltk-config --ldflags --use-images` -o a.out
*/
