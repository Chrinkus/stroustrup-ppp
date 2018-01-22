//
// Stroustrup - Programming Principles & Practice
//
// Chapter 20 Exercise 3
// 
// Redo the Jack and Jill example using the palindrome detection techniques
// from 18.7. I assume this means make an iterator that works from both ends
// inwards. Not sure how copying in reverse would help find the highest value.
//

#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>    
#include <memory>       // std::unique_ptr
#include <cfloat>       // DBL_MIN

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// mocks

double* get_from_jack(int* count)
    // mock jack data
    // must return double*
{
    constexpr int chunk = 8;

    std::ifstream ifs {"jack.txt"};

    int size = chunk;
    std::unique_ptr<double[]> da {new double[size]};

    for (int i = 0; ifs >> da[i]; ++i) {
        *count += 1;
        if (i + 1 == size) {
            std::unique_ptr<double[]> p {new double[size + chunk]};
            std::copy(da.get(), da.get() + size, p.get());
            size += chunk;
            da = std::move(p);
        }
    }

    return da.release();
}

std::vector<double>* get_from_jill()
{
    std::ifstream ifs {"jill.txt"};

    std::unique_ptr<std::vector<double>> v {new std::vector<double>};
    for (double d; ifs >> d; )
        v->push_back(d);

    return v.release();
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// new high

double* high(double* first, double* last)
{
    double h = DBL_MIN;
    double* high = first;
    while (first <= last) {
        if (h < *first) { high = first; h = *first; }
        if (h < *last) { high = last; h = *last; }
        ++first;
        --last;
    }
    return high;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

void fct()
{
    int jack_count = 0;
    double* jack_data = get_from_jack(&jack_count);

    std::vector<double>* jill_data = get_from_jill();

    // process..
    double* jack_high = high(jack_data, jack_data + jack_count);
    std::vector<double>& v = *jill_data;
    double* jill_high = high(&v[0], &v[0] + v.size());

    std::cout << "Jill's max: " << *jill_high
              << "; Jack's max: " << *jack_high << '\n';

    delete [] jack_data;
    delete jill_data;
}

int main()
try {
    fct();
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

