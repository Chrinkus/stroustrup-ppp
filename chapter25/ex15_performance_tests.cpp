//
// Stroustrup - Programming Principles & Practice
//
// Chapter 25 Exercise 15 - Performance testing
//
// Measure the time it takes to:
// - allocate 10000 objects of random sizes in the [1000:0) byte range using
// new, then measure the time it takes to deallocate them using delete
// - do this twice, deallocating once in reverse order, and once in random
// order
// - then do the same for allocating 10000 objects of 500 bytes from a pool and
// freeing them
// - then do the same for allocating 10000 objects of random sizes in the same
// range as above on a stack and free them (in reverse order only).
// - do each measurement 3 times
//
/* OUTPUT:
First run (reverse deallocate):
  random size allocation 1 took: 1739 microseconds
  random size reverse deallocation took: 4852 microseconds
Second run (random deallocate):
  random size allocation 2 took: 1981 microseconds
  random size random deallocation took: 3029 microseconds
Pool allocation (reverse deallocate):
  pool allocation 1 took: 1075 microseconds
  pool reverse deallocation took: 1245 microseconds
Pool allocation (random deallocate):
  pool allocation 2 took: 1060 microseconds
  pool random deallocation took: 1124 microseconds
Stack allocation (reverse deallocate):
  stack random size allocation took: 1533 microseconds
  stack reverse deallocation took: 436 microseconds
*/

#include <iostream>
#include <stdexcept>
#include <random>
#include <vector>
#include <list>
#include <algorithm>
#include <chrono>
#include <string>

using namespace std::chrono;

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// global constants
const int test_min = 1;
const int test_max = 1000;
const int test_size = 10000;

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// utility functions
int randint(int min, int max)
{
    static std::default_random_engine ran;
    return std::uniform_int_distribution<>{min, max}(ran);
}

template<typename C>
void print(const C& c)
{
    for (const auto& a : c)
        std::cout << a << '\n';
}

template<typename T>
void random_size_fill(std::vector<T*>& vp)
{
    for (auto i = 0; i < test_size; ++i) {
        T* chunk = new T[randint(test_min, test_max)];
        vp[i] = chunk;
    }
}

struct Make_timer{
    system_clock::time_point t1;
    Make_timer() : t1{system_clock::now()} { }
    void operator()(const std::string& lab)
    {
        auto t2 = system_clock::now();
        std::cout << "  " << lab << " took: "
                  << duration_cast<microseconds>(t2-t1).count()
                  << " microseconds\n";
    }
    void reset()
    {
        t1 = system_clock::now();
    }
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// pool
template<typename T, int N>
class Pool {
    public:
        Pool() : pool{new T[N]}
        {
            for (T* p = pool; p < pool + N; ++p)
                free_pool.push_back(p);
        }

        T* get();
        void free(T*);
        int available() const { return free_pool.size(); }

        ~Pool() { delete[] pool; }
    private:
        T* pool;
        std::list<T*> free_pool;
};

template<typename T, int N>
T* Pool<T,N>::get()
{
    if (!available())
        return nullptr;

    T* p = free_pool.front();
    free_pool.pop_front();
    return p;
}

template<typename T, int N>
void Pool<T,N>::free(T* p)
{
    free_pool.push_back(p);
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// 500 byte object
struct Five {
    char* chunk;
    Five() : chunk{new char[500]} { }
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// stack
template<int N>
class Stack {
    public:
        Stack() : stack{new char[N]}, top{stack} { }
        void* get(int);
        void free();
        int available() const { return N - std::distance(stack, top); }
    private:
        char* stack;
        char* top;
        std::vector<char*> last;
};

template<int N>
void* Stack<N>::get(int n)
{
    last.push_back(top);
    top = top + n;
    return static_cast<void*>(last.back());
}

template<int N>
void Stack<N>::free()
{
    top = last.back();
    last.pop_back();
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

int main()
try {
    Make_timer timer;

    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    // 1. allocate 10000 random sizes, deallocate in reverse
    std::cout << "First run (reverse deallocate):\n";
    std::vector<char*> vpc1 (test_size);

    timer.reset();
    random_size_fill(vpc1);
    timer("random size allocation 1");

    timer.reset();
    for (auto i = test_size - 1; i >= 0; --i) {
        delete[] vpc1[i];
    }
    timer("random size reverse deallocation");

    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    // 2. allocate 10000 random sizes, deallocate randomly
    std::cout << "Second run (random deallocate):\n";
    std::vector<char*> vpc2 (test_size);

    timer.reset();
    random_size_fill(vpc2);
    timer("random size allocation 2");

    std::random_shuffle(vpc2.begin(), vpc2.end());

    timer.reset();
    for (auto i = 0; i < test_size; ++i) {
        delete[] vpc2[i];
    }
    timer("random size random deallocation");

    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    // 3. allocate 10000 of 500 bytes from pool, deallocate in reverse
    Pool<Five,test_size> fh_pool;
    std::cout << "Pool allocation (reverse deallocate):\n";
    std::vector<Five*> vpf1 (test_size);

    timer.reset();
    for (auto i = 0; i < test_size; ++i)
        vpf1[i] = fh_pool.get();
    timer("pool allocation 1");

    timer.reset();
    for (auto i = test_size - 1; i >= 0; --i)
        fh_pool.free(vpf1[i]);
    timer("pool reverse deallocation");

    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    // 4. allocate 10000 of 500 bytes from pool, deallocate randomly
    std::cout << "Pool allocation (random deallocate):\n";
    std::vector<Five*> vpf2 (test_size);

    timer.reset();
    for (auto i = 0; i < test_size; ++i)
        vpf2[i] = fh_pool.get();
    timer("pool allocation 2");

    std::random_shuffle(vpf2.begin(), vpf2.end());

    timer.reset();
    for (auto i = 0; i < test_size; ++i)
        fh_pool.free(vpf2[i]);
    timer("pool random deallocation");

    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
    // 5. allocate 10000 random sizes on a stack, deallocate in reverse
    Stack<10000000> big_stack;
    std::vector<char*> vpc3 (test_size);

    std::cout << "Stack allocation (reverse deallocate):\n";
    timer.reset();
    for (auto i = 0; i < test_size; ++i) {
        void* pv1 = big_stack.get(randint(test_min, test_max));
        vpc3[i] = static_cast<char*>(pv1);
    }
    timer("stack random size allocation");

    timer.reset();
    for (auto i = test_size - 1; i >= 0; --i) {
        vpc3.pop_back();            // cleanup doubles time of deallocation
        big_stack.free();
    }
    timer("stack reverse deallocation");
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

