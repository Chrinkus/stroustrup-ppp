//
// Stroustrup - Programming Principles & Practice
//
// Chapter 21 Drill 1 - vector
//

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <fstream>
#include <list>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// 1. Define a struct Item
struct Item {
    std::string name;
    int iid;
    double value;
};

std::ostream& operator<<(std::ostream& os, const Item& it)
{
    return os << it.name << '\t'
              << it.iid << '\t'
              << it.value;
}

std::istream& operator>>(std::istream& is, Item& it)
{
    std::string ss;
    int ii;
    double dd;
    is >> ss >> ii >> dd;
    Item itt {ss, ii, dd};
    it = itt;
    return is;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// 4. Sort vi by decreasing value
struct Cmp_by_dec_val {
    bool operator()(const Item& a, const Item& b)
    {
        return a.value > b.value;
    }
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// 5. Insert in order
class Smaller_than {
    double val;
public:
    Smaller_than(double vv) : val{vv} { }
    bool operator()(const Item& x) const { return x.value < val; }
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// 6. Erase by name
class Cmp_by_name {
    std::string name;
public:
    Cmp_by_name(const std::string& nn) : name{nn} { }
    bool operator()(const Item& x) const { return x.name == name; }
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// 7. Erase by iid
class Cmp_by_iid {
    int iid;
public:
    Cmp_by_iid(int id) : iid{id} { }
    bool operator()(const Item& x) const { return x.iid == iid; }
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
template<typename C>
void print(const C& c, char sep = ' ')
{
    for (const auto& a : c)
        std::cout << a << sep;
    std::cout << '\n';
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
int main()
try {
    // 1. Make a vector<Item> and fill it with ten Items from a file
    const std::string iname {"input_items.txt"};

    std::ifstream ifs {iname};
    if (!ifs) throw std::runtime_error("Could not read from file: " + iname);

    std::vector<Item> vi;
    for (Item ii; ifs >> ii; )
        vi.push_back(ii);

    // 8. Repeat exercise with a list<Item>
    std::list<Item> li (vi.size());
    std::copy(vi.begin(), vi.end(), li.begin());

    // 2. Sort vi by name
    std::sort(vi.begin(), vi.end(),
            [](const Item& a, const Item& b) { return a.name < b.name; });

    // 3. Sort vi by iid
    std::sort(vi.begin(), vi.end(),
            [](const Item& a, const Item& b) { return a.iid < b.iid; });

    // 4. Sort vi by decreasing value
    std::sort(vi.begin(), vi.end(), Cmp_by_dec_val());

    // 5. Insert items. Does not indicate that they are to be inserted in the
    // correct position to preserve order but lets try anyway
    Item tmp {"horse shoe", 99, 1.34};  // value changed to test end() return
    vi.insert(
            std::find_if(vi.begin(), vi.end(), Smaller_than(tmp.value)),
            tmp);

    tmp = Item{"Canon S400", 9988, 499.95};
    vi.insert(
            std::find_if(vi.begin(), vi.end(), Smaller_than(tmp.value)),
            tmp);

    // 6. Remove two items identified by name
    vi.erase(std::find_if(vi.begin(), vi.end(), Cmp_by_name("water")));
    vi.erase(std::find_if(vi.begin(), vi.end(), Cmp_by_name("chair")));

    // 7. Remove two items identified by iid
    vi.erase(std::find_if(vi.begin(), vi.end(), Cmp_by_iid(17)));
    vi.erase(std::find_if(vi.begin(), vi.end(), Cmp_by_iid(83)));

    // 8. Repeat the above steps with a list<Item>
    print(li, '\n');

    // list sort is member function since list does not have a random-access
    // iterator as needed by std::sort.
    li.sort([](const Item& a, const Item& b) { return a.name < b.name; });
    li.sort([](const Item& a, const Item& b) { return a.iid < b.iid; });
    li.sort([](const Item& a, const Item& b) { return a.value > b.value; });

    // changed names to not upset the tabbing..
    tmp = {"horse", 99, 1.34};
    li.insert(std::find_if(li.begin(), li.end(), Smaller_than(tmp.value)),
            tmp);

    tmp = {"Canon", 9988, 499.95};
    li.insert(std::find_if(li.begin(), li.end(), Smaller_than(tmp.value)),
            tmp);

    li.erase(std::find_if(li.begin(), li.end(), Cmp_by_name("table")));
    li.erase(std::find_if(li.begin(), li.end(), Cmp_by_name("phone")));

    li.erase(std::find_if(li.begin(), li.end(), Cmp_by_iid(58)));
    li.erase(std::find_if(li.begin(), li.end(), Cmp_by_iid(2011)));

    print(li, '\n');
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

