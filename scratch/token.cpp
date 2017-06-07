#include "../text_lib/std_lib_facilities.h"

class Token {
    public:
        char kind;
        double value;
        Token(char ch)
            :kind(ch), value(0) { }
        Token(char ch, double val)
            :kind(ch), value(val) { }
};

int main()
try {
    cout << "Define a Token: \n";
    Token t {' '};
    cin >> t.kind;

    if (cin)
        cin >> t.value;

    cout << "Token kind = " << t.kind << " Token value = " << t.value << '\n';

    return 0;
}
catch (exception& e) {
    cerr << "Error " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "I have no clue what just happened..\n";
    return 2;
}
