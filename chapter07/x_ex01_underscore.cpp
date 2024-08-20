#include "../text_lib/std_lib_facilities.h"

//------------------------------------------------------------------------------

class Variable {
    public:
        string name;
        double value;
};

vector<Variable> var_table;

double get_value(string s)
{
    for (const Variable& v : var_table)
        if (v.name == s) return v.value;
    error("get: undefined Variable ", s);
}

void set_value(string s, double d)
{
    for (Variable& v : var_table)
        if (v.name == s) {
            v.value = d;
            return;
        }
    error("set: undefined variable ", s);
}

bool is_declared(string var)
{
    for (const Variable& v : var_table)
        if (v.name == var) return true;
    return false;
}

double define_name(string var, double val)
{
    if (is_declared(var)) error(var, " declared twice");
    var_table.push_back(Variable{var, val});
    return val;
}

//------------------------------------------------------------------------------
/* GRAMMAR
 * =======
 * Calculation:
 *      Statement
 *      Print
 *      Quit
 *      Calculation Statement
 *
 * Statement:
 *      Declaration
 *      Expression
 *
 * Declaration:
 *      "let" Name "=" Expression
 */
//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    string name;
    Token(char ch) :kind{ch} { }
    Token(char ch, double val) :kind{ch}, value{val} { }
    Token(char ch, string n) :kind{ch}, name{n} { }
};

//------------------------------------------------------------------------------

class Token_stream {
    public:
        Token get();            // get a Token
        void putback(Token t);  // put a Token back
        void ignore(char c);    // discard characters up to and including 'c'
    private:
        bool full {false};      // is there a Token in the buffer?
        Token buffer = {'0'};           // where we store a 'putback' Token
};

//------------------------------------------------------------------------------

const char number = '8';
const char quit = 'q';
const char print = ';';
const char name = 'a';
const char let = 'L';

const string declkey = "let";
const string prompt = "> ";
const string result = "= ";

//------------------------------------------------------------------------------

void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;         // copy t to buffer
    full = true;        // buffer is now full
}

void Token_stream::ignore(char c)
    // c represents the kind of Token
{
    // first check buffer
    if (full && c == buffer.kind) {
        full = false;
        return;
    }
    full = false;

    char ch = 0;
    while (cin >> ch)
        if (ch == c) return;
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
        case print:
        case quit:
        case '=':
        case '(':
        case ')':
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
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
                return Token{number, val};
            }
        default:
            if (isalpha(ch) && ch == '_') {
                string s;
                s += ch;
                // exercise 01
                while (cin.get(ch) && (isalpha(ch) || isdigit(ch) ||
                            (ch == '_')))
                    s += ch;
                cin.putback(ch);
                if (s == declkey) return Token{let};
                return Token{name, s};
            }
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
    case number:            // we use '8' to represent a number
        return t.value;  // return the number's value
    case name:
        return get_value(t.name);
    case '-':
        return -primary();
    case '+':
        return primary();
    default:
        error("primary expected");
    }
}
//------------------------------------------------------------------------------

void clean_up_mess()
{
    ts.ignore(print);
}

//------------------------------------------------------------------------------

double declaration()
{
    Token t = ts.get();
    if (t.kind != name) error("name expected in declaration");
    string var_name = t.name;

    Token t2 = ts.get();
    if (t2.kind != '=') error("= missing in declaration of ", var_name);

    double d = expression();
    define_name(var_name, d);
    return d;
}

//------------------------------------------------------------------------------

double statement()
{
    Token t = ts.get();
    switch (t.kind) {
        case let:
            return declaration();
        default:
            ts.putback(t);
            return expression();
    }
}

//------------------------------------------------------------------------------

void calculate()
{
    while (cin)
    try {
        cout << prompt;
        Token t = ts.get();
        while (t.kind == print) t = ts.get();
        if (t.kind == quit) return;
        ts.putback(t);
        cout << result << statement() << '\n';
    }
    catch (exception& e) {
        cerr << e.what() << '\n';
        clean_up_mess();
    }
}

//------------------------------------------------------------------------------

int main()
try {
    define_name("pi", 3.1415926535);
    define_name("e", 2.7182818284);

    calculate();
    return 0;
}
catch (exception& e) {
    cerr << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "exception \n";
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
    double left = primary();
    Token t = ts.get();     // get the next token

    while(true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
            {    
                double d = primary();
                if (d == 0) error("divide by zero");
                left /= d; 
                t = ts.get();
                break;
            }
        case '%':
            {
                double d = primary();
                if (d == 0) error("%: divide by zero");
                left = fmod(left,d);
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
