//
// Stroustrup - Programming Principles & Practice
//
// Chapter 26 Exercise 13
//
// Generate random strings and measure the time it takes to sort them using
// std::sort. Measure the time to sort 500000 strings and 5000000 strings.
//
/* OUTPUT (single thread):
Filling both vectors..
  vector fills took: 51637430 microseconds
Sorting 500000 values:
  vs1 sort took: 842695 microseconds
Sorting 5000000 values:
  vs2 sort took: 10897702 microseconds
*/
/* OUTPUT (4 threads):
Filling both vectors..
  vector fills took: 15212392 microseconds
Sorting 500000 values:
  vs1 sort took: 745249 microseconds
Sorting 5000000 values:
  vs2 sort took: 9821658 microseconds
*/

#include <iostream>
#include <stdexcept>
#include <random>
#include <chrono>
#include <vector>
#include <string>
#include <sstream>
#include <thread>
#include <mutex>

using namespace std::chrono;

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
    constexpr unsigned short low = 97;      // low end of char-range
    constexpr unsigned short high = 122;    // high end of char-range

    std::stringstream ss;

    thread_local static std::default_random_engine ran;
    auto len = std::uniform_int_distribution<>{min, max}(ran);

    for (auto i = 0; i < len; ++i)
        ss << std::uniform_int_distribution<char>{low, high}(ran);
    
    return ss.str();
}

std::vector<std::string> random_fill(int n)
{
    std::vector<std::string> vs;
    vs.reserve(n);
    for (auto i = 0; i < n; ++i)
        vs.push_back(get_string());
    return vs;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// Multi-threading
void fill_task(std::vector<std::string>& vs, int n, std::mutex& m)
{
    std::vector<std::string> v = random_fill(n);

    std::unique_lock<std::mutex> lck {m};
    std::copy(v.begin(), v.end(), std::back_inserter(vs));
}

std::vector<std::string> threaded_fill(int n)
    // fill a large vector with random strings
{
    std::vector<std::string> vs;
    vs.reserve(n);

    const int num_threads = std::thread::hardware_concurrency();

    std::mutex mtx;
    std::vector<std::thread> vt;
    for (auto i = 0; i < num_threads; ++i)
        vt.push_back(std::thread{fill_task, std::ref(vs), n / num_threads,
                     std::ref(mtx)});

    for (auto& t : vt)
        t.join();

    std::cout << "vector size: " << vs.size() << '\n';
    return vs;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// Utility
void check_output(const std::vector<std::string>& vs)
{
    std::cout << "first element: " << vs.front() << '\n'
              << "last element: " << '\n'
              << vs.back() << '\n';
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
int main()
try {
    const int test1 = 500000;
    const int test2 = 5000000;

    Make_timer timer;

    std::cout << "Filling both vectors..\n";
    timer.reset();
    //std::vector<std::string> vs1 = random_fill(test1);
    //std::vector<std::string> vs2 = random_fill(test2);
    std::vector<std::string> vs1 = threaded_fill(test1);
    std::vector<std::string> vs2 = threaded_fill(test2);
    timer("vector fills");

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
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

