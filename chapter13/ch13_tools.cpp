#include "./ch13_tools.h"
#include <iostream>

using namespace Graph_lib;

// Ex 1 - Arc

Arc::Arc(Point p, int rr, double s, double e)
    : r{rr}, start{s}, end{e}
{
    add(Point{p.x-r, p.y-r});
}

void Arc::draw_lines() const
{
    if (color().visibility())
        fl_arc(point(0).x, point(0).y, r+r, r+r, start, end);
}

// Ex 2 - Box

Box::Box(Point p, int w, int h, int r)
{
    sides.add(Point{p.x + r, p.y}, Point{p.x+w-r, p.y});    // top
    sides.add(Point{p.x+w, p.y+r}, Point{p.x+w, p.y+h-r});  // right
    sides.add(Point{p.x+w-r, p.y+h}, Point{p.x+r, p.y+h});  // bottom
    sides.add(Point{p.x, p.y+h-r}, Point{p.x, p.y+r});      // left

    corners.push_back(new Arc{Point{p.x+w-r, p.y+r}, r, 0, 90});        // tr
    corners.push_back(new Arc{Point{p.x+r, p.y+r}, r, 90, 180});        // tl
    corners.push_back(new Arc{Point{p.x+r, p.y+h-r}, r, 180, 270});     // bl
    corners.push_back(new Arc{Point{p.x+w-r, p.y+h-r}, r, 270, 360});   // br
}

void Box::draw_lines() const
{
    for (int i = 0; i < corners.size(); ++i)
        corners[i].draw_lines();

    sides.draw_lines();
}

// Ex 3 - Arrow

Arrow::Arrow(Point tail, Point tip)
{
    add(tail);
    add(tip);
}

void Arrow::draw_lines() const
{
    constexpr double PI = 3.14159265;

    int diff_x = point(1).x - point(0).x;
    int diff_y = point(1).y - point(0).y;
    double angle = atan2(diff_y, diff_x)*180/PI;

    double x1 = point(1).x - cos((angle-iso)*PI/180) * size;
    double y1 = point(1).y - sin((angle-iso)*PI/180) * size;

    double x2 = point(1).x - cos((angle+iso)*PI/180) * size;
    double y2 = point(1).y - sin((angle+iso)*PI/180) * size;

    Polygon head;
    head.add(point(1));
    head.add(Point{int(x1), int(y1)});
    head.add(Point{int(x2), int(y2)});
    head.set_fill_color(color());

    head.draw_lines();          // draw arrow head
    Shape::draw_lines();        // draw line
}

// Ex 4 Connection Points: Rectangle

Point n (Rectangle& r)
{
    int x = r.point(0).x + r.width() / 2;
    int y = r.point(0).y;

    return Point{x, y};
}

Point s (Rectangle& r)
{
    int x = r.point(0).x + r.width() / 2;
    int y = r.point(0).y + r.height();
    return Point{x, y};
}

Point e (Rectangle& r)
{
    int x = r.point(0).x + r.width();
    int y = r.point(0).y + r.height() / 2;
    return Point{x, y};
}

Point w (Rectangle& r)
{
    int x = r.point(0).x;
    int y = r.point(0).y + r.height() / 2;
    return Point{x, y};
}

Point nw (Rectangle& r)
{
    int x = r.point(0).x;
    int y = r.point(0).y;
    return Point{x, y};
}

Point ne (Rectangle& r)
{
    int x = r.point(0).x + r.width();
    int y = r.point(0).y;
    return Point{x, y};
}

Point sw (Rectangle& r)
{
    int x = r.point(0).x;
    int y = r.point(0).y + r.height();
    return Point{x, y};
}

Point se (Rectangle& r)
{
    int x = r.point(0).x + r.width();
    int y = r.point(0).y + r.height();
    return Point{x, y};
}

Point center (Rectangle& r)
{
    int x = r.point(0).x + r.width() / 2;
    int y = r.point(0).y + r.height() / 2;
    return Point{x, y};
}

// Ex 5 - Connection Points: Circle 

Point n (Circle& c)
{
    int x = c.center().x + cos(90*PI/180) * c.radius();
    int y = c.center().y - sin(90*PI/180) * c.radius();
    return Point{x, y};
}

Point s (Circle& c)
{
    int x = c.center().x + cos(270*PI/180) * c.radius();
    int y = c.center().y - sin(270*PI/180) * c.radius();
    return Point{x, y};
}

Point e (Circle& c)
{
    int x = c.center().x + cos(0*PI/180) * c.radius();
    int y = c.center().y - sin(0*PI/180) * c.radius();
    return Point{x, y};
}

Point w (Circle& c)
{
    int x = c.center().x + cos(180*PI/180) * c.radius();
    int y = c.center().y - sin(180*PI/180) * c.radius();
    return Point{x, y};
}

Point nw (Circle& c)
{
    int x = c.center().x + cos(135*PI/180) * c.radius();
    int y = c.center().y - sin(135*PI/180) * c.radius();
    return Point{x, y};
}

Point ne (Circle& c)
{
    int x = c.center().x + cos(45*PI/180) * c.radius();
    int y = c.center().y - sin(45*PI/180) * c.radius();
    return Point{x, y};
}

Point se (Circle& c)
{
    int x = c.center().x + cos(315*PI/180) * c.radius();
    int y = c.center().y - sin(315*PI/180) * c.radius();
    return Point{x, y};
}

Point sw (Circle& c)
{
    int x = c.center().x + cos(225*PI/180) * c.radius();
    int y = c.center().y - sin(225*PI/180) * c.radius();
    return Point{x, y};
}

Point center (Circle& c)
{
    return c.center();
}

// Ex 5 - Connection Points: Circle 

Point n (Ellipse& e)
{
    int x = e.center().x;
    int y = e.center().y - e.minor();
    return Point{x, y};
}

Point s (Ellipse& e)
{
    int x = e.center().x;
    int y = e.center().y + e.minor();
    return Point{x, y};
}

Point e (Ellipse& e)
{
    int x = e.center().x + e.major();
    int y = e.center().y;
    return Point{x, y};
}

Point w (Ellipse& e)
{
    int x = e.center().x - e.major();
    int y = e.center().y;
    return Point{x, y};
}

Point nw (Ellipse& e)
{
    int slr = pow(e.minor(), 2) / (e.focus1().x - e.center().x);
    std::cout << slr << '\n';
    int x = e.focus2().x;
    int y = e.focus2().y - slr;
    return Point{x, y};
}

Point ne (Ellipse& e)
{
    int slr = pow(e.minor(), 2) / (e.focus1().x - e.center().x);
    int x = e.focus1().x;
    int y = e.focus1().y - slr;
    return Point{x, y};
}

Point se (Ellipse& e)
{
    int slr = pow(e.minor(), 2) / (e.focus1().x - e.center().x);
    int x = e.focus1().x;
    int y = e.focus1().y + slr;
    return Point{x, y};
}

Point sw (Ellipse& e)
{
    int slr = pow(e.minor(), 2) / (e.focus1().x - e.center().x);
    int x = e.focus2().x;
    int y = e.focus2().y + slr;
    return Point{x, y};
}

// Ex 6 - Text_box

Text_box::Text_box(Point p, int ww, int hh, string ss)
    : Rectangle(p, ww, hh), label (Point{p.x+5,p.y+16}, ss)
{
    add(p);
}

void Text_box::draw_lines() const
{
    Rectangle::draw_lines();
    label.draw_lines();
}

// Ex 8 - Regular_hexagon

Reg_hex::Reg_hex(Point p, int rr)
    : r{rr}, c{p}
{
    for (int i = 0; i < 360; i += 60) {
        double x = c.x + cos(i*PI/180) * r;
        double y = c.y + sin(i*PI/180) * r;
        add(Point{int(x), int(y)});
    }
}

// Ex 10 - Regular_polygon

Reg_poly::Reg_poly(Point p, int ss, int dd)
    : c{p}, s{ss}, d{dd}
{
    if (s < 3) error("Regular polygon must have at least 3 sides");
    double angle = 360 / s;

    for (double i = 0; i < 360; i += angle) {
        // make poly
        double x = c.x + cos(i*PI/180) * d;
        double y = c.y + sin(i*PI/180) * d;
        add(Point{int(x), int(y)});
    }
}

// Ex 14 - Right_triangle

Right_triangle::Right_triangle(Point p, int aa, int bb)
    : a{aa}, b{bb}
{
    add(p);
    add(Point{p.x + a, p.y});
    add(Point{p.x, p.y - b});
}

Right_triangle::Right_triangle(Point p, int aa, int bb, double oo)
    : a{aa}, b{bb}, o{oo}, c{90 - oo}
{
    add(p);

    int x = p.x + cos(o*PI/180) * a;
    int y = p.y - sin(o*PI/180) * a;
    add(Point{x, y});

    x = p.x - cos(c*PI/180) * b;
    y = p.y - sin(c*PI/180) * b;
    add(Point{x, y});
}

// Ex 19 - Star

Star::Star(Point cc, int rr, int pp, int qq)
    : c{cc}, r{rr}, p{pp}, q{qq}
{
    double angle = 0;
    double next = 360 / pp;

    for (int i = 0; i < pp; ++i) {
        int x = c.x + cos(angle*PI/180) * rr;
        int y = c.y + sin(angle*PI/180) * rr;

        add(Point{x, y});

        angle += qq * next;
    }
}
