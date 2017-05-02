#include "../text_lib/std_lib_facilities.h"

int main()
{
    char alpha = 'a';

    for (int i = 'a'; i <= 'z'; ++i) {
        alpha = i;
        cout << alpha << '\t' << i << '\n';
    }

    cout << '\n';

    for (int i = 'A'; i <= 'Z'; ++i) {
        alpha = i;
        cout << alpha << '\t' << i << '\n';
    }

    cout << '\n';

    for (int i = '0'; i <= '9'; ++i) {
        alpha = i;
        cout << alpha << '\t' << i << '\n';
    }
}
