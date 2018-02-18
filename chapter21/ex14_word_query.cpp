//
// Stroustrup - Programming Principles & Practice
//
// Chapter 21 Exercise 14
//
// Write a word query program that provides information about the text in a
// document. Use the text cleaner from ex13 to produce input.
//

#include <iostream>
#include <stdexcept>
#include <string>
#include <map>
#include <vector>

int count_word(const std::map<std::string,int>& msi, const std::string& w)
    // return the number of times word 'w' is used in msi
{
    auto it = msi.find(w);
    if (it == msi.end())
        return 0;

    return it->second;
}

std::string most_freq(const std::map<std::string,int>& msi)
{
    auto freq = msi.begin();
    for (auto it = msi.begin(); it != msi.end(); ++it)
        if (it->second > freq->second)
            freq = it;

    return freq->first;
}

std::string longest_word(const std::map<std::string,int>& msi)
{
    auto longest = msi.begin();
    for (auto it = msi.begin(); it != msi.end(); ++it)
        if (it->first.size() > longest->first.size())
            longest = it;

    return longest->first;
}

std::string shortest_word(const std::map<std::string,int>& msi)
{
    auto shortest = msi.begin();
    for (auto it = msi.begin(); it != msi.end(); ++it)
        if (it->first.size() < shortest->first.size())
            shortest = it;

    return shortest->first;
}

std::vector<std::string> search_starts(const std::map<std::string,int>& msi,
        const std::string& sub)
{
    std::vector<std::string> vs;

    for (auto it = msi.begin(); it != msi.end(); ++it)
        if (std::equal(sub.begin(), sub.end(), it->first.begin()))
            vs.push_back(it->first);

    return vs;
}

std::vector<std::string> search_size(const std::map<std::string,int>& msi,
        int n)
{
    std::vector<std::string> vs;

    for (auto it = msi.begin(); it != msi.end(); ++it)
        if (it->first.size() == n)
            vs.push_back(it->first);

    return vs;
}

// forward declaration? see if this works
std::map<std::string,int> get_word_data(const std::string&);
// it does! ex 13 was compiled with 14!

int main()
try {
    const std::string fname = "./input_story.txt";

    std::map<std::string,int> word_data = get_word_data(fname);

    std::cout << "'toddler' was used "
              << count_word(word_data, "toddler") << " times\n";

    std::cout << "the most frequently used word was "
              << most_freq(word_data) << '\n';

    std::cout << "the longest word was: "
              << longest_word(word_data) << '\n';

    std::cout << "the shortest word was: "
              << shortest_word(word_data) << '\n';

    std::vector<std::string> starts_f = search_starts(word_data, "f");

    std::cout << "All of the 'f' words were:\n";
    for (const auto& a : starts_f)
        std::cout << a << ' ';
    std::cout << '\n';

    std::vector<std::string> fours = search_size(word_data, 4);

    std::cout << "there were " << fours.size() << " four-letter words\n";

    for (const auto& a : fours)
        std::cout << a << ' ';
    std::cout << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

