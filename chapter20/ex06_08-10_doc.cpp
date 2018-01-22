//
// Stroustrup - Programming Principles & Practice
//
// Chapter 20 Example Simple Text Editor
// 
// Chapter 20 Exercise 6
//
// Write a find and replace operation for Document

#include <iostream>
#include <stdexcept>
#include <vector>
#include <list>
#include <string>
#include <sstream>

using Line = std::vector<char>;         // a line is a vector of characters

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

class Text_iterator {
    std::list<Line>::iterator ln;
    Line::iterator pos;
public:
    // start the iterator at line ll's character position pp
    Text_iterator(std::list<Line>::iterator ll, Line::iterator pp)
        : ln{ll}, pos{pp} { }

    char& operator*() { return *pos; }
    Text_iterator& operator++();

    bool operator==(const Text_iterator& other) const
        { return ln == other.ln && pos == other.pos; }
    bool operator!=(const Text_iterator& other) const
        { return !(*this == other); }

    // added for find_replace
    Line& get_line() const { return *ln; }
    Line::iterator get_pos() const { return pos; }
};

Text_iterator& Text_iterator::operator++()
{
    ++pos;                              // proceed to next character
    if (pos == (*ln).end()) {
        ++ln;                           // proceed to next line
        pos = (*ln).begin();            // bad if ln==line.end(); so prevent
    }
    return *this;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

struct Document {
    std::list<Line> line;               // a document is a list of lines
    Document() { line.push_back(Line{}); }

    Text_iterator begin()               // first character of first line
        { return Text_iterator(line.begin(), (*line.begin()).begin()); }
    Text_iterator end()                 // one beyond last char of last line
    {
        auto last = line.end();
        --last;                         // we know document is not empty
        return Text_iterator(last, (*last).end());
    }
};

std::istream& operator>>(std::istream& is, Document& d)
{
    for (char ch; is.get(ch); ) {
        if (ch == '|') break;           // need some way to terminate std::cin
        d.line.back().push_back(ch);    // add the character
        if (ch == '\n')
            d.line.push_back(Line{});   // add another line
    }
    if (d.line.back().size()) d.line.push_back(Line{}); // add empty last line
    return is;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

void print(Document& d)
{
    for (auto p : d) std::cout << p;
}

void erase_line(Document& d, int n)
{
    if (n < 0 || d.line.size() - 1 <= n) return;
    auto p = d.line.begin();
    advance(p, n);
    d.line.erase(p);
}

template<typename Iter>         // requires Bidirectional_iterator<Iter>
void advance(Iter& p, int n)
{
    while (0 < n) { ++p; --n; }
    // try this - two way iterator
    while (n < 0) { --p; ++n; }
}

bool match(Text_iterator p, Text_iterator last, const std::string& s)
{
    for (auto q = s.begin(); q != s.end(); ++q) {
        if (*q != *p || p == last) return false;
        ++p;
    }
    return true;
}

Text_iterator find_txt(Text_iterator first, Text_iterator last,
        const std::string& s)
{
    if (s.size() == 0) return last;     // can't find an empty string
    char first_char = s[0];
    while (true) {
        auto p = std::find(first, last, first_char);
        if (p == last || match(p, last, s)) return p;
        first = ++p;                    // look at next character
    }
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// Ex 6 - implement find and replace
void find_replace(Text_iterator first, Text_iterator last,
        const std::string& fs, const std::string& rs)
{
    Text_iterator p = find_txt(first, last, fs);
    if (p == last) return;

    Line& li = p.get_line();
    
    // check to see if li has enough capacity for replacement
    const int diff = rs.size() - fs.size();
    if (diff > 0 && li.size() + diff > li.capacity())
        li.reserve(li.size() + diff);   // get enough memory for replacement

    p = find_txt(first, last, fs);      // find again in new allocation of li
    auto q = p.get_pos();

    q = li.erase(q, q + fs.size());

    for (auto rit = rs.crbegin(); rit != rs.crend(); ++rit)
        q = li.insert(q, *rit);
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// Ex 8 - character counter
int char_count(Document& d)
    // non-const, no cbegin defined
    // doesn't count space characters
{
    int count = 0;

    for (auto p : d)
        if (!isspace(p))
            ++count;

    return count;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// Ex 9 - word counters
int words_w(Document& d)
{
    int count = 0;
    bool word = false;
    for (auto a : d) {
        if (!word && isalpha(a))
            word = true;
        else if (word && isspace(a)) {
            word = false;
            ++count;
        }
    }

    return count;
}

int words_a(Document& d)
{
    int count = 0;
    bool word = false;
    for (auto a : d) {
        if (!word && isalpha(a))
            word = true;
        else if (word && !isalpha(a)) {
            word = false;
            ++count;
        }
    }
    return count;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// Ex 10 - custom word counter
int words_custom(Document& d, const std::string& ws)
{
    int count = 0;
    bool word = false;
    for (auto a : d) {
        if (!word && isalpha(a))
            word = true;
        else if (word)
            for (auto b : ws)
                if (a == b) {
                    word = false;
                    ++count;
                    break;
                }
    }

    return count;
}
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

int main()
try {
    // prove document works
    Document my_doc;
    std::istringstream iss {"Today is the greatest\nday I've ever known\ncan't wait for tomorrow\nI might not have that long\n"};
    iss >> my_doc;

    print(my_doc);

    // Ex 6 find & replace
    // replace with longer
    find_replace(my_doc.begin(), my_doc.end(), "greatest", "superbliest");
    // replace with shorter
    find_replace(my_doc.begin(), my_doc.end(), "tomorrow", "later");
    print(my_doc);

    // Ex 8 char count
    std::cout << "Characters in document: " << char_count(my_doc) << '\n';

    // Ex 9 word counters
    std::cout << "The number of whitespace separated words is: "
              << words_w(my_doc) << '\n';
    std::cout << "The number of separate alpha-words is: "
              << words_a(my_doc) << '\n';

    // Ex 10 custom word counter
    std::cout << "The number of custom separated words is: "
              << words_custom(my_doc, "\n") << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

