//
// Stroustrup - Programming Principles & Practice
//
// Chapter 19 Exercise 13
//
// Write a Tracer class where its constructor prints a string and its
// destructor prints a string. Add copy a constructor and assignment.
//

#include <iostream>
#include <stdexcept>
#include <string>

class Tracer {
public:
    std::string c;
    std::string d;

    Tracer(const std::string& cc, const std::string& dd)
        : c{cc}, d{dd}
    {
        std::cout << c << '\n';
    }

    Tracer(const Tracer& t)
        : c{t.c}, d{t.d}
    {
        std::cout << "copy tracer constructed in\n";
    }

    Tracer& operator=(const Tracer& t)
    {
        c = t.c;
        d = t.d;
        std::cout << "copy tracer assigned\n";
        return *this;
    }

    Tracer(Tracer&& t)
        : c{t.c}, d{t.d}
    {
        t.c = "";
        t.d = "";
        std::cout << "move constructor fired!\n";
    }
    Tracer& operator=(Tracer&& t)
    {
        c = t.c;
        d = t.d;
        t.c = "";
        t.d = "";
        std::cout << "move assignment executed!\n";
        return *this;
    }

    ~Tracer()
    {
        std::cout << d << '\n';
    }
};

Tracer gt {"global tracer reporting in", "global tracer signing off"};

void f1()
{
    Tracer ft1 {"function tracer in", "function tracer out"};
    Tracer ft2 = ft1;
}

Tracer f2()
{
    Tracer ft3 {"another function tracer in", "another function tracer out"};
    return ft3;
}

int main()
try {
    std::cout << "Begin main()\n";

    Tracer t1 {"t1 reporting in", "t1 signing off"};

    f1();

    Tracer t2 = f2();

    Tracer t3 = t1;

    std::cout << "End main()\n";
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

