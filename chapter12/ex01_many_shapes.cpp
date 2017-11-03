#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <string>
#include <iostream>
#include <vector>

using namespace Graph_lib;

// Examples 1-6

int main()
try {
    // window setup
    Point tl {100, 100};

    Simple_window win {tl, 600, 400, "Ch 12 Exercises"};
    win.wait_for_button();

    // ex01 - draw two rectangles, a Rectangle and a Polygon
    Rectangle r{Point{50, 50}, 50, 25};
    r.set_color(Color::blue);
    win.attach(r);

    Polygon rect;
    rect.add(Point{125, 50});
    rect.add(Point{175, 50});
    rect.add(Point{175, 75});
    rect.add(Point{125, 75});
    rect.set_color(Color::red);
    win.attach(rect);

    win.set_label("Ch 12 Ex 1");
    win.wait_for_button();

    // ex02 - draw a rectangle and place text inside
    Rectangle rt{Point{200, 50}, 100, 30};
    win.attach(rt);

    Text t {Point{205, 75}, "Howdy!"};
    t.set_font(Font::helvetica_bold);
    t.set_font_size(20);
    win.attach(t);

    win.set_label("Ch 12 Ex 2");
    win.wait_for_button();

    // ex03 - draw initials 150px high
    Text t1 {Point{50, 350}, "C"};
    t1.set_font(Font::courier);
    t1.set_font_size(150);

    Text t2 {Point{150, 350}, "G"};
    t2.set_font(Font::courier);
    t2.set_font_size(150);

    Text t3 {Point{250, 350}, "S"};
    t3.set_font(Font::courier);
    t3.set_font_size(150);
    
    t1.set_color(Color::magenta);
    t2.set_color(Color::yellow);
    t3.set_color(Color::green);
    win.attach(t1);
    win.attach(t2);
    win.attach(t3);

    win.set_label("Ch 12 Ex 3");
    win.wait_for_button();

    // ex04 - draw a 3x3 tic-tac-toe board
    Vector_ref<Rectangle> vr;
    int w = 50;
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            vr.push_back(new Rectangle{Point{350+w*col, 200+w*row}, w, w});
            int i = vr.size() - 1;

            i % 2 == 0
                ? vr[i].set_fill_color(Color::red)
                : vr[i].set_fill_color(Color::white);

            win.attach(vr[i]);
        }
    }

    win.set_label("Ch 12 Ex 4");
    win.wait_for_button();

    // ex05 - draw a huge rectangle
    Rectangle huge {Point{150, 150}, x_max() * 2 / 3, y_max() * 3 / 4};
    huge.set_style(Line_style(Line_style::solid, 8));
    huge.set_color(Color::red);

    win.attach(huge);
    win.set_label("Ch 12 Ex 5");
    win.wait_for_button();

    // ex06 - phenomena
    /* When a shape is drawn that doesn't fit in the window, the complete
     * shape is drawn "in the dark". Resizing the window reveals that the
     * full shape exists.
     * When a window is defined larger than the screen size, the window size
     * is reduced to fill 100% of the screen.
     */

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
g++ -w -Wall -std=c++11 GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp ex01_many_shapes.cpp `fltk-config --ldflags --use-images` -o a.out
*/
