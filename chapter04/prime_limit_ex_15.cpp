#include "../text_lib/std_lib_facilities.h"

int main()
{
    // Prime numbers to 100
    vector<int> primes = { 2 };
    
    bool is_prime;

    int limit;
    cout << "How many primes should we find?\n";
    cin >> limit;

    for (int i = 3; primes.size() < limit; ++i) {
        is_prime = true;
        for (int prime : primes)
            if (i % prime == 0)
                is_prime = false;

        if (is_prime)
            primes.push_back(i);
    }

    for (int prime : primes)
        cout << prime << '\n';
}
