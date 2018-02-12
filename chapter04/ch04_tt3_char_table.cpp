#include "../text_lib/std_lib_facilities.h"

int main()
{
    int i = 0;
    int unicode_val = 'a';
    
    char alpha = 'a';

    while (i<26) {
        alpha = unicode_val + i;
        cout << alpha << '\t' << (unicode_val + i) << '\n';
        ++i;
    }
}
