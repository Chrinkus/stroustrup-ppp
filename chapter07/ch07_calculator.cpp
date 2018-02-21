//
// Stroustrup - Programming Principles & Practice
//
// Chapter 7 - Simple Calculator
//
// Drill - adds sqrt and pow funcitonality
// Ex 2 - allows underscores in variable names
// Ex 3 - provides constant variabls
// Ex 4 - moves Variable related functions to Symbol_table class
// Ex 5 - Token_stream reads \n as print
// Ex 6 - help page added (?)
// Ex 7 - help and quit commands expanded to strings
// Ex 8 - Grammar updated
// Ex 9 - Added sin and cos
//

/*
    The grammar for input is:

    Calculation:
        Statement
        Print
        Help
        Quit
        Calculation Statement

    Statemant:
        Declaration
        Expression

    Print:
        ;

    Quit:
        q

    Declaration:
        "let" Name "=" Expression

    Expression:
        Term
        Expression + Term
        Expression - Term

    Term:
        Secondary
        Term * Secondary
        Term / Secondary
        Term % Secondary

    Secondary:
        Primary "!" 
        "Sqrt (" Expression ")"
        "Pow (" Expression "," Expression ")"

    Primary:
        Number
        ( Expression )
        { Expression }
        - Primary
        + Primary
        Variable
        "sqrt"( Expression )
        "pow(" Expression "," narrow_cast<int>(Expression) ")"
        "sin"( Expression )
        "cos"( Expression )

    Number:
        floating-point-literal

    Input comes from cin through the Token_stream called ts.
*/

#include "../text_lib/std_lib_facilities.h"

// §7.6.1 Symbolic constants
const char number = '8';
const char quit = 'q';
const char print = ';';
const char name = 'a';
const char let = 'L';           // declaration token
const char help = '?';
const char c_sin = 's';
const char c_cos = 'c';

const string prompt = "> ";
const string result = "= ";
const string declkey = "let";   //declaration keywork

// drill
const char square_root = '@';
const char exponent = '^';
const string sqrtkey = "sqrt";
const string expkey = "pow";
const string sinkey = "sin";
const string coskey = "cos";
const string quitkey = "quit";
const string helpkey = "help";

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

class Token {
public:
    char kind;
    double value;
    string name;

    Token(char k) : kind{k}, value{0} { }
    Token(char k, double v) : kind{k}, value{v} { }
    Token(char k, string n) : kind{k}, value{0}, name{n} { }
};

class Token_stream {
public:
    Token get();                // get a Token
    void putback(Token t);      // put a token back
    void ignore(char c);        // discard characters up to and including a c
private:
    bool full { false };        // is there a Token in the buffer?
    Token buffer {'0'};         // here is where putback() stores a Token
};

void Token_stream::ignore(char c)
    // c represents the kind of Token
{
    // first look in buffer
    if (full && c == buffer.kind) {
        full = false;
        return;
    }
    full = false;

    // now search for input
    char ch = 0;
    while (cin >> ch)
        if (ch == c) return;
}

void Token_stream::putback(Token t)
{
    buffer = t;                 // copy t to buffer
    full = true;                // buffer is now full
};

Token Token_stream::get()
{
    if (full) {             // do we already have a Token?
        full = false;       // remove Token from buffer
        return buffer;
    }

    char ch;
    cin.get(ch);            // look for any char including whitespace

    while (isspace(ch) && ch != '\n') cin.get(ch);

    switch (ch) {
        case '\n':
            return Token{print};
        case print:
        case quit:
        case help:
        case '(':
        case ')':
        case '{':
        case '}':
        case '!':
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '=':
        case ',':
            return Token { ch };    // let each character represent itself
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            {
                cin.putback(ch);    // put digit back into input stream
                double val;
                cin >> val;         // read floating-point number
                return Token { number, val };  
            }
        default:
            if (isalpha(ch)) {
                string s;
                s += ch;
                while (cin.get(ch) &&
                        ((isalpha(ch) || isdigit(ch) || ch == '_')))
                    s += ch;
                cin.putback(ch);
                if (s == declkey) return Token{let};    // declaration keyword
                else if (s == sqrtkey) return Token{square_root};
                else if (s == expkey) return Token{exponent};
                else if (s == sinkey) return Token{c_sin};
                else if (s == coskey) return Token{c_cos};
                else if (s == quitkey) return Token{quit};
                else if (s == helpkey) return Token{help};
                else return Token{name, s};
            }
            error("Bad token");
    }
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

class Variable {
public:
    string name;
    double value;
    bool constant;
    Variable(string n, double v, bool c = false)
        : name{n}, value{v}, constant{c} { }
};

class Symbol_table {
    vector<Variable> var_table;
public:
    bool is_declared(string);
    double get_value(string);
    double set_value(string, double);
    double define_name(string, double, bool con = false);
};

bool Symbol_table::is_declared(string var)
    // is var already in var_table?
{
    for (const Variable& v : var_table)
        if (v.name == var) return true;
    return false;
}

double Symbol_table::get_value(string s)
    // return the value of the Variable named s
{
    for (const Variable& v : var_table)
        if (v.name == s) return v.value;
    error("get: undefined variable ", s);
}

double Symbol_table::set_value(string s, double d)
    // set the Variable named s to d
{
    for (Variable& v : var_table)
        if (v.name == s) {
            if (v.constant) error("Can't overwrite constant variable");
            v.value = d;
            return d;
        }
    error("set: undefined variable ", s);
}

double Symbol_table::define_name(string var, double val, bool con)
    // add {var,val,con} to var_table
{
    if (is_declared(var)) error(var, " declared twice");
    var_table.push_back(Variable{var,val,con});
    return val;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// globals(?)

Symbol_table st;            // allows Variable storage and retrieval

Token_stream ts;            // provides get() and putback()

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// additional calculator functions

double expression();        // forward declaration for primary to call

double calc_sqrt()
{
    char ch;
    if (cin.get(ch) && ch != '(') error("'(' expected");
    cin.putback(ch);
    double d = expression();
    if (d < 0) error("sqrt: negative val is imaginary");
    return sqrt(d);
}

double calc_pow()
{
    Token t = ts.get();
    if (t.kind != '(') error("'(' expected");
    double base = expression();
    t = ts.get();
    if (t.kind != ',') error("',' expected");
    int power = narrow_cast<int>(expression());
    t = ts.get();
    if (t.kind != ')') error("')' expected");
    return pow(base, power);
}

double calc_sin()
{
    char ch;
    if (cin.get(ch) && ch != '(') error("'(' expected");
    cin.putback(ch);
    double d = expression();
    if (d == 0 || d == 180) return 0;       // return true zero
    return sin(d*3.1415926535/180);
}

double calc_cos()
{
    char ch;
    if (cin.get(ch) && ch != '(') error("'(' expected");
    cin.putback(ch);
    double d = expression();
    if (d == 90 || d == 270) return 0;      // return 0 instead of 8.766e-11
    return cos(d*3.1415926535/180);
}

double handle_variable(Token& t)
{
    Token t2 = ts.get();
    if (t2.kind == '=')
        return st.set_value(t.name, expression());
    else {
        ts.putback(t2);
        return st.get_value(t.name);       // missing in text!
    }
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// input grammar functions

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
        case number: 
            return t.value;         // return the number's value
        case name:
            return handle_variable(t);
        case '-':
            return -primary();
        case '+':
            return primary();
        case square_root:
            return calc_sqrt();
        case exponent:
            return calc_pow();
        case c_sin:
            return calc_sin();
        case c_cos:
            return calc_cos();
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
        switch (t.kind) {
            case '!':
                if (left == 0) return 1;
                for (int i = left - 1; i > 0; --i) left *= i;
                t = ts.get();
                break;
            default:
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
            case '%':
                {
                    double d = secondary();
                    if (d == 0) error("%: divide by zero");
                    left = fmod(left, d);
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

double declaration()
    // assume we have seen "let"
    // handle: name = expression
    // declare a variable called "name" with the initial value "expression"
{
    Token t = ts.get();
    if (t.kind != name) error("name expected in declaration");
    string var_name = t.name;

    Token t2 = ts.get();
    if (t2.kind != '=') error("= missing in declaration of ", var_name);

    double d = expression();
    st.define_name(var_name, d);
    return d;
}

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

void print_help()
{
    cout << "Simple Calculator Manual\n"
         << "========================\n"
         << "This calculator program supports +, -, *, and / operations\n"
         << "Enter any form of compound statement followed by ';' for result\n"
         << "- ex: 4 + 1; (5-2)/{6*(8+14)}\n"
         << "The modulo operator % may be used on all numbers\n"
         << "An '!' placed after a value will calculate the factorial of it\n"
         << "- ex: 4! = 4 * 3 * 2 * 1\n"
         << "Square root and exponentiation are provided by 'sqrt' and 'pow'\n"
         << "- ex: sqrt(25) = 5, pow(5,2) = 25\n"
         << "Variable assignment is provided using the 'let' keyword:\n"
         << "- ex: let x = 37; x * 2 = 74; x = 4; x * 2 = 8\n\n";
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// expression evaluation loop
// §7.7 recovering from errors
void clean_up_mess()
{
    ts.ignore(print);
}

// §7.6.2 separate main's extra action
void calculate()                   
{
    while (cin)
        try {
            cout << prompt;
            Token t = ts.get();
            while (t.kind == print) t = ts.get();   // discard extra 'prints'
            if (t.kind == help) print_help();
            else if (t.kind == quit) return;
            else {
                ts.putback(t);
                cout << result << statement() << '\n';
            }
        }
        catch (exception& e) {
            cerr << e.what() << '\n';       // write error message to user
            clean_up_mess();
        }
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

int main()
try {
    st.define_name("pi", 3.1415926535, true);       // hardcoded constants
    st.define_name("e", 2.7182818284, true);      

    cout << "Simple Calculator (type ? for help)\n";

    calculate();
    return 0;
}
catch(exception& e) {
    cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Unknown exception\n";
    return 2;
}

/*
    Feb 18, 2018

    Returning to this after months of moving on I can see where I got lost. I
    had followed the text all along but when I neared the end of Chapter 7 I
    could not figure out why my code wouldn't work as the text suggests.

    In §7.8.2 we alter the Token_stream to accept names, specifically in the
    default clause of our switch statement. Then we add constructors to Token
    to allow for the creation of variable names. What we don't cover in the 
    text is modifying primary() to work with variable names.

    This was the cause of a major table_flipping moment for me and I hope that
    if someone reads this they can save themselves the frustration.
*/
