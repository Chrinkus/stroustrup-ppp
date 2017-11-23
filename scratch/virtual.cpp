#include <iostream>
#include <string>

using std::cout;

struct B {
    virtual void f() const { cout << "B::f"; }
    void g() const { cout << "B::g"; }  // not virtual
};

struct D : B {
    // explicit override is useful in large, complicated class hierarchies
    void f() const override { cout << "D::f"; }  // overrides B::f
    void g() { cout << "D::g"; }
};

struct DD : D {
    void f() { cout << "DD::f"; }       // doesn't override D::f (not const)
    void g() const { cout << "DD::g"; }
};

void call(const B& b)
    // a D is a kind of B, so call() can accept a D
    // a DD is a kind of D and a D is a kind of B, so call() can accept a DD
{
    b.f();
    b.g();
}

int main()
{
    B b;
    D d;
    DD dd;

    call(b);
    call(d);
    call(dd);

    b.f();
    b.g();

    d.f();
    d.g();

    dd.f();
    dd.g();

    cout << '\n';
}
