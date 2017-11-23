// Graphics library headers
#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"

// Chapter tools
#include "./ch15_tools.h"

// Standard headers
#include <iostream>
#include <stdexcept>

using namespace Graph_lib;      // includes using namespace std

struct Distribution {
    double height;
    double people;
};

istream& operator>>(istream& is, Distribution& d)
    // assume format: (height, people)
{
    char ch1 = 0;
    char ch2 = 0;
    char ch3 = 0;
    Distribution dd;

    if (is >> ch1 >> dd.height
            >> ch2 >> dd.people
            >> ch3) {
        if (ch1 != '(' || ch2 != ',' || ch3 != ')') {
            is.clear(ios_base::failbit);
            return is;
        }
    }
    else 
        return is;

    d = dd;
    return is;
}

int main()
try {
    string iname {"heights.txt"};
    ifstream ifs {iname};
    if (!ifs) error("Could not open file ", iname);

    vector<Distribution> vd;
    for (Distribution d; ifs >> d; )
        vd.push_back(d);

    // Boilerplate
    constexpr int xmax = 600;
    constexpr int ymax = 400;

    Simple_window win {Point{100, 100}, 600, 400, "Chapter 15"};

    vector<double> data;
    for (auto d : vd)
        data.push_back(d.people);

    Bar_graph bg {data, xmax, ymax};
    bg.set_labels("Distribution of Heights", "Heights 170:195", "People");
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
g++ -w -Wall -std=c++11 ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp ch15_tools.cpp ex08_heights.cpp `fltk-config --ldflags --use-images` -o a.out
*/
