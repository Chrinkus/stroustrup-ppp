//
// Stroustrup - Programming Principles & Practice
//
// Chapter 19 Exercise 12
//
// Define a File_handle class that opens a file in its constructor and closes
// it in its destructor.
//

#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>

class File_handle {
    std::fstream fs;
public:
    File_handle(const std::string& s)
        : fs{s}
    {
        std::cout << "File opened\n";
    }

    ~File_handle()
    {
        fs.close();
        std::cout << "File closed\n";
    }

    void readFile(std::string& s)
    {
        for (std::string t; fs >> t; )
            s += t + ' ';
    }
};

int main()
try {
    File_handle test {"./test.txt"};
    std::string s;
    test.readFile(s);

    std::cout << s << '\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

