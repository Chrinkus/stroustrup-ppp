#include "../text_lib/std_lib_facilities.h"

int area(int length, int width)
// calculate area of a rectangle
// pre-conditions: length and width are positive
// post-condition: returns a positive value that is area
{
    if (length <= 0 || width <= 0) error("area() pre-condition");
    int a = length * width;
    if (a <= 0) error("area() post-condition");
    return a;
}

int main()
try {
    // This is an example of the area function with pre & post conditionals

    int x;
    int y;
    for (; cin >> x >> y; )
        cout << "Area: " << area(x, y) << '\n';

}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    return 2;
}
