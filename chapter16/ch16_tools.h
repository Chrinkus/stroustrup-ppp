#include "../GUI/GUI.h"

using namespace Graph_lib;

// Ex 1 - My_window

struct My_window : Graph_lib::Window {
    My_window(Point xy, int w, int y, const string& title);

private:
    Button next_button;
    Button quit_button;

    void next();
    void quit();
};
