#include "./ch16_tools.h"

#include <iostream>

int main()
try {
    My_window win {Point{100, 100}, 600, 400, "My Window"};
    return gui_main();
}
catch(exception& e) {
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}
/* Compile command
g++ -w -Wall -std=c++11 ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp ch16_tools.cpp ex01_my_window.cpp `fltk-config --ldflags --use-images` -o a.out
*/
