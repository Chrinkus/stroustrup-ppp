//
// Stroustrup - Programming Principles & Practice
//
// Chapter 19 Exercise 10
//
// Implement a simple unique_ptr w/constructor, destructor, ->, *, and
// release()
//

#include <iostream>
#include <stdexcept>

template<typename T> class unique_ptr {
    T* p;
public:
    explicit unique_ptr(T* ptr) : p{ptr}
    {
        std::cout << "constructed u_p\n";
    }

    ~unique_ptr()
    {
        std::cout << "destructed u_p\n";
        delete p;
    }

    T* release()
    {
        T* q = p;
        p = nullptr;
        return q;
    }

    T& operator*() { return *p; }
};

unique_ptr<int> f1(int n)
{
    unique_ptr<int> p {new int{n}};
    return p;
}

double* f2(double n)
{
    unique_ptr<double> p {new double{n}};
    return p.release();
}

int main()
try {
    std::cout << "Start of main\n";

    unique_ptr<int> p1 = f1(11);

    std::cout << "Pointer contents: " << *p1 << '\n';

    //throw std::runtime_error("Was u_p destructed?");

    double* p2 = f2(2.71828);

    std::cout << "Pointer contents: " << *p2 << '\n';
    delete p2;
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

