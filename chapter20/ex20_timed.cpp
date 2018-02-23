//
// Stroustrup - Programming Principles & Practice
//
// Chapter 20 Exercise 20
//
// Run a timing experiment to compare the cost of using vector and list. Create
// random numbers and store them in an ordered vector and list.
//
// Originally this was run with just push backs, not bothering to keep order.
// That was NOT what the text asked but it was still fun. I had to figure out
// how to insert into vectors and lists while keeping order AND equal, as I
// thought the point was isolating the insertion operation.
//
// I ended up learning a lot more than anticipated. My inital ordered insertion
// was kind of ham-handed, start at front and iterate till a larger value was
// found then insert there. This solution is found in the Linear_ordered_fill
// function object. The results of this timing experiment saw vectors being
// faster than lists, which is not what was expected. I'd guess that stepping
// through a List may be more slower than insert and reallocations are in a 
// vector. Good to know.
//
// The next idea was to just remove the ordered requirement again but use
// insert rather than push_back as I initially attempted. This approach saw
// the linked list trounce the vector as expected.
//
// Lastly, when looking for better alternatives to ordered insertion I found
// the binary search algorithms, specifically upper_bound, which work excep-
// tionally well with random-access iterators. The results were astoundingly
// in favour of vectors with lists actually performing worse than my linear
// solution (since they don't have random-access iterators).
//
// Comparing to a multiset I see that ordered insertion into a vector using
// binary search to find the right spot is fast enough to reinforce the state-
// ment "use vector almost always"!

#include <iostream>
#include <stdexcept>
#include <chrono>
#include <vector>
#include <list>
#include <random>
#include <functional>
#include <array>
#include <set>

using namespace std::chrono;

template<typename Func>
void time_check(Func& op, const std::string& label = "")
{
    auto t1 = system_clock::now();//.time_since_epoch().count();

    op();

    auto t2 = system_clock::now();//.time_since_epoch().count();

    std::cout << "Task " << label << " took\n"
              << '\t' << duration_cast<milliseconds>(t2 - t1).count()
              << " milliseconds\n"
              << '\t' << duration_cast<microseconds>(t2 - t1).count()
              << " microseconds\n";
}

template<typename C, typename D>
class Linear_ordered_fill {
    C c;
    const D& d;
public:
    Linear_ordered_fill(C cc, const D& dd) : c{cc}, d{dd} { }

    void operator()()
    {
        for (auto p = d.begin(); p != d.end(); ++p) {
            auto it = c.begin();
            while (it != c.end() && *it < *p) ++it;
            c.insert(it, *p);
        }
    }
};

template<typename C, typename D>
class Binary_ordered_fill {
    C c;
    const D& d;
public:
    Binary_ordered_fill(C cc, const D& dd) : c{cc}, d{dd} { }

    void operator()()
    {
        for (const auto a : d) {
            auto it = std::upper_bound(c.begin(), c.end(), a);
            c.insert(it, a);
        }
    }
};

template<typename C, typename D>
class Front_fill {
    C c;
    const D& d;
public:
    Front_fill(C cc, const D& dd) : c{cc}, d{dd} { }

    void operator()()
    {
        for (const auto a : d)
            c.insert(c.begin(), a);
    }
};

template<typename D>
class Set_fill {
    std::multiset<int> st;
    const D& d;
public:
    Set_fill(std::multiset<int> ss, const D& dd) : st{ss}, d{dd} { }

    void operator()()
    {
        for (const auto a : d)
            st.insert(a);
    }
};

int main()
try {
    const int n = 10000;

    // randomizer
    int seed = system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(1, n);
    auto dice = std::bind(distribution, generator);

    std::array<int,n> rand_arr;
    for (auto it = rand_arr.begin(); it != rand_arr.end(); ++it)
        *it = dice();

    Linear_ordered_fill<std::vector<int>,std::array<int,n>> vec {
        std::vector<int>(), rand_arr
    };

    Linear_ordered_fill<std::list<int>,std::array<int,n>> lst {
        std::list<int>(), rand_arr
    };

    time_check(vec, "linear ordered vector");
    time_check(lst, "linear ordered list");

    Binary_ordered_fill<std::vector<int>,std::array<int,n>> vec3 {
        std::vector<int>(), rand_arr
    };

    Binary_ordered_fill<std::list<int>,std::array<int,n>> lst3 {
        std::list<int>(), rand_arr
    };

    time_check(vec3, "binary ordered vector");
    time_check(lst3, "binary ordered list");

    Front_fill<std::vector<int>,std::array<int,n>> vec2 {
        std::vector<int>(), rand_arr
    };

    Front_fill<std::list<int>,std::array<int,n>> lst2 {
        std::list<int>(), rand_arr
    };

    time_check(vec2, "front filled vector");
    time_check(lst2, "front filled list");

    Set_fill<std::array<int,n>> si { std::multiset<int>(), rand_arr };

    time_check(si, "naturally ordered set");

    /*
    // Old solution
    std::vector<int> vi;
    std::list<int> li;
    std::multiset<int> si;

    // task Vector
    auto t1 = system_clock::now();          // begin time

    for (int i = 0; i < n; ++i) {
        int ran = dice();
        auto it = vi.begin();
        while (it != vi.end() && *it < ran) ++it;
        vi.insert(it, ran);
    }

    auto t2 = system_clock::now();          // end time

    std::cout << "Task vector took "
              << duration_cast<milliseconds>(t2 - t1).count()
              << " milliseconds.\n\n";

    // task List
    auto t3 = system_clock::now();          // begin time

    for (int i = 0; i < n; ++i) {
        int ran = dice();
        auto it = li.begin();
        while (it != li.end() && *it < ran) ++it;
        li.insert(it, ran);
    }

    auto t4 = system_clock::now();          // end time
    
    std::cout << "Task list took "
              << duration_cast<milliseconds>(t4 - t3).count()
              << " milliseconds.\n\n";

    // task Set
    auto t5 = system_clock::now();          // begin time

    for (int i = 0; i < n; ++i) {
        si.insert(dice());
    }

    auto t6 = system_clock::now();          // end time
    
    std::cout << "Task set took "
              << duration_cast<milliseconds>(t6 - t5).count()
              << " milliseconds.\n\n";
    */
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

