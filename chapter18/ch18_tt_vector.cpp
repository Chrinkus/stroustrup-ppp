//
// Stroustrup - Programming Principles & Practice
//
// Chapter 18 Try This - vector thus far
//

#include <iostream>
#include <stdexcept>
#include <initializer_list>    
#include <algorithm>            

class vector {
    int sz;             // the size
    double* elem;       // a pointer to the elements
public:
    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    // 17.4 Free store & pointers (needed for elem)
    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    explicit vector(int s)                  // constructor
        : sz{s}, elem{new double[s]}
    {
        for (int i = 0; i < s; ++i) elem[i] = 0;
    }

    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    // 18.3.1 Copy constructors
    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    vector(const vector& arg)
        : sz{arg.sz}, elem{new double[arg.sz]}
    {
        std::copy(arg.elem, arg.elem.size, elem);
    }

    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    // 18.3.2 Copy assignments
    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    vector& operator=(const vector& a)
    {
        double* p = new double[a.sz];       // allocate new space
        std::copy(a.elem, a.elem.sz, p);    // copy elements
        delete[] elem;                      // deallocate old space
        elem = p;                           // reset elem
        sz = a.sz;
        return *this;                       // return self reference
    }

    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    // 18.3.4 Moving
    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    vector(vector&& a)                      // move constructor
        : sz{a.sz}, elem{a.elem}             // copy a's elem and sz
    {
        a.sz = 0;                           // make a the empty vector
        a.elem = nullptr;
    }

    vector& operator=(vector&& a)           // move assignment
    {                                       // move a to this vector
        delete[] elem;                      // deallocate old space
        elem = a.elem;                      // copy a's elem and sz
        sz = a.sz;
        a.elem = nullptr;                   // make a the empty vector
        a.sz = 0;
        return *this;                       // return a self-reference
    }

    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    // 18.2 Initializer list construction
    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    vector(std::initializer_list<double> lst)   // initializer-list constructor
        : sz{lst.size()},
        elem{new double[sz]}                    // uninitialized memory
    {
        // copy from i_list begin to end into elem
        std::copy(lst.begin(), lst.end(), elem);
    }

    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    // 17.5 Destructors
    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    ~vector() { delete[] elem; }            // destructor

    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    // 18.5 Access
    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    double operator[](int n) { return elem[n]; }        // return element

    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    int size() const { return sz; }         // the current size

    double get(int n) const { return elem[n]; }         // access: read
    void set(int n, double v) { elem[n] = v; }          // access: write
};

int main()
try {
    // code
    vector v(10);
    double x = v[2];
    v[3] = x;
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

