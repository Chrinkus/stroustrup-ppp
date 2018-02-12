#include "../text_lib/std_lib_facilities.h"

class Bad_area { };

int area(int length, int width)
{
    // Callee deals with errors (better)
    if (length <= 0 || width <= 0) throw Bad_area{};

    return length * width;
}

int framed_area(int x, int y)
{
    constexpr int frame_width = 2;

    return area(x - frame_width, y - frame_width);
}

int main()
try {
    // Program
    int x = -1;
    int y = 2;
    int z = 4;

    /* Caller deals with errors (not optimal)
    if (x <= 0 || y <= 0)
        error("non-positive area() arg");
    if (z <= 2)
        error("non-positive 2nd area() arg called by frame_area()");
    if (y <= 2 || z <= 2)
        error("non-positive area() arg called by framed_area()");
    */

    int area1 = area(x, y);
    int area2 = framed_area(1, z);
    int area3 = framed_area(y, z);
    double ratio = double(area1) / area3;   // convert to double to get
                                            // floating-point division
}
catch (Bad_area) {
    cout << "Oops! bad arguments to area()\n";
}
