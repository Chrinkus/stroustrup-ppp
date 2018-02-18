//
// Stroustrup - Programming Principles & Practice
//
// Chapter 21 Exercise 13
//
// Write a program to "clean up" a text file for use in a word query program.
// - replace punctuation with whitespace
// - put words into lower case
// - replace don't with do not etc*
// - remove plurals (ships becomes ship) if both singular and plural forms 
// exist in set.
//

#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <fstream>
#include <map>

void handle_not(std::string& s, std::string::size_type pos)
    // n't is an expecially finicky contraction
{
    if (s == "can't")
        s = "cannot";
    else if (s == "won't")
        s = "would not";
    else
        s.replace(pos - 1, 3, " not");
}

void spread_contractions(std::string& s)
    // not perfect but good enough
    // - all 's's are assumed to be posessive and thus removed
    // - all 'd's are assumed to be 'had' instead of 'would'
    // - weird contractions like o'clock are not handled
{
    auto pos = s.find('\'');

    switch (s[pos+1]) {
        case 't':
            handle_not(s, pos);
            break;
        case 'd':
            s.replace(pos, 2, " had");
            break;
        case 'l':
            s.replace(pos, 3, " will");
            break;
        case 'v':
            s.replace(pos, 3, " have");
            break;
        case 'm':
            s.replace(pos, 2, " am");
            break;
        case 'r':
            s.replace(pos, 3, " are");
            break;
        case 's':
            s.erase(pos, 2);
            break;
        default:
            std::cout << "Could not handle: " << s << '\n';
            break;
    }
}

bool case_punct_pass(std::string& s)
    // in a single pass through the string
    // - change upper-case to lower-case
    // - replace most punctuation with whitespace
    // - return boolean flag if contraction is detected
{
    bool contraction = false;

    for (auto it = s.begin(); it != s.end(); ++it) {
        if (isupper(*it))
            *it = tolower(*it);
        else if (ispunct(*it)) {
            if (*it == '\'')
                contraction = true;
            else
                *it = ' ';
        }
    }

    return contraction;
}

void text_cleaner(std::string& s)
    // takes a single whitespace-separated word and cleans it.
    // may return a multi-word string as a result of contraction removal.
{
    bool contraction = case_punct_pass(s);

    if (contraction)
        while (s.find('\'') != std::string::npos)
            spread_contractions(s);
}

void remove_plurals(std::map<std::string,int>& msi)
{
    for (auto it = msi.begin(); it != msi.end(); ++it) {
        std::string plural = it->first + "s";   // create plural form of key
        auto p = msi.find(plural);              
        if (p != msi.end()) {                   // test if plural key exists
            it->second += p->second;            // add the word count of plural
                                                // to singular
            msi.erase(p);                       // remove plural key
        }
    }
}

std::map<std::string,int> get_word_data(const std::string& fname)
{
    std::ifstream ifs {fname};
    if (!ifs)
        throw std::runtime_error("Could not read from file: " + fname);

    std::map<std::string,int> word_data;

    for (std::string word; ifs >> word; ) {
        text_cleaner(word);         // remove punct, upper case & contractions
        std::istringstream iss {word};      // word may now be two words

        for (std::string w; iss >> w; )
            ++word_data[w];
    }

    remove_plurals(word_data);

    return word_data;
}

/*
int main()
try {
    const std::string iname = "./input_story.txt";

    std::map<std::string,int> query_data = get_word_data(iname);

    for (const auto& a : query_data)
        std::cout << a.first << ": " << a.second << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}
*/

