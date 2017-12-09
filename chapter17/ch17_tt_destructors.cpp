#include <iostream>
#include <stdexcept>

using std::cout;

class Base {
    double* elem;
public:
    int nums;
    Base(int n)
        : nums{n}, elem{new double[n]}
    {
        cout << "Base class constructed: " << n << '\n';
        for (int i = 0; i < n; ++i) elem[i] = 0;
    }

    virtual ~Base()
    {
        cout << "Base class destructed: " << nums << '\n';
        delete[] elem;
    }

    void virtual proclaim() const
    {
        cout << "I am base class#" << nums << '\n';
    }
};

Base* func(int a, int b)
{
    Base b1 {a};
    Base* p = new Base{b};

    cout << "leaving func()\n";

    return p;
}

class Derived : public Base {
    int* mo_nums;
public:
    Derived(int n)
        : Base{n}, mo_nums{new int[n]}
    {
        cout << "Derived class constructed: " << n << '\n';
    }

    void proclaim() const
    {
        cout << "I am derived class #" << nums << '\n';
    }

    /*
    ~Derived()
    {
        cout << "Derived class destructed: " << nums << '\n';
        delete[] mo_nums;
    }
    */
};

int main()
try {
    // Destructor fun!
    Base b2 {2};
    Derived d1 {63};

    Base* p1 = func(10, 13);
    Base* p2 = func(27, 37);

    delete p1;
    delete p2;

    cout << "leaving main()\n";
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}
