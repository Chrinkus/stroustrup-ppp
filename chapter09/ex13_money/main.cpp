#include "money.h"
#include <iostream>

int main()
{
    Money five_bucks{5.00};
    Money ten_bucks{10.00};

    std::cout << five_bucks << '\n'
              << ten_bucks << '\n'
              << five_bucks + ten_bucks << '\n';

    Money loose_change{2.35};
    Money extra_deci{17.312};
    Money round_up{8.628};

    std::cout << loose_change << '\n'
              << extra_deci << '\n'
              << round_up << '\n';
    
    // International money
    Money canadian{"CDN", 53.20};
    Money danish{"DKK", 16.07};
    Money american{"USD", 1.72};

    std::cout << canadian << '\n'
              << danish << '\n'
              << american << '\n';
}
