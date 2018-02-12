#include "../text_lib/std_lib_facilities.h"

int main()
{
    // Sieve of Eratosthenes
    vector<int> primes;
    vector<int> sieve;

    for (int i = 0; i <= 100; ++i) 
        if (i < 2)
            sieve.push_back(0);
        else
            sieve.push_back(i);

    for (int i = 0; i < sieve.size(); ++i) {
        if (sieve[i] != 0) {
            primes.push_back(i);

            if (i * i < sieve.size())
                for (int j = i; j < sieve.size(); j += i)
                    sieve[j] = 0;
        }
    }

    for (int n : primes)
        cout << n << '\n';
}
