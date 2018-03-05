//
// Stroustrup - Programming Principles & Practice
//
// Chapter 23 Exercise 5 - Huge Mail Test
//
// Find a mail file of thousands of messages and time it as written with a
// multimap and an unordered_multimap.
//
// There ended up being very little difference with 1200 emails. It was 47ms
// vs 48ms with the multimap being faster than an unordered_multimap.
//

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <fstream>
#include <regex>
#include <map>
#include <unordered_map>
#include <chrono>

using namespace std::chrono;

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
using Line_iter = std::vector<std::string>::const_iterator;

class Message {
    Line_iter first;
    Line_iter last;
public:
    Message(Line_iter p1, Line_iter p2) : first{p1}, last{p2} { }
    Line_iter begin() const { return first; }
    Line_iter end() const { return last; }
};
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
using Mess_iter = std::vector<Message>::const_iterator;

struct Mail_file {
    std::string name;                   // file name
    std::vector<std::string> lines;     // the lines in order
    std::vector<Message> m;             // Messages in order

    Mail_file(const std::string& s);    // read file s into lines

    Mess_iter begin() const { return m.begin(); }
    Mess_iter end() const { return m.end(); }
};

Mail_file::Mail_file(const std::string& fname)
{
    std::ifstream ifs {fname};
    if (!ifs) {
        std::cerr << "Could not read from file " << fname << '\n';
        exit(1);
    }

    for (std::string s; std::getline(ifs,s); )
        lines.push_back(s);

    auto first = lines.begin();
    for (auto p = lines.begin(); p != lines.end(); ++p) {
        if (*p == "----") {
            if (p != first)
                m.push_back(Message{first,p});
            first = p + 1;
        }
    }
}
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

// if found, put sender's name in s
bool find_from_addr(const Message* m, std::string& s)
{
    std::regex pat {R"(^From:\s?(.+)$)"};    // \s added to front ok?

    for (const auto& x : *m) {
        std::smatch matches;
        if (std::regex_search(x,matches,pat)) {
            s = matches[1];
            return true;
        }
    }

    return false;
}

// return the subject of the message, if any, otherwise ""
std::string find_subject(const Message* m)
{
    std::regex pat {R"(^Subject:\s?(.+)$)"};

    for (const auto& x : *m) {
        std::smatch matches;
        if (std::regex_search(x,matches,pat)) {
            return matches[1];
        }
    }

    return "";
}
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

int main()
try {
    std::cout << "Enter an email file to process:\n";
    std::string fname;
    std::cin >> fname;

    Mail_file mfile {fname};

    // ex 5 - multimap vs unordered_multimap
    // create a multimap with pointers to Messages indexed by sender
    auto t1 = std::chrono::system_clock::now();

    std::multimap<std::string,const Message*> sender;

    for (const auto& m : mfile) {
        std::string s;
        if (find_from_addr(&m,s))
            sender.insert(std::make_pair(s,&m));
    }

    auto t2 = std::chrono::system_clock::now();

    std::cout << "Size of mail file: " << sender.size() << '\n';

    std::cout << "Task took\n"
              << '\t' << duration_cast<milliseconds>(t2 - t1).count()
              << " milliseconds\n"
              << '\t' << duration_cast<microseconds>(t2 - t1).count()
              << " microseconds\n";
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

