#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

int main()
{
    using namespace Graph_lib;

    Point tl( 100, 100 );

    Simple_window win ( tl, 600, 400, "Canvas" );

    Polygon poly;

    poly.add(Point( 300, 200 ));
    poly.add(Point( 350, 100 ));
    poly.add(Point( 400, 200 ));

    poly.set_color(Color::red);

    win.attach(poly);

    win.wait_for_button();
}
/* Compile command (change MY_CPP_FILE):
g++ -w -Wall -std=c++11 GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp MY_CPP_FILE.cpp `fltk-config --ldflags --use-images` -o a.out
*/
