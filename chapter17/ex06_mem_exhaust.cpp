//
// Stroustrup - Programming Principles & Practice
//
// Chapter 17 Exercise 6
//
// Write a program with an infinite loop that allocates but never deallocates.
// What happens and how much memory can you allocate before failing?
#include <iostream>
#include <stdexcept>

unsigned long long int n = 0;

int main()
try {
    while(true) {
        double* p = new double[100000];
        n += 1;
        std::cout << n << '\n';
    }
}
catch(std::exception& e) {
    std::cerr << "Error: " << e.what() << n << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unkown Error: " << n << '\n';
}

// This seems to never crash. There are slight pauses now and then but my
// computer is able to get much higher than anyone else who posted about this.
// Do Mac's dump memory to save themselves?
