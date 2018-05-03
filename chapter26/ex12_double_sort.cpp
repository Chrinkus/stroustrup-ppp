//
// Stroustrup - Programming Principles & Practice
//
// Chapter 26 Exercise 12
//
// Generate random floating point values and measure the time it takes to sort
// them using std::sort. Measure the time to sort 500000 doubles and 5000000
// doubles.
//

#include <iostream>
#include <stdexcept>
#include <random>
#include <chrono>
#include <vector>
#include <string>

using namespace std::chrono;

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

double get_double()
{
    static std::default_random_engine ran;
    return std::uniform_real_distribution<double>{0,1000}(ran);
}

std::vector<double> random_fill(int n)
{
    std::vector<double> vd;
    vd.reserve(n);
    for (auto i = 0; i < n; ++i)
        vd.push_back(get_double());
    return vd;
}

int main()
try {
    const int test1 = 500000;
    const int test2 = 5000000;

    Make_timer timer;

    std::cout << "Filling both vectors..\n";
    std::vector<double> vd1 = random_fill(test1);
    std::vector<double> vd2 = random_fill(test2);
    timer("vector fills");

    std::cout << "Sorting " << test1 << " values:\n";
    timer.reset();
    std::sort(vd1.begin(), vd1.end());
    timer("vd1 sort");

    std::cout << "Sorting " << test2 << " values:\n";
    timer.reset();
    std::sort(vd2.begin(), vd2.end());
    timer("vd2 sort");
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

