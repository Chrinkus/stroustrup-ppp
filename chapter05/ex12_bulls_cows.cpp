#include "../text_lib/std_lib_facilities.h"

int main()
try {
    // Bulls and Cows
    vector<int> hidden = { 1, 2, 3, 5 };
    bool success = false;

    cout << "Let's play Bulls & Cows! Guess 4 integers w/o repeating:\n";
    while (!success) {
        vector<int> guess;

        int bulls = 0;
        int cows = 0;

        for (int val; guess.size() < 4; ) {
            cin >> val;
            if (!cin) error("Couldn't read integer from input\n");
            guess.push_back(val);
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
