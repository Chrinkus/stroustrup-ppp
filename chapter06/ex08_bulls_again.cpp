#include "../text_lib/std_lib_facilities.h"

int main()
try {
    // Bulls and Cows
    vector<char> hidden = { 'c', 'j', 'o', 'b' };
    bool success = false;

    cout << "Let's play Bulls & Cows! Guess 4 characters w/o repeating:\n";
    while (!success) {
        vector<char> guess;

        int bulls = 0;
        int cows = 0;

        for (char ch; guess.size() < 4; ) {
            cin >> ch;
            if (!cin) error("Couldn't read character from input\n");
            guess.push_back(ch);
        }

        for (int i = 0; i < guess.size(); ++i)
            for (int j = 0; j < hidden.size(); ++j)
                if (guess[i] == hidden[j]) {
                    if (i == j)
                        ++bulls;
                    else
                        ++cows;
                }

        cout << bulls << " bulls, " << cows << " cows.\n";

        if (bulls == 4) success = true;
    }
    cout << "Success!!\n";
    
    return 0;
}
catch(exception& e) {
    cerr << "error: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Unknown exception!\n";
    return 2;
}

