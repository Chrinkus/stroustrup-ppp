//
// Stroustrup - Programming Principles & Practice
//
// Chapter 18 Exercise 11
//
// Implement a skip list
//
// Node and basic Skip_list implemented. Current list allows insertion of
// integer type values, assigns a random level and places them into the list
// in order.
//
// Print_list has been modified to selectively print the express lanes. Nodes
// currently "know" their level for proofing though real skip list nodes do
// not.
//
// Search and delete are next to be added, then a max level that grows as
// elements are added to the list.

#include <iostream>
#include <stdexcept>
#include <random>
#include <functional>       // std::bind
#include <chrono>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// Random level generator

int seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine generator(seed);
std::bernoulli_distribution distribution(0.5);
auto coin_flip = std::bind(distribution, generator);

int generate_prob(int max)
{
    int prob = 1;
    while (prob < max) {
        if (!coin_flip())
            break;
        ++prob;
    }
    return prob;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// Node data structure

struct Node {
    explicit Node(int levels)
        : val{INT_MIN}, lvl{levels}, fwd{new Node*[levels]}
    {
        for (int i = 0; i < levels; ++i) fwd[i] = nullptr;
    }

    Node(int value, int levels, Node** forward)
        : val{value}, lvl{levels}, fwd{new Node*[levels]}
    {
        for (int i = 0; i < levels; ++i) fwd[i] = forward[i];
    }

    ~Node() { delete fwd[0]; delete[] fwd; }

    int val;
    int lvl;
    Node** fwd;
private:
    Node(const Node&);              // prevent copying
    Node& operator=(const Node&);
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// Skip list implementation

class Skip_list {
    int sz;                     // needed for calculating lvls *future*
    int lvls;                   // should grow with list, is set by arg for now
    Node* head;           
public:
    explicit Skip_list(int levels)
        : sz{0}, lvls{levels}, head{new Node(levels)} { }

    ~Skip_list() { delete head; }

    void insert(int);
    Node* front(int i = 0) const { return head->fwd[i]; }
};

void Skip_list::insert(int n)
{
    // create temp Node* array to fill with values just lower than n
    Node* update[lvls];
    update[lvls-1] = head;

    for (int i = lvls - 1; i >= 0; --i) {
        
        // compare values until find one greater or hit end of list at level
        while (update[i]->fwd[i] != nullptr && update[i]->fwd[i]->val < n)
            update[i] = update[i]->fwd[i];

        update[i-1] = update[i];
    }

    // create new Node with empty forward array of random size
    int levels = generate_prob(lvls);
    Node* forward[levels];
    Node* new_node = new Node{n, levels, forward};

    // shuffle pointers to insert new_node
    for (int i = 0; i < levels; ++i) {
        if (head->fwd[i] == nullptr) {          // check if this level is empty
            head->fwd[i] = new_node;
            new_node->fwd[i] = nullptr;
        }
        else {
            new_node->fwd[i] = update[i]->fwd[i];
            update[i]->fwd[i] = new_node;       // prev's fwd is new_node
        }

    }
    
    // increase list size
    ++sz;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// Print function for proofing

void print_skip_list(Skip_list& skip, int n = 0)
{
    Node* p = skip.front(n);
    while (p != nullptr) {
        std::cout << p->val << ' ' << p->lvl << '\n';
        p = p->fwd[n];
    }
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

int main()
try {
    Skip_list test(4);

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

    std::cout << "Level 1\n";
    print_skip_list(test);
    std::cout << "Level 2\n";
    print_skip_list(test, 1);
    std::cout << "Level 3\n";
    print_skip_list(test, 2);
    std::cout << "Level 4\n";
    print_skip_list(test, 3);
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

