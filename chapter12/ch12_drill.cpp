#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <string>
#include <iostream>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
/*  included in text graphics lib
#include <stdexcept>

void error(string s)
{
    throw runtime_error(s);
}

void error(string s1, string s2)
{
    throw runtime_error(s1 + s2);
}
*/
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

using namespace Graph_lib;

int main()
try {
    // 1. empty Simple_window
    Point tl {100, 100};        // top left corner of window

    Simple_window win {tl, 600, 400, "My window"};
        // screen coordinate tl for top left corner
        // window size(600*400)
        // title: My window
    win.wait_for_button();      // display!

    // 2. add more examples
    // 12.7.3 Axis
    Axis xa {Axis::x, Point{20, 300}, 280, 10, "x axis"};   // make an Axis
    
    win.attach(xa);                 // attach xa to the window, win
    win.set_label("My window #2");  // relabel the window
    win.wait_for_button();          // display!

    Axis ya {Axis::y, Point{20, 300}, 280, 10, "y axis"};
    ya.set_color(Color::cyan);              // choose a color
    ya.label.set_color(Color::dark_red);    // choose a color for the text
    win.attach(ya);
    win.set_label("My window #3");
    win.wait_for_button();                  // display!

    // 12.7.4 Graphing a function
    Function sine {sin, 0, 100, Point{20, 150}, 1000, 50, 50};  // sine curve
        // plot sin() in the range [0:100) with (0,0) at (20,150)
        // using 1000 points; scale x values*50, scale y values*50

    win.attach(sine);
    win.set_label("My window #4");
    win.wait_for_button();
    
    // 12.7.5 Polygons
    sine.set_color(Color::blue);    // we changed our mind about sine's color

    Polygon poly;                   // a polygon; a Polygon is a kind of Shape
    poly.add(Point{300, 200});      // three points make a triangle
    poly.add(Point{350, 100});
    poly.add(Point{400, 200});

    poly.set_color(Color::red);
    poly.set_style(Line_style::dash);
    win.attach(poly);
    win.set_label("My window #5");
    win.wait_for_button();

    // 12.7.6 Rectangles
    Rectangle r {Point{200, 200}, 100, 50}; // top left corner, width, height
    win.attach(r);

    Closed_polyline poly_rect;
    poly_rect.add(Point{100, 50});
    poly_rect.add(Point{200, 50});
    poly_rect.add(Point{200, 100});
    poly_rect.add(Point{100, 100});
    poly_rect.add(Point{50, 75});
    win.attach(poly_rect);

    win.set_label("My window #6");
    win.wait_for_button();

    // 12.7.7 Fill
    r.set_fill_color(Color::yellow);    // color the inside of the rectangle
    poly.set_style(Line_style(Line_style::dash, 4));
    poly_rect.set_style(Line_style(Line_style::dash, 2));
    poly_rect.set_fill_color(Color::green);
    win.set_label("My window #7");
    win.wait_for_button();

    // 12.7.8 Text
    Text t {Point{150, 150}, "Hello, graphical world!"};
    win.attach(t);
    win.set_label("My window #8");
    win.wait_for_button();

    t.set_font(Font::times_bold);
    t.set_font_size(20);
    win.set_label("My window #9");
    win.wait_for_button();

    // 12.7.9 Images
    Image ii {Point{100, 50}, "./rob_bass.jpg"};
    win.attach(ii);
    win.set_label("My window #10");
    win.wait_for_button();

    ii.move(100, 200);
    win.set_label("My window #11");
    win.wait_for_button();

    // 12.7.10 And much more
    Circle c {Point{100, 200}, 50};
    Ellipse e {Point{100, 200}, 75, 25};
    e.set_color(Color::dark_red);
    Mark m {Point{100, 200}, 'x'};

    ostringstream oss;
    oss << "screen size: " << x_max() << "*" << y_max()
        << "; window size: " << win.x_max() << "*" << win.y_max();
    Text sizes {Point{100, 20}, oss.str()};

    Image cal {Point{225, 225}, "snow_cpp.gif"};
    cal.set_mask(Point{40, 40}, 200, 150);

    win.attach(c);
    win.attach(m);
    win.attach(e);

    win.attach(sizes);
    win.attach(cal);
    win.set_label("My window #12");
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
g++ -w -Wall -std=c++11 GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp ch12_drill.cpp `fltk-config --ldflags --use-images` -o a.out
*/
