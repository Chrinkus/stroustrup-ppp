//
// Stroustrup - Programming Principles & Practice
//
// Chapter 25 Try This - Memory Fragmentation
//
// While I was initially trying to give meaning to Messages and Nodes I
// eventually just gave them enough members for close but inequal sizes. The
// output is saved below the catch clauses and has a few interesting jumps.
//

#include <iostream>
#include <stdexcept>
#include <string>
#include <chrono>
#include <vector>

struct Message {
    std::string content;
    std::string::size_type count;
    std::chrono::system_clock::time_point sent;
    Message(const std::string& s)
        : content{s}, count{s.size()},
        sent{std::chrono::system_clock::now()} { }
};

struct Node {
    const char* cs;
    int size;
    Node* next;
    Node* prev;
    Node(const std::string& s, Node* p = nullptr, Node* n = nullptr)
        : cs{s.c_str()}, size{int(s.size())}, prev{p}, next{n} { }
};

Message* get_input(std::istream& is)
{
    std::string buffer;
    std::getline(is, buffer);
    return new Message{buffer};
}

int main()
try {
    std::cout << "Message size: " << sizeof(Message) << '\n';   // 40
    std::cout << "Node size: " << sizeof(Node) << '\n';         // 32

    Node* nlist = new Node{"first node"};
    std::vector<Node*> vn;

    for (int i = 0; i < 7; ++i) {
        Message* p = get_input(std::cin);
        std::cout << "p  address: " << p << '\n';

        Node* n1 = new Node(p->content);

        delete p;

        Node* n2 = new Node("window pane");

        vn.push_back(n1);
        vn.push_back(n2);
    }

    for (auto n : vn) {
        std::cout << "Node address: " << n << '\n';
        delete n;
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
/*
Message size: 40
Node size: 32
sunday
p  address: 0x7ff089500000
monday
p  address: 0x7ff089600000
tuesday
p  address: 0x7ff0894026f0
wednesday
p  address: 0x7ff089600000
thursday
p  address: 0x7ff089600000
friday
p  address: 0x7ff089600000
saturday
p  address: 0x7ff089600000
Node address: 0x7ff089500030
Node address: 0x7ff089500050
Node address: 0x7ff089600030
Node address: 0x7ff089600050
Node address: 0x7ff089402720
Node address: 0x7ff089402740
Node address: 0x7ff089600070
Node address: 0x7ff089600090
Node address: 0x7ff0896000b0
Node address: 0x7ff0896000d0
Node address: 0x7ff089600170
Node address: 0x7ff089600190
Node address: 0x7ff0896001b0
Node address: 0x7ff0896001d0
*/
