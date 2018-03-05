//
// Stroustrup - Programming Principles & Practice
//
// Chapter 23 Exercise 1 - More Mail File Fun
//
// Get the email file example to run and test it with a larger file of emails.
// Try to break the program with extra addresses, several messages with same
// address and/or subjects etc.
//
// Exercise 2 - Input Subject Search
//
// Add a multimap to hold subjects. Take keyboard input and print out every
// message with that input as its subject.
//
// Exercise 3 - Regex Update
// 
// Modify the chapter example to use regular expres-
// sions to find the subject and sender.
//
// Exercise 4 - Real Email
//
// Find a real email message file (containing real email messages)
// and modify example to extract subject lines from sender names given as
// input.
//

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <fstream>
#include <regex>
#include <map>

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
// ex 3

// if found, put sender's name in s
bool find_from_addr(const Message* m, std::string& s)
    // what to do with empty sender field? According to the RFC 2822 document
    // all messages MUST have a From: field and that field MUST contain the
    // address of the originator. I'll just stick to what the original version
    // did and return bool and fill the string. The caller can handle an empty
    // address.
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

    // create a multimap with pointers to Messages indexed by sender
    std::multimap<std::string,const Message*> sender;

    for (const auto& m : mfile) {
        std::string s;
        if (find_from_addr(&m,s))
            sender.insert(std::make_pair(s,&m));
    }

    // ex 2 - add a multimap with pointers to Messages indexed by subject
    std::multimap<std::string,const Message*> subject;

    for (const auto& m : mfile) {
        std::string s = find_subject(&m);
        if (s.size())
            subject.insert(std::make_pair(s,&m));
    }

    // ex 4 - using a real email file, extract subject lines from sender names
    // taken as input
    while (true) {
        std::cout << "What sender do you want to find subjects from?\n";
        std::string s;
        std::getline(std::cin,s);

        if (s == "quit") return 0;

        auto pp = sender.equal_range(s);
        for (auto p = pp.first; p != pp.second; ++p)
            std::cout << '\t' << find_subject(p->second) << '\n';
    }
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

