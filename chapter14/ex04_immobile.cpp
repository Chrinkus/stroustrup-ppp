#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"
#include "./ch14_tools.h"

#include <iostream>

int main()
try {
    const Point tl {100, 100};
    Simple_window win {tl, 600, 400, "Chapter 14 Ex 1"};

    Immobile_circle ic {Point{300, 200}, 100};
    ic.move(100, 100);
    win.attach(ic);

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
g++ -w -Wall -std=c++11 ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp ch14_tools.cpp ex04_immobile.cpp `fltk-config --ldflags --use-images` -o a.out
*/
