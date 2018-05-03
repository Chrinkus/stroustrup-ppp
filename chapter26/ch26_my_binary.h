//
// Stroustrup - Programming Principles & Practice
//
// Chapter 26 My Binary Search
//

#ifndef MY_BINARY_SEARCH_H
#define MY_BINARY_SEARCH_H

template<typename Iter, typename T>
bool my_binary(Iter first, Iter last, const T& val)
{
    if (first == last) return false;        // empty sequence

    while (first <= last) {
        Iter mid = first + (std::distance(first, last) / 2);

        if (val == *mid)
            return true;
        else if (val < *mid)
            last = --mid;
        else
            first = ++mid;
    }

    return false;
}

template<typename Iter, typename T, typename BinOp>
bool my_binary(Iter first, Iter last, const T& val, BinOp cmp)
{
    if (first == last) return false;

    while (first <= last) {
        Iter mid = first + (std::distance(first, last) / 2);

        if (val == *mid)
            return true;
        else if (cmp(val, *mid))
            last = --mid;
        else
            first = ++mid;
    }

    return false;
}

#endif
