#include <iostream>

int main()
{
    double* p0 = nullptr;

    if (p0)
        std::cout << "What does this actually prove?\n";
    else
        std::cout << "Its a null pointer?\n";
}
