#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"
#include "./ch14_tools.h"

#include <iostream>

int main()
try {
    const Point tl {100, 100};
    Simple_window win {tl, 600, 400, "Chapter 14 Ex 1"};

    Octagon oc {Point{300, 200}, 100};
    oc.move(80, -60);
    oc.set_color(Color::red);
    oc.set_style(Line_style(Line_style::dash, 4));
    oc.set_fill_color(Color::white);

    /*
    cout << "Line style: " << oc.style() << '\n'
         << "Line color: " << oc.color() << '\n'
         << "Fill color: " << oc.fill_color() << '\n'
         << "Num points: " << oc.number_of_points() << '\n';
     */

    for (int i = 0; i < oc.number_of_points(); ++i) {
        cout << "Point " << i << ": " << oc.point(i).x << ", "
             << oc.point(i).y << '\n';
    }

    win.attach(oc);

    win.wait_for_button();
}
catch (exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch (...) {
    std::cerr << "Unknown error!\n";
    return 2;
}
/* Compile command
g++ -w -Wall -std=c++11 ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp ch14_tools.cpp ex08_octagon.cpp `fltk-config --ldflags --use-images` -o a.out
*/
