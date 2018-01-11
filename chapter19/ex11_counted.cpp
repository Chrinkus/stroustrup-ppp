//
// Stroustrup - Programming Principles & Practice
//
// Chapter 19 Exercise 11
//
// Implement a counted_ptr<T> that holds a pointer to a T and a pointer to a
// use count int. Count should hold the number of counted pointers pointing to
// a given T.
//

#include <iostream>
#include <stdexcept>

template<typename T> class counted_ptr {
    T* obj;
    int* count;
public:
    counted_ptr(T* p) : obj{p}, count{new int{1}}
    {
        std::cout << "c_p " << *obj << " constructed\n";
    }

    counted_ptr(counted_ptr& cp)
        : obj{cp.object()}, count{cp.counter()}
    {
        ++*count;
        std::cout << "c_p " << *obj << " copy constructed\n";
    }
    counted_ptr& operator=(counted_ptr& cp)
    {
        if (&cp == this) return *this;      // self assign, don't inc count

        --*count;
        counted_ptr<T> q = *this;           // create copy to trigger destruct

        obj = cp.object();
        count = cp.counter();
        ++*count;
        std::cout << "c_p " << *obj << " copy assigned\n";
        return *this;
    }

    counted_ptr(counted_ptr&& cp)
        : obj{cp.object()}, count{cp.counter()}
    {
        cp.reset();
        std::cout << "c_p move constructor\n";
    }
    counted_ptr& operator=(counted_ptr&& cp)
    {
        obj = cp.object();
        count = cp.counter();
        cp.reset();
        std::cout << "c_p move assignment\n";
    }

    ~counted_ptr()
    {
        if (count != nullptr) {
            --*count;
            std::cout << "c_p " << *obj << " destructor: " << *count
                      << " ptrs left..\n";
            if (*count == 0) {
                delete obj;
                delete count;
                std::cout << "c_p deleted!\n";
            }
        }
    }

    T* object() { return obj; }
    int* counter() { return count; }
    void reset() { obj = nullptr; count = nullptr; }

    T& operator*() { return *obj; }
    T* operator->() { return obj; }
};

counted_ptr<double> f1(double n)
{
    counted_ptr<double> cpd {new double{n}};
    return cpd;
}

int main()
try {
    counted_ptr<double> p1 {new double{63.2}};
    std::cout << "Pointer contents: " << *p1 << '\n';

    counted_ptr<double> p2 = p1;
    std::cout << "Pointer contents: " << *p2 << '\n';

    counted_ptr<double> p3 = p2;
    std::cout << "Pointer contents: " << *p3 << '\n';

    counted_ptr<double> p4 = f1(3.14159);
    std::cout << "Pointer contents: " << *p4 << '\n';

    p4 = p3;

    std::cout << "End of main\n";
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

