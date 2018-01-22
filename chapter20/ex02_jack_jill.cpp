//
// Stroustrup - Programming Principles & Practice
//
// Chapter 20 Jack and Jill example
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
{
    std::ifstream ifs {"jill.txt"};
    if (!ifs) throw std::runtime_error("Could not open file jill.txt");

    std::unique_ptr<std::vector<double>> v {new std::vector<double>};
    for (double d; ifs >> d; )
        v->push_back(d);

    return v.release();
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

double* high(double* first, double* last)
    // return a pointer to the element in [first,last) that is highest
{
    double h = -1;
    double* high;
    for (double* p = first; p != last; ++p)
        if (h < *p) { high = p; h = *p; }
    return high;
}

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

