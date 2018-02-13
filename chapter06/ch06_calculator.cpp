//
// Stroustrup - Programming Principles & Practice
//
// Chapter 6 - Calculator
//
// Try This #3 - Get final chapter 6 version of calculator to run
//
// ex 2 - Add the ability to use {} so that {(4+5)*6}/(3+4)}; is valid
//
// ex 3 - Add a factorial operator '!'. Make '!' bind tighter than '*' & '/'
//

#include "../text_lib/std_lib_facilities.h"

class Token {
public:
    char kind;
    double value;

    Token(char k) : kind{k}, value{0} { }
    Token(char k, double v) : kind{k}, value{v} { }
};

class Token_stream {
public:
    Token get();                // get a Token
    void putback(Token t);      // put a token back
private:
    bool full { false };        // is there a Token in the buffer?
    Token buffer {'0'};         // here is where putback() stores a Token
};

void Token_stream::putback(Token t)
{
    buffer = t;                 // copy t to buffer
    full = true;                // buffer is now full
};

Token Token_stream::get()
    // ex 2 - added '{' & '}'
    // ex 3 - added '!'
{
    if (full) {             // do we already have a Token?
        full = false;       // remove Token from buffer
        return buffer;
    }

    char ch;
    cin >> ch;              // note that >> skips whitespace

    switch (ch) {
        case ';':           // for "print"
        case 'q':           // for "quit"
        case '(': case ')': case '{': case '}': case '!':
        case '+': case '-': case '*': case '/':
            return Token { ch };
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            {
                cin.putback(ch);    // put digit back into input stream
                double val;
                cin >> val;
                return Token { '8', val };  // let '8' represent a number
            }
        default:
            error("Bad token");
    }
};

Token_stream ts;            // provides get() and putback()
double expression();        // forward declaration for primary to call

double primary()            // deal with numbers and parenthesis
    // ex 2 - added '{' case
{
    Token t = ts.get();
    switch (t.kind) {
        case '(':                   // handle '(' expression ')'
            {
                double d = expression();
                t = ts.get();
                if (t.kind != ')') error("')' expected");
                return d;
            }
        case '{':
            {
                double d = expression();
                t = ts.get();
                if (t.kind != '}') error("'}' expected");
                return d;
            }
        case '8':                   // we use '8' to represent a number
            return t.value;         // return the number's value
        default:
            error("primary expected");
    }
}

double secondary()          
    // ex 3 - Add a factorial operator '!'
{
    double left = primary();
    Token t = ts.get();

    while (true) {
        if (t.kind == '!') {
            if (left == 0)
                return 1;

            for (int i = left - 1; i > 0; --i)
                left *= i;

            t = ts.get();
        }
        else {
            ts.putback(t);
            return left;
        }
    }
}

double term()               // deal with * and /
{
    double left = secondary();
    Token t = ts.get();             // get next token from Token_stream

    while (true) {
        switch (t.kind) {
            case '*':
                left *= secondary();
                t = ts.get();
                break;
            case '/':
                {
                    double d = secondary();
                    if (d == 0) error("divide by zero");
                    left /= d;
                    t = ts.get();
                    break;
                }
            default:
                ts.putback(t);      // put t back into the Token_stream
                return left;
        }
    }
}

double expression()         // deal with + and -
{
    double left = term();           // read and evaluate a term
    Token t = ts.get();             // get next token from Token_stream

    while (true) {
        switch (t.kind) {
            case '+':
                left += term();     // evaluate term and add
                t = ts.get();
                break;
            case '-':
                left -= term();     // evaluate term and subtract
                t = ts.get();
                break;
            default:
                ts.putback(t);      // put t back into the token stream
                return left;
        }
    }
}

int main()
try {
    double val = 0;
    while (cin) {
        Token t = ts.get();

        if (t.kind == 'q') break;       // 'q' for "quit"
        if (t.kind == ';')              // ';' for "print now"
            cout << "=" << val << '\n';
        else
            ts.putback(t);
        val = expression();
    }
}
catch(exception& e) {
    cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Unknown exception\n";
    return 2;
}

