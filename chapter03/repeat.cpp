#include "../text_lib/std_lib_facilities.h"

int main()
{
    int number_of_words = 0;
    string previous = " ";
    string current;
    while (cin>>current) {
        if (previous == current)
            cout << "repeated word: " << current << '\n';
        previous = current;
    }
}
