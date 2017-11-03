#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

Point n (Rectangle r)
{
    int x = r.point(0).x + r.width() / 2;
    int y = r.point(0).y;

    return Point{x, y};
}

Point s (Rectangle r)
{
    int x = r.point(0).x + r.width() / 2;
    int y = r.point(0).y + r.height();
    return Point{x, y};
}

Point e (Rectangle r)
{
    int x = r.point(0).x + r.width();
    int y = r.point(0).y + r.height() / 2;
    return Point{x, y};
}

Point w (Rectangle r)
{
    int x = r.point(0).x;
    int y = r.point(0).y + r.height() / 2;
    return Point{x, y};
}

Point nw (Rectangle r)
{
    int x = r.point(0).x;
    int y = r.point(0).y;
    return Point{x, y};
}

Point ne (Rectangle r)
{
    int x = r.point(0).x + r.width();
    int y = r.point(0).y;
    return Point{x, y};
}

Point sw (Rectangle r)
{
    int x = r.point(0).x;
    int y = r.point(0).y + r.height();
    return Point{x, y};
}

Point se (Rectangle r)
{
    int x = r.point(0).x + r.width();
    int y = r.point(0).y + r.height();
    return Point{x, y};
}

Point center (Rectangle r)
{
    int x = r.point(0).x + r.width() / 2;
    int y = r.point(0).y + r.height() / 2;
    return Point{x, y};
}

Point n (Circle c)
{
    int x = c.point(0).x + c.radius();
    int y = c.point(0).y;
    return Point{x, y};
}

Point s (Circle c)
{
    int x = c.point(0).x + c.radius();
    int y = c.point(0).y + c.radius() * 2;
    return Point{x, y};
}

Point e (Circle c)
{
    int x = c.point(0).x + c.radius() * 2;
    int y = c.point(0).y + c.radius();
    return Point{x, y};
}

Point w (Circle c)
{
    int x = c.point(0).x;
    int y = c.point(0).y + c.radius();
    return Point{x, y};
}

int main()
try {
    // program
}
catch(exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "error\n";
    return 2;
}
