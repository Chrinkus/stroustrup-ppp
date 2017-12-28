#include <iostream>

int main()
{
    int ai[50] {1, 2, 3, 4, 5};
    int* p = ai;

    std::cout << "Array ai = " << ai << " size of ai = " << sizeof(ai) << '\n';
    std::cout << "Pointer p = " << p << " size of p = " << sizeof(p) << '\n';

    int n = 100;
    for (int* pi = ai; pi < &ai[sizeof(ai) / sizeof(int)]; ++pi)
        *pi = n++;

    std::cout << "The last element in ai is: " << ai[49] << '\n';

    char ch[100] {'a', 'b', 'c'};
    char* pc = ch;

    std::cout << "pc: " << &pc << " size of p is " << sizeof(pc) << '\n';
}
