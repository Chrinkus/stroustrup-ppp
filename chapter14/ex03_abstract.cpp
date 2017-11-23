#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"
#include "./ch14_tools.h"

#include <iostream>

struct Vehicle {
    void horn() const { cout << "beep beep!\n"; }

protected:
    Vehicle() { }
};

int main()
try {
    const Point tl {100, 100};
    Simple_window win {tl, 600, 400, "Chapter 14 Ex 1"};

    Vehicle v;      // Error: calling a protected constructor

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
g++ -w -Wall -std=c++11 ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp ch14_tools.cpp ex03_abstract.cpp `fltk-config --ldflags --use-images` -o a.out
*/
