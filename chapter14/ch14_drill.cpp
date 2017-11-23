#include <iostream>
#include <string>

using std::cout;
using std::string;

struct B1 {
    virtual void vf() { cout << "B1::vf()\n"; }
    void f() { cout << "B1::f()\n"; }
    virtual void pvf() =0;
};

struct D1 : B1 {
    void vf() override { cout << "D1::vf()\n"; }
    void f() { cout << "D1::f()\n"; }
};

struct D2 : D1 {
    void pvf() override { cout << "D2::pvf()\n"; }
};

struct B2 {
    virtual void pvf() =0;
};

struct D21 : B2 {
    string s = "stuffs";
    void pvf() override { cout << s << '\n'; }
};

struct D22 : B2 {
    int i = 37;
    void pvf() override { cout << i << '\n'; }
};

void f (B2& b)
{
    b.pvf();
}

int main()
{
    /*
    B1 b;
    b.vf();
    b.f();

    D1 d;
    d.vf();
    d.f();

    B1& r {d};
    r.vf();
    r.f();

    D2 dd;
    dd.vf();
    dd.f();
    dd.pvf();
    */

    D21 two_one;
    D22 two_two;

    f(two_one);
    f(two_two);
}
