//
// Stroustrup - Programming Principles & Practice
//
// Chapter 17 Exercise 9
//
// Write a program to determine how the stack and free store grow: up or down.
// Result: Free store address grow upwards and stack addresses grow down!

#include <iostream>
#include <stdexcept>

using namespace std;

void stack_check()
{
    int x = 7;
    cout << "Stack: " << &x << '\n';
}

void double_stack()
{
    int y = 10;
    cout << "Stack: " << &y << '\n';
    stack_check();

    int z = 37;
    cout << "Stack: " << &z << '\n';
}

void free_check()
{
    int* arr = new int[5];

    for (int i = 0; i < 5; ++i)
        cout << "Free: " << &arr[i] << '\n';

    delete[] arr;
}

int main()
try {
    // code
    stack_check();
    free_check();
    double_stack();
}
catch(exception& e) {
    cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Unknown exception\n";
    return 2;
}

