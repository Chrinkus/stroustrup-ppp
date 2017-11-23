#include "../GUI/Graph.h"
#include <string>
#include <cmath>

using namespace Graph_lib;

constexpr double PI = 3.14159265;

// Ex 1 - Arc

struct Arc : Shape {
    Arc(Point p, int rr, double start, double end);

    void draw_lines() const;

    int radius() const { return r; }

private:
    int r;
    double start;
    double end;
};

// Ex 2 - Box

struct Box : Shape {
    Box(Point p, int w, int h, int r);

    void draw_lines() const;

private:
    Vector_ref<Arc> corners;
    Lines sides;
};

// Ex 3 - Arrow

struct Arrow : Shape {
    Arrow(Point p1, Point p2);

    void draw_lines() const;
    
    void set_size(int s) { size = s; }

private:
    int size = 12;
    int iso = 20;
};

// Ex 4 - Connection Points: Rectangle

Point n (Rectangle& r);
Point s (Rectangle& r);
Point e (Rectangle& r);
Point w (Rectangle& r);
Point nw (Rectangle& r);
Point ne (Rectangle& r);
Point sw (Rectangle& r);
Point se (Rectangle& r);
Point center (Rectangle& r);

// Ex 5 - Connection Points: Circle & Ellipse

Point n (Circle& c);
Point s (Circle& c);
Point e (Circle& c);
Point w (Circle& c);
Point ne (Circle& c);
Point se (Circle& c);
Point sw (Circle& c);
Point nw (Circle& c);
Point center (Circle& c);

Point n (Ellipse& e);
Point s (Ellipse& e);
Point e (Ellipse& e);
Point w (Ellipse& e);
Point ne (Ellipse& e);
Point se (Ellipse& e);
Point sw (Ellipse& e);
Point nw (Ellipse& e);
Point center (Ellipse& e);

// Ex 6 - Text_box

struct Text_box : Rectangle {
    Text_box(Point pp, int ww, int hh, string ss);

    void draw_lines() const;

private:
    Text label;
};

// Ex 8 - Regular_hexagon

struct Reg_hex : Closed_polyline {
    Reg_hex(Point p, int r);

    int radius() const { return r; }
    Point center() const { return c; }

private:
    int r;          // Radius to corners
    Point c;        // Center of hex
};

// Ex 10 - Regular_polygon

struct Reg_poly : Closed_polyline {
    Reg_poly(Point p, int sides, int distance);

    Point center() const { return c; }
    int number_of_sides() const { return s; }
    int distance_to_corner() const { return d; }

private:
    Point c;
    int s;
    int d;
};

// Ex 14 - Right_triangle

struct Right_triangle : Closed_polyline {
    Right_triangle(Point p, int a, int b);      // initialize w/o rotation
    Right_triangle(Point p, int a, int b, double o);

private:
    int a;          // side a
    int b;          // side b
    double o = 0;   // orientation
    double c = 90;  // compliment of orientation
};

// Ex 19 - Star

struct Star : Closed_polyline {
    Star(Point c, int r, int p, int q);

private:
    Point c;    // centre of star
    int r;      // radius of bounding circle
    int p;      // number of points
    int q;      // skip to next point
};
