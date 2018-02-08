//
// Stroustrup - Programming Principles & Practice
//
// Chapter 21 Try This: ugly functions
//

#include <iostream>
#include <stdexcept>

template<typename In, typename Pred>
    // requires Input_iterator<In>() && Predicate<Pred,Value_type<In>>()
In my_find_if(In first, In last, Pred pred)
{
    while (first != last && !pred(*first)) ++first;
    return first;
}

// Awful code example:
double v_val;                   // non-const global
bool larger_than_v(double x) { return x > v_val; }  // relies on non-const gbl

void f(list<double>& v, int x)
{
    v_val = 31;                 // changes non-const global
    auto p = my_find_if(v.begin(), v.end(), larger_than_v);
    if (p != v.end()) { /* we found a value > 31 */ }

    v_val = x;
    auto q = my_find_if(v.begin(), v.end(), larger_than_v);
    if (q != v.end()) { /* we found a value > x */ }

    // ...
}

// This works but there are pieces of this 'solution' scattered all over.
//
// 3 ways this can cause errors: v_val was not initialized and may be used
// before initialization, v_val may be given a value and not reassigned a value
// before next use, and v_val exists as a non-const global variable which may
// be re-assigned in scopes in between intended uses of it.
//
// 3 applications that I'd hate to find this code: the next three I work on.

// function object solution
class Larger_than {
    int v;
public:
    Larger_than(int vv) : v{vv} { }                 // store argument
    bool operator()(int x) const { return x > v; }  // compare
};

void f2(list<double>& v, int x)
{
    auto p = my_find_if(v.begin(), v.end(), Larger_than(31));
    if (p != v.end()) { /* we found a value > 31 */ }
    
    auto q = my_find_if(v.begin(), v.end(), Larger_than(x));
    if (q != v.end()) { /* we found a value > x */ }
}

// abstract function object
class F {
    S s;        // state
public:
    F(const S& ss) : s{ss} { /* establish initial state */ }
    T operator()(const S& ss) const
    {
        // do something with ss to s
        // return a value of type T (T is often void, bool or S)
    }

    const S& state() const { return s; }        // reveal state
    void reset(const S& ss) { s = ss; }         // reset state
};

int main()
try {
    // code
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

