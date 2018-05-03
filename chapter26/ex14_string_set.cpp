//
// Stroustrup - Programming Principles & Practice
//
// Chapter 26 Exercise 14
//
// Repeat random string container fill using map so the sequences are already
// sorted. I used a set instead since there wasn't really a 'pair'.
//

#include <iostream>
#include <stdexcept>
#include <random>
#include <chrono>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <thread>
#include <mutex>

using namespace std::chrono;

std::mutex mtx;                     // where is the best place for this?

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// Timing
class Make_timer {
    public:
        Make_timer() : t1{system_clock::now()} { }

        void reset() { t1 = system_clock::now(); }

        void operator()(const std::string& label)
        {
            auto t2 = system_clock::now();
            std::cout << "  " << label << " took: "
                      << duration_cast<microseconds>(t2-t1).count()
                      << " microseconds\n";
        }
    private:
        system_clock::time_point t1;
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// Random string generation
std::string get_string()
{
    constexpr unsigned int min = 1;         // smallest string
    constexpr unsigned int max = 100;       // largest string
    constexpr unsigned short low = 33;      // low end of char-range
    constexpr unsigned short high = 126;    // high end of char-range

    std::stringstream ss;

    thread_local static std::default_random_engine ran;
    auto len = std::uniform_int_distribution<>{min, max}(ran);

    for (auto i = 0; i < len; ++i)
        ss << std::uniform_int_distribution<char>{low, high}(ran);
    
    return ss.str();
}

template<typename C> C random_fill(int n)
{
    C vs;
    for (auto i = 0; i < n; ++i)
        vs.insert(get_string());
    return vs;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// Multi-threading
void fill_task(std::set<std::string>& vs, int n, std::mutex& m)
{
    std::set<std::string> v = random_fill<std::set<std::string>>(n);

    std::unique_lock<std::mutex> lck {m};
    for (const auto& a : v)
        vs.insert(a);
}

std::set<std::string> threaded_fill(int n)
    // fill a large set with random strings
    // thread number performance:
    // 1: ~107
    // 4: ~32s
    // 8: ~28s
{
    std::set<std::string> vs;

    constexpr int num_threads = 8;

    std::mutex mtx;
    std::vector<std::thread> vt;            // still using vector for threads
    for (auto i = 0; i < num_threads; ++i)
        vt.push_back(std::thread{fill_task,
                                 std::ref(vs),
                                 n/num_threads,
                                 std::ref(mtx)});

    for (auto& t : vt)
        t.join();

    return vs;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// Utility
template<typename C>
void check_output(const C& c)
{
    std::cout << "first element: " << c.front() << '\n'
              << "last element: " << '\n'
              << c.back() << '\n';
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
int main()
try {
    const int test1 = 500000;
    const int test2 = 5000000;

    Make_timer timer;

    std::cout << "Filling both sets..\n";
    timer.reset();
    //std::vector<std::string> vs1 = random_fill(test1);
    //std::vector<std::string> vs2 = random_fill(test2);
    std::set<std::string> vs1 = threaded_fill(test1);
    std::set<std::string> vs2 = threaded_fill(test2);
    timer("set fills");

    /*
    std::cout << "Sorting " << test1 << " values:\n";
    timer.reset();
    std::sort(vs1.begin(), vs1.end());
    timer("vs1 sort");

    std::cout << "Sorting " << test2 << " values:\n";
    timer.reset();
    std::sort(vs2.begin(), vs2.end());
    timer("vs2 sort");

    std::cout << "Output check:\n";
    check_output(vs1);
    check_output(vs2);
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

