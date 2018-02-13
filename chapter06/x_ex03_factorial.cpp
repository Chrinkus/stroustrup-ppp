//
// This is example code from Chapter 6.6 "Trying the first version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

#include "../text_lib/std_lib_facilities.h"

// ATTENTION: This initial attempt may not work as expected. The actual
// solution to ex 3 is found in ch06_calculator.cpp.

//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }    
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------
/*
Token get_token()    // read a token from cin
{
    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
 //not yet   case ';':    // for "print"
 //not yet   case 'q':    // for "quit"
    case '(': case ')': case '+': case '-': case '*': case '/': 
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        {    
            cin.putback(ch);         // put digit back into the input stream
            double val;
            cin >> val;              // read a floating-point number
            return Token('8',val);   // let '8' represent "a number"
        }
    default:
        error("Bad token");
    }
}
*/
//------------------------------------------------------------------------------

class Token_stream {
    public:
        Token get();            // get a Token
        void putback(Token t);  // put a Token back
    private:
        bool full {false};      // is there a Token in the buffer?
        Token buffer = {'0'};           // where we store a 'putback' Token
};

void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;         // copy t to buffer
    full = true;        // buffer is now full
}

Token Token_stream::get()
{
    if (full) {
        full = false;
        return buffer;
    }
    char ch;
    cin >> ch;

    switch (ch) {
        case ';':       // for "print"
        case 'q':       // for "quit"
        case '!':
        case '(':
        case ')':
        case '{':
        case '}':
        case '+':
        case '-':
        case '*':
        case '/':
            return Token{ch};   // let each character represent itself
        case '.':
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            {
                cin.putback(ch);
                double val;
                cin >> val;
                return Token{'8', val};
            }
        default:
            error("Bad Token");
    }
}

//------------------------------------------------------------------------------

Token_stream ts;      // provides get() and putback()

//------------------------------------------------------------------------------

double expression();  // read and evaluate a Expression

//------------------------------------------------------------------------------

double term();        // read and evaluate a Term

//------------------------------------------------------------------------------

double secondary();

//------------------------------------------------------------------------------

double primary()     // read and evaluate a Primary
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
        {    
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
    case '{':
        {
            double x = expression();
            t = ts.get();
            if (t.kind != '}') error("'}' expected");
            return x;
        }
    case '8':            // we use '8' to represent a number
        return t.value;  // return the number's value
    default:
        error("primary expected");
    }
}
//------------------------------------------------------------------------------

int main()
try {
    while (cin)
        cout << expression() << '\n';
    keep_window_open("~0");
}
catch (exception& e) {
    cerr << e.what() << endl;
    keep_window_open ("~1");
    return 1;
}
catch (...) {
    cerr << "exception \n";
    keep_window_open ("~2");
    return 2;
}

//------------------------------------------------------------------------------

double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token
    while(true) {    
        switch(t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

double term()
{
    double left = secondary();
    Token t = ts.get();     // get the next token

    while(true) {
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
            ts.putback(t);
            return left;
        }
    }
}

//------------------------------------------------------------------------------

double secondary()
{
    double left = primary();
    Token t = ts.get();

    while(true) {
        if (t.kind == '!') {
            if (left == 0)
                return 1;

            for (int i = left - 1; i > 0; --i)
                left *= i;
            t = ts.get();
        } else {
            ts.putback(t);
            return left;
        }
    }
}

//------------------------------------------------------------------------------
/*
Grammar 
=======
Expression:
    Term
    Expression "+" Term
    Expression "-" Term
Term:
    Secondary
    Term "*" Secondary
    Term "/" Secondary
Secondary:
    Primary
    Number "!"
Primary:
    Number
    "(" Expression ")"
Number:
    floating-point-literal
*/
