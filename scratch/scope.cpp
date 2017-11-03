#include <iostream>

int main()
{
    int a = 8;

    {
        int a = 12;
        std::cout << a << '\n';
    }

    std::cout << a << '\n';
}
