#include "./ch16_tools.h"

// Ex 1 - My_window

My_window::My_window(Point xy, int w, int h, const string& title)
    : Window(xy, w, h, title),
    next_button{Point{x_max() - 150, 0}, 70, 20, "Next",
        [](Address, Address pw) { reference_to<My_window>(pw).next(); } },
    quit_button{Point{x_max() - 70, 0}, 70, 20, "Quit",
        [](Address, Address pw) { reference_to<My_window>(pw).quit(); } }
{
    attach(next_button);
    attach(quit_button);
}

void My_window::next()
{
    // not sure what next is supposed to do..
}

void My_window::quit()
{
    hide();
}
