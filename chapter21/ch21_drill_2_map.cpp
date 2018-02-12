//
// Stroustrup - Programming Principles & Practice
//
// Chapter 21 Drill - map
//

#include <iostream>
#include <stdexcept>
#include <map>
#include <string>
#include <numeric>

// 5. Read in pairs from std::cin and place them in map
void f(std::map<std::string, int>& m)
{
    std::string s;
    int i = 0;

    while (m.size() < 10) {
        std::cin >> s >> i;
        m.insert(std::make_pair(s, i));
    }
}

// 3. Output the pairs to std::cout
template<typename T, typename U>
void print(const std::map<T,U>& m)
{
    std::cout << "MAP CONTENTS:" << '\n'
              << "=============" << '\n';

    for (const auto& a : m)
        std::cout << a.first << '\t' << a.second << '\n';

    std::cout << "END" << "\n\n";
}

int main()
try {
    // 1. Define a map
    std::map<std::string, int> msi;

    // 2. Insert 10 pairs into map
    msi["Robert"] = 4;
    msi["Margret"] = 34;
    msi["Irene"] = 6;
    msi["Gregory"] = 38;
    msi["Lyle"] = 64;
    msi["Anne"] = 62;
    msi["Barbara"] = 33;
    msi["Young"] = 24;
    msi["Turk"] = 13;
    msi["Chloe"] = 9;

    // 3. Output the pairs
    print(msi);

    // 4. Erase the pairs from msi
    msi.erase(msi.begin(), msi.end());

    print(msi);

    // 6. Read 10 pairs from std::cin and place them in msi
    f(msi);

    // 7. Write the elements from msi to std::cout
    print(msi);

    // 8. Output the sum of the integer values in msi
    int total = std::accumulate(msi.begin(), msi.end(), 0,
            [](int sum, const std::pair<std::string,int>& p)
            { return sum += p.second; });

    std::cout << "Total of integers: " << total << '\n';

    // 9. Define a map<int,string>
    std::map<int, std::string> mis;

    // 10. Enter values from msi into mis
    for (const auto& a : msi)
        mis[a.second] = a.first;

    // 11. Output the elements of mis
    print(mis);
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

