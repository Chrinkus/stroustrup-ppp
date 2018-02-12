#include "../text_lib/std_lib_facilities.h"

int main()
{
    vector<string> words;
    for (string word; cin >> word; )
        words.push_back(word);

    vector<string> dislikes = { "php", "python", "C#" };

    for (string word : words) {
        bool bad = false;

        for (string awful : dislikes) {
            if (word == awful)
                bad = true;
        }

        if (bad)
            cout << "BLEEP!" << '\n';
        else
            cout << word << '\n';
    }
}
