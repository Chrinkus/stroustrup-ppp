#include "../GUI/Graph.h"
#include "../chapter13/ch13_tools.h"

using namespace Graph_lib;

// Ex 1 - Smiley, Frowny

struct Smiley : Circle {
    Smiley(Point p, int r);

    void draw_lines () const;

private:
    int r;          // radius
    Circle left;    // left eye
    Circle right;   // right eye
    Arc mouth;      // mouth
};

struct Frowny : Circle {
    Frowny(Point p, int r);

    void draw_lines () const;

private:
    int r;          // radius
    Circle left;    // left eye
    Circle right;   // right eye
    Arc mouth;      // mouth
};

struct Smiley_hat : Smiley {
    Smiley_hat(Point p, int r);

    void draw_lines () const;

private:
    Rectangle hat;
};

struct Frowny_hat : Frowny {
    Frowny_hat(Point p, int r);

    void draw_lines () const;

private:
    Polygon hat;
};

// Ex 4 - Immobile_circle

struct Immobile_circle : Circle {
    Immobile_circle(Point p, int r)
        : Circle{p, r} { }

    void move(int dx, int dy) { }
};

// Ex 5 - Striped_rectangle

struct Striped_rectangle : Rectangle {
    Striped_rectangle(Point p, int w, int h, int s);

    void draw_lines () const;
    void set_stripe_color(Color col);

private:
    Lines stripes;      // stripe lines
    int sw;             // stripe width
};

// Ex 6 - Striped_circle

struct Striped_circle : Circle {
    Striped_circle(Point p, int r, int s);

    void draw_lines() const;

private:
    Lines stripes;      // stripe lines
    int sw;             // stripe width
};

// Ex 8 - Octagon

struct Octagon : Closed_polyline { 
    Octagon(Point p, int rr);

private:
    Point c;    // centre
    int r;      // radius
};

// Ex 9 - Group

struct Group {
    Group() { }

    void add(Shape& s) { vr.push_back(s); }

    void move(int dx, int dy);
    void set_color(Color col);
    void set_fill_color(Color col);
    void set_style(Line_style sty);
private:
    Vector_ref<Shape> vr;
};

// Ex 10 - Pseudo_window

struct Pseudo_window : Shape {
    Pseudo_window(Point p, string url);
    void draw_lines() const;

private:
    Box         viewport;
    Text_box    button;
    Image       content;
    Circle      c1;
    Circle      c2;
    Circle      c3;
};

/*
// Ex 11 - Binary_tree

struct Binary_tree : Shape {
    Binary_tree(Point p, int levels);

    int number_of_nodes() const { return nodes.size(); }

private:
    vector<Point> nodes;
    int r = 25;
    int l;
};
*/
