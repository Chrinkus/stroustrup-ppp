//
// Stroustrup - Programming Principles & Practice
//
// Chapter 20 Exercise 1
//
// Do all the try-this exercises from the chapter.
//
// tt1 - how would you redesign Jill's interface? Return a reference to the 
// data set.
//
// tt2 - find errors in 20.1.2 code and suggest remedies. Could potentially
// return an undefined pointer for dereferencing. Set to nullptr and check for
// nullptr in caller. Also, -1 is set as the "lowest" possible high value which
// could lead to problems with sets that have negative values.
//
// tt3 - write a function void copy(int* f1, int* e1, int* f2) that copies the
// elements from an array defined by [f1:e1) into another. Use only iterator
// operations, no subscripting

void copy(int* f1, int* e1, int* f2)
{
    for (int* p = f1; p != e1; ++p)
        *f2++ = *p;                     // sets f2 value then increments f2 ptr
}

// tt4 - find the error in 20.3.1 code, fix it, and suggest a general remedy
// for that kind of problem. The function may throw an error before deleting
// the data objects. Potentially use unique_ptr's for them.
//
// tt5 - Implement push_front() for vector and compare it to push_back().
//
// tt6 - Rewrite advance() so that it will go backward when given a negative
// argument.
//
// tt7 - Test the variations in string storage: char*, vector<char>,
// list<char>, and string.
//
// tt8 - Replicate try-this 7 for int[], vector<int>, and list<int> with the
// value { 1, 2, 3, 4, 5}.

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

