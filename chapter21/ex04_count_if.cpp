//
// Stroustrup - Programming Principles & Practice
//
// Chapter 21 Exercise 4
//
// Implement count_if() and test it.
//

#include <iostream>
#include <stdexcept>
#include <vector>
#include <list>
#include <string>

template<typename Iter, typename Pred>
unsigned int my_count_if(Iter first, Iter last, Pred pred)
{
    unsigned int count = 0;

    while (first != last) {
        if (pred(*first))
            ++count;
        ++first;
    }

    return count;
}

struct Actor {
    std::string name;
    char sex;               // m or f
};

class Check_sex {
    char sex;
public:
    Check_sex(char s) : sex{s}
    {
        if (s != 'm' && s != 'f')
            throw std::runtime_error("unrecognized sex!");
    }

    bool operator()(const Actor& a) { return a.sex == sex; }
};

int main()
try {
    std::vector<int> vi { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

    auto threes = my_count_if(vi.begin(), vi.end(),
            [](int v) { return v % 3 == 0; });

    std::cout << "There are " << threes << " multiples of 3 in vi\n";

    std::list<Actor> la {
        { "Whitney Houston", 'f' },
        { "Bruce Willis", 'm' },
        { "Kurt Russel", 'm' },
        { "Markie Post", 'f' },
        { "Winona Ryder", 'f' }
    };

    auto women = my_count_if(la.begin(), la.end(), Check_sex('f'));

    std::cout << "There are " << women << " ladies in la\n";
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

