#include "../text_lib/std_lib_facilities.h"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

const char number = '8';
const char quit = 'q';
const char print = ';';
const char name = 'a';
const char let = 'L';

const string declkey = "let";
const string prompt = "> ";
const string result = "= ";

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

struct Variable {
    string name;
    double value;
    Variable(string n, double v) :name{n}, value{v} { }
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

class Symbol_table {
    private:
        vector<Variable> var_table;
        bool is_declared(string var);
    public:
        double get_value(string);
        void set_value(string, double);
        double define_name(string, double);
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

double Symbol_table::get_value(string s)
{
    for (const Variable& v : var_table)
        if (v.name == s) return v.value;
    error("get: undefined variable ", s);
}

void Symbol_table::set_value(string s, double d)
{
    for (Variable& v : var_table)
        if (v.name == s)
            v.value = d;
    error("set: undefined variable ", s);
}

bool Symbol_table::is_declared(string var)
{
    for (const Variable& v : var_table)
        if (v.name == var) return true;
    return false;
}

double Symbol_table::define_name(string var, double val)
{
    if (is_declared(var)) error(var, " declared twice");
    var_table.push_back(Variable(var, val));
    return val;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

Symbol_table sym;           // still a global

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

struct Token {
    char kind;
    double value;
    string name;
    Token(char ch) :kind{ch} { }
    Token(char ch, double val) :kind{ch}, value{val} { }
    Token(char ch, string n) :kind{ch}, name{n} { }
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

class Token_stream {
    private:
        bool full;
        Token buffer;
    public:
        Token_stream() :full(0), buffer(0) { }
        
        Token get();
        void putback(Token);
        void ignore(char);
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

void Token_stream::putback(Token t)
{
    if (full) error("putback() into full buffer");
    buffer = t;
    full = true;
}

void Token_stream::ignore(char c)
{
    if (full && c == buffer.kind) {
        full = false;
        return;
    }
    full = false;

    char ch;
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

    switch(ch) {
        case '(':
        case ')':
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '=':
        case print:
        case quit:
            return Token{ch};
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            {
                cin.putback(ch);
                double val;
                cin >> val;
                return Token{number, val};
            }
        default:
            if (isalpha(ch)) {
                string s;
                s += ch;
                while (cin.get(ch) && (isalpha(ch) || isdigit(ch)))
                    s += ch;
                cin.putback(ch);
                if (s == declkey) return Token{let};
                return Token{name, s};
            }
            error("bad Token");
    }
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

double expression(Token_stream&);

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

double primary(Token_stream& ts)
{
    Token t = ts.get();
    switch (t.kind) {
        case '(':
        {
            double d = expression(ts);
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
        case number:
            return t.value;
        case name:
            return sym.get_value(t.name);
        case '-':
            return - primary(ts);
        case '+':
            return primary(ts);
        default:
            error("primary expected");
    }
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

double declaration(Token_stream& ts)
{
    Token t = ts.get();
    if (t.kind != name) error("name expected in declaration");
    string var_name = t.name;

    Token t2 = ts.get();
    if (t2.kind != '=') error("= missing in declaration of ", var_name);

    double d = expression(ts);
    sym.define_name(var_name, d);
    return d;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

double statement(Token_stream& ts)
{
    Token t = ts.get();
    switch (t.kind) {
        case let:
            return declaration(ts);
        default:
            ts.putback(t);
            return expression(ts);
    }
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

void calculate(Token_stream& ts)
{
    while (cin)
    try {
        cout << prompt;
        Token t = ts.get();
        while (t.kind == print) t = ts.get();
        if (t.kind == quit) return;
        ts.putback(t);
        cout << result << statement(ts) << '\n';
    }
    catch (exception& e) {
        cerr << e.what() << '\n';
        ts.ignore(print);
    }
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

int main()
try {
    Token_stream ts;

    sym.define_name("pi", 3.1415926535);
    sym.define_name("e", 2.7182818284);

    calculate(ts);
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

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

double term(Token_stream& ts)
{
    double left = primary(ts);
    Token t = ts.get();

    while (true)
        switch (t.kind) {
            case '*':
                left *= primary(ts);
                t = ts.get();
                break;
            case '/':
                {
                    double d = primary(ts);
                    if (d == 0) error("divide by zero");
                    left /= d;
                    t = ts.get();
                    break;
                }
            case '%':
                {
                    double d = primary(ts);
                    if (d == 0) error("%: divide by zero");
                    left = fmod(left, d);
                    t = ts.get();
                    break;
                }
            default:
                ts.putback(t);
                return left;
        }
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

double expression(Token_stream& ts)
{
    double left = term(ts);
    Token t = ts.get();
    while (true)
        switch(t.kind) {
            case '+':
                left += term(ts);
                t = ts.get();
                break;
            case '-':
                left -= term(ts);
                t = ts.get();
                break;
            default:
                ts.putback(t);
                return left;
        }
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
