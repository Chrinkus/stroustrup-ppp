//
// Stroustrup - Programming Principles & Practice
//
// Chapter 23 Exercise 15
//
// Describe a pattern that cannot be expressed as a regular expression.
// - This is weird. I was able to reach the catch clause in the pattern
// generating exercises with extra '\'s but is that a pattern? No, it was 
// always a mis-typed character.
//
// Exercise 16
//
// Prove that the pattern found in the previous exercise really isn't a regular
// expression.
// - the escape character alone isn't really a regex as the rules state that a
// single backslash needs to be escaped itself if we want to try to match it or
// it shall preceed a special character to denote it's special-ness.
//
// Not sure if the above answers are what Bjarne was going for but there you
// go.
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

