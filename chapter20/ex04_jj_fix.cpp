//
// Stroustrup - Programming Principles & Practice
//
// Chapter 20 Exercise 4
//
// Find and fix the errors in 20.3.1 by using STL techniques.
//
// Honestly not sure what the "serious error" was. Thinking it might have been
// the potential for leaking the memory in fct() but the problem indicates we
// must accept the data as it comes.
//

#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <memory>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// mocks

double* get_from_jack(int* count)
    // mock jack data
    // must return double*
{
    constexpr int chunk = 8;

    std::ifstream ifs {"jack.txt"};
    if (!ifs) throw std::runtime_error("Could not open file jack.txt");

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
    // mock jill data
    // must return vector<double>*
{
    std::ifstream ifs {"jill.txt"};
    if (!ifs) throw std::runtime_error("Could not open file jill.txt");

    std::unique_ptr<std::vector<double>> v {new std::vector<double>};
    for (double d; ifs >> d; )
        v->push_back(d);

    return v.release();
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

template<typename Iterator>
Iterator high(Iterator first, Iterator last)
    // return an iterator to the element in [first:last) that is highest val
{
    Iterator high = first;
    for (Iterator p = first; p != last; ++p)
        if (*high < *p) high = p;
    return high;
}

void fct()
{
    int jack_count = 0;
    double* jack_data = get_from_jack(&jack_count);
    std::vector<double>* jill_data = get_from_jill();

    double* jack_high = high(jack_data, jack_data + jack_count);
    std::vector<double>& v = *jill_data;
    double* jill_high = high(&v[0], &v[0] + v.size());

    std::cout << "Jill's high " << *jill_high
              << "; Jack's high " << *jack_high << '\n';

    delete[] jack_data;     // naked delete
    delete jill_data;       // naked delete
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

