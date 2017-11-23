#include "./ch15_tools.h"
#include <iostream>

using namespace Graph_lib;

// Ex 1 - Fct >> Func

Func::Func(Fct ff, double r_min, double r_max, Point origin,
        int count = 100, double xscale = 25, double yscale = 25) :
    Function{ff, r_min, r_max, origin, count, xscale, yscale},
    f{ff},
    r1{r_min},
    r2{r_max},
    o{origin},
    c{count}, 
    xs{xscale}, 
    ys{yscale}
{ }

void Func::reset()
{
    clear_points();

    double dist = (r2-r1)/c;
    double r = r1;
    for (int i = 0; i<c; ++i) {
        add(Point(o.x+int(r*xs),o.y-int(f(r)*ys)));
        r += dist;
    }
}

void Func::set_function(Fct ff)
{
    f = ff;
    reset();
}

void Func::set_range(double rr1, double rr2)
{
    r1 = rr1;
    r2 = rr2;
    reset();
}

void Func::move_origin(int dx, int dy)
{
    o.x += dx;
    o.y += dy;
    reset();
}

// Ex 7 - Graph Labels

Graph_labels::Graph_labels(const string& title, const string& x_label,
        const string& y_label) :
    t{Point{0, 0}, title},
    x{Point{0, 0}, x_label},
    y{Point{0, 0}, y_label}
{
    t.set_font_size(20);
    t.set_color(Color::black);
    x.set_font_size(16);
    x.set_color(Color::black);
    y.set_font_size(16);
    y.set_color(Color::black);
}

void Graph_labels::draw_lines() const
{
    t.draw();
    x.draw();
    y.draw();
}

// Ex 6 - Bar_graph

L_axis::L_axis(int xx, int yy) :
    xmax{xx}, ymax{yy},
    xlength{xx - xoffset - xspace},
    ylength{yy - yoffset - yspace},
    o{xoffset, yy - yoffset},
    xa{Axis::x, o, xlength},
    ya{Axis::y, o, ylength},
    labs{"Big Title!!"}
{
    // Move labels
    labs.t.move(o.x, yspace - 10);
    labs.x.move(o.x, o.y + 20);
    labs.y.move(o.x / 4, o.y - height() / 2);
}

void L_axis::draw_lines() const
{
    xa.draw();
    ya.draw();
    labs.draw_lines();
}

void L_axis::set_labels(const string& tt, const string& xx, const string& yy)
{
    labs.t.set_label(tt);
    labs.x.set_label(xx);
    labs.y.set_label(yy);
}

Graph_data::Graph_data(vector<double>& data)
{
    for (auto d : data) {
        if (min == 0 && max == 0) {
            min = d;
            max = d;
        }
        if (d < min)
            min = d;
        if (d > max)
            max = d;
    }

    ceil = max * 1.05;
    // It would be nice to come up with an algorithm that lands my ceiling on
    // a round number
    // Also, it would be nice to find a way to define an adequate space for
    // adding background lines..
}

Bar_graph::Bar_graph(vector<double>& data, int xx, int yy) :
    lax{xx, yy},
    gd{data}
{
    const Point o = lax.origin();
    const int w = lax.width() / data.size();
    const int bar = w * 0.8;
    const int gap = w * 0.2;

    int x = o.x;
    for (auto d : data) {
        int h = d / gd.ceiling() * lax.height();
        int y = o.y - h;
        bars.push_back(new Rectangle{Point{x + gap, y}, bar, h});
        bars[bars.size()-1].set_color(Color::invisible);
        bars[bars.size()-1].set_fill_color(Color::blue);
        x += w;
    }
}

void Bar_graph::draw_lines() const
{
    // Bars
    for (int i = 0; i < bars.size(); ++i)
        bars[i].draw_lines();

    // Axis
    lax.draw_lines();
}

void Bar_graph::set_labels(const string& t, const string& x, const string& y)
{
    lax.set_labels(t, x, y);
}
