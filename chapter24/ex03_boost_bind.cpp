//
// Stroustrup - Programming Principles & Practice
//
// Chapter 24 Exercise 3
//
// Write an apply(f,a) that can take a void (T&), a T (const T&) and their 
// function object equivalents.
//
// This is indicated to be "Expert only" so I'll put this on the back-burner
// and potentially use it when I look at Boost more closely after this book.
//

#include <iostream>
#include <stdexcept>

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

