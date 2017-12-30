//
// Stroustrup - Programming Principles & Practice
//
// Chapter 18 Exercise 11
//
// Implement a skip list
//
// Try to implement a regular linked list, add a head, attempt skips
// NOT YET COMPLETE - as is, functions as a singly-linked list with a head and
// sorted entry. To make this a skip list I need to find a way to change the 
// forward pointer into an array of pointers based on level and have each level
// point to the next element of that level. Also must somehow save back
// pointers covering the same levels for previous forwarding (?)

#include <iostream>
#include <stdexcept>
#include <random>
#include <functional>       // std::bind
#include <chrono>

// global answer...
int seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine generator(seed);
std::bernoulli_distribution distribution(0.5);
auto coin_flip = std::bind(distribution, generator);

int generate_prob(int max)
{
    int prob = 0;
    while (prob < max) {
        if (!coin_flip())
            break;
        ++prob;
    }
    return prob;
}

class Node {
    int val;
    int lvl;
public:
    // no default constructor
    Node(int n, int l, Node* fwd)
        : val{n}, lvl{l}, forward{fwd} { }

    ~Node() { delete forward; }

    Node* forward;

    int value() const { return val; }
    int level() const { return lvl; }
};

class Skip_list {
    int sz;                     // needed for calculating lvls *future*
    int lvls;                   // should grow with list, is set to 4 for this

public:
    Skip_list();

    ~Skip_list() { delete head; }

    Node* head;                 // pointer to first element

    void insert(int);
};

Skip_list::Skip_list()
    // levels is fixed for now as currently we aren't changing the size of
    // arrays in this chapter.
    : sz{0}, lvls{4}, head{new Node{INT_MIN, 4, nullptr}}
{
    // nothing yet
}

void Skip_list::insert(int n)
{
    // determine where in the list to insert
    int level = generate_prob(lvls - 1);
    Node* p = head;
    while (p->forward != nullptr && p->forward->value() < n) {
        p = p->forward;
    }
    
    // create Node for value n & pass max level to generate level
    Node* pn = new Node{n, level, p->forward};
    p->forward = pn;
    ++sz;
}

void print_skip_list(Skip_list& skl)
{
    Node* p = skl.head;
    while (p->forward != nullptr) {
        p = p->forward;
        std::cout << p->value() << ' ' << p->level() << '\n';
    }
}

int main()
try {
    Skip_list test;

    test.insert(37);
    test.insert(23);
    test.insert(67);
    test.insert(10);
    test.insert(44);
    test.insert(82);
    test.insert(17);
    test.insert(76);
    test.insert(28);
    test.insert(56);
    test.insert(4);
    test.insert(91);
    test.insert(21);
    test.insert(39);
    test.insert(62);

    print_skip_list(test);
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

