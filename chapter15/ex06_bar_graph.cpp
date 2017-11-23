#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"
#include "./ch15_tools.h"

#include <iostream>

using namespace Graph_lib;

int main()
try {
    // Boilerplate
    constexpr int xmax = 600;
    constexpr int ymax = 400;

    Simple_window win {Point{100, 100}, xmax, ymax, "Chapter 15"};

    // Ex 6 - Bar Graph
    vector<double> data {6.2, 8.7, 7.3, 5.5, 9.1, 9.4, 6, 2.4, 4.2, 3.3, 8};
    Bar_graph bg {data, xmax, ymax};
    win.attach(bg);

    win.wait_for_button();
}
catch (exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch (...) {
    std::cerr << "Unknown exception\n";
    return 2;
}
/* Compile command
g++ -w -Wall -std=c++11 ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp ch15_tools.cpp ex06_bar_graph.cpp `fltk-config --ldflags --use-images` -o a.out
*/
