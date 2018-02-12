//
// Stroustrup - Programming Principles & Practice
//
// Chapter 21 Drill - moar vector 
//

#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <numeric>

class Less_than {
    double v;
public:
    Less_than(double vv) : v{vv} { }

    bool operator()(const double val) { return val < v; }
};

template<typename C> void print(const C& c, char sep = '\n')
{
    std::cout << "CONTAINER ELEMENTS:\n"
              << "===================\n";

    for (const auto ele : c)
        std::cout << ele << sep;

    std::cout << '\n';
}

int main()
try {
    // 1. Read floating-point values from a file into a vector<double>
    const std::string iname {"input_floats.txt"};
    std::ifstream ifs {iname};
    if (!ifs) throw std::runtime_error("Could not read from file: " + iname);

    std::vector<double> vd;
    for (double d; ifs >> d; )
        vd.push_back(d);

    // 2. Output vd to std::cout
    print(vd);

    // 3. Make a vector of ints and copy the elements from vd to vi
    std::vector<int> vi (vd.size());
    std::copy(vd.begin(), vd.end(), vi.begin());

    // 4. Output the pairs of vd[i], vi[i] to cout, one pair per line
    for (int i = 0; i < vd.size(); ++i)
        std::cout << vd[i] << '\t' << vi[i] << '\n';

    // 5. Output the sum of the elements of vd
    double double_sum = std::accumulate(vd.begin(), vd.end(), 0.0);

    std::cout << "Sum of vector<double>: " << double_sum << '\n';

    // 6. Output the difference between the sum of vd and sum of vi
    double diff_sum =
        std::inner_product(vd.begin(), vd.end(),
                vi.begin(),
                0.0,
                std::plus<double>(),
                std::minus<double>());

    std::cout << "The cumulative difference of int(double) truncs is: "
              << diff_sum << '\n';

    // 7. Reverse vd and output vd to std::cout
    std::reverse(vd.begin(), vd.end());

    print(vd);

    // 8. Compute the mean value of vd and output it
    double vd_mean = double_sum / vd.size();

    std::cout << "The mean of vd is: " << vd_mean << '\n';

    // 9. Make a new vector<double> and copy all elements from vd that are less
    // than vd's mean.
    std::vector<double> vd2 (vd.size());    // too big?

    auto it = std::copy_if(vd.begin(), vd.end(), vd2.begin(),
            Less_than(vd_mean));
    vd2.resize(std::distance(vd2.begin(), it));

    print(vd2);

    // 10. Sort vd, output it again
    std::sort(vd.begin(), vd.end());

    print(vd);
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

