#include <iostream>
#include <numeric>
#include <vector>

int evens(int x, int y) { return y % 2 == 0 ? x + y : x; }

struct Mults_3x10 {
    int m = 10;
    int operator()(int x, int y) { return y % 3 == 0 ? x + y * m : x; }
} m3;

int main()
{
    int num_arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::vector<int> num_vec { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    std::cout << "default accumulate: ";
    std::cout << std::accumulate(num_arr, num_arr+10, 0);
    std::cout << '\n';

    std::cout << "vector accumulate: ";
    std::cout << std::accumulate(num_vec.begin(), num_vec.end(), 0);
    std::cout << '\n';

    std::cout << "vector evens: ";
    std::cout << std::accumulate(num_vec.begin(), num_vec.end(), 0, evens);
    std::cout << '\n';

    std::cout << "vector odds lambda: ";
    std::cout << std::accumulate(num_vec.begin(), num_vec.end(), 0,
            [](int x, int y) { return y % 2 != 0 ? x + y : x; });
    std::cout << '\n';

    std::cout << "vector mults of 3 struct: ";
    std::cout << std::accumulate(num_vec.begin(), num_vec.end(), 0, m3);
    std::cout << '\n';

    return 0;
}
