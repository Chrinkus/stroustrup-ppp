// Graphics library headers
#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"

// Chapter tools
#include "./ch15_tools.h"

// Standard headers
#include <iostream>
#include <stdexcept>

using namespace Graph_lib;      // includes using namespace std

struct River_data {
    string name;
    int length;
};

istream& operator>>(istream& is, River_data& r)
    // assume format: name length
{
    River_data rr;

    string n;
    int l;
    for (char ch; is >> ch; ) {
        if (isdigit(ch)) {
            is.unget();
            is >> l;
            break;
        } else {
            n += ch;
        }
    }

    rr.name = n;
    rr.length = l;

    r = rr;
    return is;
}

int main()
try {
    string iname {"rivers.txt"};
    ifstream ifs {iname};
    if (!ifs) error("Could not open file ", iname);

    vector<River_data> vr;
    for (River_data r; ifs >> r; )
        vr.push_back(r);

    // Boilerplate
    constexpr int xmax = 600;
    constexpr int ymax = 400;

    Simple_window win {Point{100, 100}, 600, 400, "Chapter 15"};

    vector<double> data;
    for (auto r : vr)
        data.push_back(double(r.length));

    for (auto d : data)
        cout << d << '\n';

    Bar_graph bg {data, xmax, ymax};
    bg.set_labels("Canadian Rivers", "Rivers", "Length");
    win.attach(bg);

    win.wait_for_button();
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}
/* Compile command
g++ -w -Wall -std=c++11 ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp ch15_tools.cpp ex09_can_rivers.cpp `fltk-config --ldflags --use-images` -o a.out
*/
