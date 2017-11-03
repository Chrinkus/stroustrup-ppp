#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"
#include "./ch13_tools.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main()
try {
    // Right triangle
    const Point tl {100, 100};
    Simple_window win {tl, 600, 400, "Chapter 13 Ex 14"};

    /*
    Right_triangle rt1 {Point{300, 200}, 100, 150};
    win.attach(rt1);

    Right_triangle rt2 {Point{200, 100}, 75, 125, 150};
    win.attach(rt2);
    */

    enum Palette {
        red=0, yellow, green, blue
    };

    Point next {200, 250};
    int a = 100;
    int b = 100;
    double o = 0;

    Vector_ref <Right_triangle> vr;

    for (int i = 0; i < 8; ++i) {
        vr.push_back(new Right_triangle{next, a, b, o});
        vr[vr.size()-1].set_fill_color(Color(i));
        win.attach(vr[vr.size()-1]);

        next.x -= cos((90 - o)*PI/180) * b;
        next.y -= sin((90 - o)*PI/180) * b;

        o -= 45;
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
g++ -w -Wall -std=c++11 ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp ch13_tools.cpp ex14_right_triangle.cpp `fltk-config --ldflags --use-images` -o a.out
*/
