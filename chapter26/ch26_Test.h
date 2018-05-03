//
// Stroustrup - Programming Principles & Practice
//
// Chapter 26 Test Framework
//

#ifndef TEST_H
#define TEST_H

#include <string>
#include <vector>
#include <iostream>

struct Test {
    std::string label;
    int val;
    std::vector<int> seq;
    bool res;
};

std::istream& operator>>(std::istream& is, Test& t)
{
    char ch1, ch2;
    std::string lab;
    int val;
    is >> ch1 >> lab >> val >> ch2;

    if (!is || (ch1 != '{' || ch2 != '{'))
        return is;

    std::vector<int> vi;
    for (int v; is >> v; )
        vi.push_back(v);

    is.clear();

    bool result;
    is >> ch1 >> result >> ch2;
    if (!is)
        return is;

    t.label = lab;
    t.val = val;
    t.seq = vi;
    t.res = result;

    return is;
}

#endif
