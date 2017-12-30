//
// Stroustrup - Programming Principles & Practice
//
// Scratch file: arrays
//

#include <iostream>
#include <stdexcept>
#include <array>

/*
void f1(int a[])
    // compiler error: fails since a[] is passed as a pointer to a there is no
    // range-for defined for just a pointer
{
    std::cout << "Function range-for array loop\n";
    for (auto& n : a)
        std::cout << n << ' ';
    std::cout << '\n';
}
*/

void f2(int a[], int n)
{
    std::cout << "Function for loop w/size\n";
    for (int i = 0; i < n; ++i)
        std::cout << a[i] << ' ';
    std::cout << '\n';
}

void f3(std::array<int, 10> ai)
{
    std::cout << "Function range-for std::array loop\n";
    for (auto& a : ai)
        std::cout << a << ' ';
    std::cout << '\n';
}

struct Node {
    Node(int value, int level)
        : val{value}, lvl{level} { }

    int val;
    int lvl;
};

int main()
try {
    // array size awareness test
    int ai[] {1, 2, 3, 4, 5, 6, 7};

    std::cout << "Local range-for array loop\n";
    for (auto& a : ai)          // ai doesn't "know" its size, or does it?
        std::cout << a << ' ';
    std::cout << '\n';

    //f1(ai);
    f2(ai, 7);

    // char array tests
    int n1 = 10;                // doesn't have to be costexpr(?)

    char ac[n1];
    char ch = 'a';
    for (auto& a : ac)
        a = ch++;

    std::cout << "Char array fill test\n";
    for (auto& a : ac)
        std::cout << a << ' ';
    std::cout << '\n';

    // <array> tests
    std::array<int, 10> ai2;
    int n = 1;
    for (auto& a : ai2)
        a = n++;

    std::cout << "std::array fill test\n";
    for (auto& a : ai2)
        std::cout << a << ' ';
    std::cout << '\n';

    f3(ai2);

    // pointer array test
    Node* an[3];
    Node* pn1 = new Node{10, 2};
    Node* pn2 = new Node{20, 3};
    Node* pn3 = new Node{30, 1};
    an[0] = pn1;
    an[1] = pn2;
    an[2] = pn3;

    std::cout << "Array of pointers test\n";
    for (auto& a : an)
        std::cout << a->val << ' ' << a->lvl << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

