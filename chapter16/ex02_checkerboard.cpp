#include "./ch16_tools.h"

#include <iostream>
#include <string>

struct Change_box : Out_box {
    Change_box(Point xy, int w, int h, const string& label)
        : Out_box{xy, w, h, label} { }

    void put_poop() { put("poop"); }
};

int main()
try {
    My_window win {Point{100, 100}, 600, 400, "Checkerboard"};

    Change_box outie{Point{250, 0}, 100, 20, "output:"};

    int w = 100;
    int h = 100;

    Button tl {Point{200, 100}, 100, 100, "?",
        [](Address, Address pw) { return; }};
    Button tr {Point{300, 100}, 100, 100, "?",
        [](Address, Address pw) { return; }};
    Button bl {Point{200, 200}, 100, 100, "?",
        [](Address, Address pw) { reference_to<Change_box>(pw).put_poop(); }};
    Button br {Point{300, 200}, 100, 100, "?",
        [](Address, Address pw) { return; }};

    win.attach(tl);
    win.attach(tr);
    win.attach(bl);
    win.attach(br);

    win.attach(outie);

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
g++ -w -Wall -std=c++11 ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp ch16_tools.cpp ex02_checkerboard.cpp `fltk-config --ldflags --use-images` -o a.out
*/
