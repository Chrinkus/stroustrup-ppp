#include "../GUI/Graph.h"

using namespace Graph_lib;

// Ex 1 - Fct >> Func

struct Func : Function {
    Func(Fct f, double r1, double r2, Point o, int c, double xs, double ys);

    void reset();
    void set_function(Fct f);
    void set_range(double r1, double r2);
    void move_origin(int dx, int dy);

private:
    Fct* f;
    double r1;
    double r2;
    Point o;
    int c;
    double xs;
    double ys;
};

// Ex 7 - Graph labels

struct Graph_labels : Shape {
    Graph_labels(const string& title = "Default",
            const string& x_label = "Default",
            const string& y_label = "Default");

    void draw_lines() const;

    Text t;
    Text x;
    Text y;
};

// Ex 6 - Bar_graph

class L_axis : public Shape {
    int xmax;
    int ymax;
    int xlength;
    int ylength;

    Point o;
    Axis xa;
    Axis ya;
    Graph_labels labs;

    static constexpr int xoffset = 100;
    static constexpr int yoffset = 60;
    static constexpr int xspace = 40;
    static constexpr int yspace = 40;

public:
    L_axis(int x_width, int y_height);

    void draw_lines() const;
    void set_labels(const string& t, const string& x, const string& y);

    Point origin() const { return o; }
    int width() const { return xlength; }
    int height() const { return ylength; }
};

struct Graph_data {
    Graph_data(vector<double>& d);

    double ceiling() const { return ceil; }

private:
    double min;
    double max;
    double ceil;
};

struct Bar_graph : Shape {
    Bar_graph(vector<double>& data, int xm, int ym);

    void draw_lines() const;
    void set_labels(const string& t, const string& x, const string& y);

private:
    Vector_ref<Rectangle> bars;
    L_axis lax;
    Graph_data gd;
};
