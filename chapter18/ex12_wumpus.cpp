//
// Stroustrup - Programming Principles & Practice
//
// Chapter 18 Exercise 12
//
// Implement a version of the game "Hunt the Wumpus"
//

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <map>
#include <sstream>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

class Player {
    int r;      // current room
    int a;      // arrows left
public:
    explicit Player(int room) : r{room}, a{5} { }

    int room() const { return r; }
    bool has_arrow() const { return a > 0; }

    void move(int newRoom) { r = newRoom; }
    void shoot() { --a; }
    void found_arrow() { ++a; }
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

class Cave {
    std::map<int, std::vector<int>> rooms;
public:
    Cave()
    {
        rooms[1] = std::vector<int> {2, 5, 8};
        rooms[2] = std::vector<int> {1, 3, 10};
        rooms[3] = std::vector<int> {2, 4, 12};
        rooms[4] = std::vector<int> {3, 5, 14};
        rooms[5] = std::vector<int> {1, 4, 6};
        rooms[6] = std::vector<int> {5, 7, 15};
        rooms[7] = std::vector<int> {6, 8, 17};
        rooms[8] = std::vector<int> {1, 7, 9};
        rooms[9] = std::vector<int> {8, 10, 18};
        rooms[10] = std::vector<int> {2, 9, 11};
        rooms[11] = std::vector<int> {10, 12, 19};
        rooms[12] = std::vector<int> {3, 11, 13};
        rooms[13] = std::vector<int> {12, 14, 20};
        rooms[14] = std::vector<int> {4, 13, 15};
        rooms[15] = std::vector<int> {6, 14, 16};
        rooms[16] = std::vector<int> {15, 17, 20};
        rooms[17] = std::vector<int> {7, 16, 18};
        rooms[18] = std::vector<int> {9, 17, 19};
        rooms[19] = std::vector<int> {11, 18, 20};
        rooms[20] = std::vector<int> {13, 16, 19};
    }

    const std::vector<int>& get_adjacents(int r) { return rooms[r]; }
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

class Game {
    Player p;
    Cave c;

public:
    Game() : p{1}, c{} { }

    void start();
    void loop();
    void get_message();
    void process_input(const std::string&);
    void shoot(int);

    void debug() const;
};

void Game::start()
{
    std::cout << "Are you ready to Hunt the Wumpus?!\n"
              << "Enter 'yes' or 'no':\n";

    std::string input;

    while (std::cin >> input) {
        if (input == "no") return;
        if (input == "yes") break;
    }

    return loop();
}

void Game::loop()
{
    get_message();
    std::string input;
    std::cin >> input;
}

void Game::get_message()
{
    const std::vector<int>& adj = c.get_adjacents(p.room());

    std::cout << "You are in room " << p.room()
              << "; there are tunnels to rooms "
              << adj[0] << ", " << adj[1] << " & " << adj[2] << ";\n"
              << "(m)ove or (s)hoot?\n";
}

void Game::process_input(const std::string& s)
{
    std::istringstream iss {s};
    char ch;
    iss >> ch;

    switch(ch) {
        case 'm':
            int n;
            iss >> n;
            if (c.is_adjacent(p.room(), n)) p.move(n);
            break;
        case 's':
            int r;
            iss >> r;
            if (c.is_adjacent(p.room(), r) && p.has_arrow()) shoot(r);
            break;
        default:
            // invalid input
            break;
    }

}

void Game::shoot(int r)
    // check if wumpus is in r
    // decrement player arrows
{

}

void Game::debug() const
{
    /*
    for (auto& a : c.rooms)
        std::cout << a.first << '\n';
    std::cout << '\n';
    */
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

int main()
try {
    Game game;

    game.start();
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

