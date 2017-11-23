#include "./ch14_tools.h"
#include <iostream>
#include <cmath>

// Ex 1 - Smiley, Frowny

Smiley::Smiley (Point p, int r) :
    Circle  {p, r},
    left    {Point{p.x-r/3, p.y-r/3}, r / 4},
    right   {Point{p.x+r/3, p.y-r/3}, r / 4},
    mouth   {p, r*2/3, 200, 340} { }

void Smiley::draw_lines () const
{
    Circle::draw_lines();
    left.draw_lines();
    right.draw_lines();
    mouth.draw_lines();
}

Frowny::Frowny (Point p, int r) :
    Circle  {p, r},
    left    {Point{p.x-r/3, p.y-r/3}, r / 4},
    right   {Point{p.x+r/3, p.y-r/3}, r / 4},
    mouth   {Point{p.x, p.y+r*3/4}, r*2/3, 22, 157} { }

void Frowny::draw_lines () const
{
    Circle::draw_lines();
    left.draw_lines();
    right.draw_lines();
    mouth.draw_lines();
}

Smiley_hat::Smiley_hat (Point p, int r) :
    Smiley  {p, r},
    hat     {Point{p.x-r*3/4, p.y-r*5/4}, r*3/2, r/2}
{
    hat.set_fill_color(Color::black);
}

void Smiley_hat::draw_lines () const
{
    Smiley::draw_lines();
    hat.draw_lines();
}

Frowny_hat::Frowny_hat (Point p, int r)
    : Frowny  {p, r}
{
    hat.add(Point{p.x-r*3/4, p.y-r*3/4});
    hat.add(Point{p.x+r*3/4, p.y-r*3/4});
    hat.add(Point{p.x, p.y-r*3/2});

    hat.set_fill_color(Color::yellow);
}

void Frowny_hat::draw_lines () const
{
    Frowny::draw_lines();
    hat.draw_lines();
}

// Ex 5 - Striped_rectangle

Striped_rectangle::Striped_rectangle (Point p, int ww, int hh, int ss)
    : Rectangle{p, ww, hh}, sw{ss}
{
    for (int i = p.y + ss; i < p.y + hh; i += ss)
        stripes.add(Point{p.x, i}, Point{p.x + ww - 1, i});
}

void Striped_rectangle::set_stripe_color(Color col)
{
    stripes.set_color(col);
}

void Striped_rectangle::draw_lines () const
{
    stripes.draw();
    Rectangle::draw_lines();
}

// Ex 6 - Striped_circle

Striped_circle::Striped_circle(Point p, int r, int ss)
    : Circle{p, r}, sw{ss}
{
    for (int i = p.y - r; i < p.y + r; i += ss) {
        int x_mod = sqrt(pow(r, 2) - pow(p.y - i, 2));

        stripes.add(Point{p.x - x_mod, i}, Point{p.x + x_mod, i});
    }
}

void Striped_circle::draw_lines() const
{
    stripes.draw_lines();
    Circle::draw_lines();
}

// Ex 8 - Octagon

Octagon::Octagon(Point p, int rr)
    : c{p}, r{rr}
{
    for (int i = 0; i < 360; i += 45) {        // <= creates 9 points to 
        int x = p.x + cos(i*PI/180) * rr;       // close the shape (bad?)
        int y = p.y + sin(i*PI/180) * rr;

        add(Point{x, y});
    }
}

// Ex 9 - Group

void Group::move(int dx, int dy)
{
    for (int i = 0; i < vr.size(); ++i)
        vr[i].move(dx, dy);
}

void Group::set_color(Color col)
{
    for (int i = 0; i < vr.size(); ++i)
        vr[i].set_color(col);
}

void Group::set_fill_color(Color col)
{
    for (int i = 0; i < vr.size(); ++i)
        vr[i].set_fill_color(col);
}

void Group::set_style(Line_style sty)
{
    for (int i = 0; i < vr.size(); ++i)
        vr[i].set_style(sty);
}

// Ex 10 - Pseudo_window

Pseudo_window::Pseudo_window(Point p, string url) :
    viewport{p, 400, 250, 5},
    button{Point{p.x + 360, p.y + 30}, 40, 20, "Next"},
    content{Point{p.x + 40, p.y + 40}, url},
    c1 {Point{p.x + 15, p.y + 15}, 10},
    c2 {Point{p.x + 45, p.y + 15}, 10},
    c3 {Point{p.x + 75, p.y + 15}, 10}
{
    add(Point{p.x, p.y + 30});
    add(Point{p.x + 400, p.y + 30});

    c1.set_color(Color::red);       // these don't work..
    c2.set_color(Color::yellow);
    c3.set_color(Color::green);
}

void Pseudo_window::draw_lines() const
{
    viewport.draw_lines();
    Shape::draw_lines();
    button.draw_lines();
    content.draw_lines();

    c1.draw_lines();
    c2.draw_lines();
    c3.draw_lines();
}

/*
// Ex 11 - Binary_tree

Binary_tree::Binary_tree(Point p, int levels)
    : l{levels}
{
    int x_max = pow(2, levels - 1) * 2.5 * r;

    int x_min = p.x - x_max / 2;
    int y_min = p.y;

    for (int i = 0; i < pow(2, levels) - 1; ++i) {
        int level = log2(i + 1);

        int x = x_min + x_max / 
        int y = p.y + log2(i + 1) * 4 * r;
        nodes.push_back(Point{x, y});
    }
}
*/
