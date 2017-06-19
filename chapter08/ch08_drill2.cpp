#include "../text_lib/std_lib_facilities.h"

void swap_v(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swap_r(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

/*
void swap_cr(const int& a, const int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
*/

int main()
{
    int x = 7;
    int y = 9;
    swap_r(x, y);
    swap_r(7, 9);
    const int cx = 7;
    const int cy = 9;
    swap_r(cx, cy);
    swap_r(7.7, 9.9);
    double dx = 7.7;
    double dy = 9.9;
    swap_r(dx, dy);
    swap_r(7.7, 9.9);

    cout << "x: " << x << '\n'
         << "y: " << y << '\n'
         << "cx: " << cx << '\n'
         << "cy: " << cy << '\n'
         << "dx: " << dx << '\n'
         << "dy: " << dy << '\n';
}
