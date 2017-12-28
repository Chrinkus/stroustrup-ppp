//
// Stroustrup - Programming Principles & Practice
//
// Chapter 18 Exercise 11
//
// Implement a skip list
// NOT YET COMPLETE

#include <iostream>
#include <stdexcept>
#include <random>
#include <functional>

class Skip_list {
    int sz;
    int lvls;
    Node* head[];
public:
    Skip_list();

    void insert(Node&);
};

Skip_list::Skip_list()
    // levels is fixed for now as currently we aren't changing the size of
    // arrays in this chapter.
    : sz{0}, lvls{4}, head{new int[lvls]}
{
    for (int i = 0; i < lvls; ++i) head[i] = nullptr;
}

void Skip_list::insert(Node& n)
{
    int lvl = 0;
    while (lvl < lvls) {
        std::default_random_engine gen;
        std::uniform_int_distribution<> dist(0, 1);
        if (dist(gen) == 0)
            break;
        ++lvl;
    }

    // set Node's level
    // determine where in the list to insert
}

class Node {
    int val;
    int lvl;
    int forward[];
public:
    Node(int);
};

int main()
try {
    std::default_random_engine ran;
    std::uniform_int_distribution<> dist(1, 6);
    auto dice = std::bind(dist, ran);

    std::cout << dice() << ' ' << dice() << ' ' << dice() << '\n';
    std::cout << dice() << ' ' << dice() << ' ' << dice() << '\n';
    std::cout << dice() << ' ' << dice() << ' ' << dice() << '\n';
    std::cout << dice() << ' ' << dice() << ' ' << dice() << '\n';

}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

