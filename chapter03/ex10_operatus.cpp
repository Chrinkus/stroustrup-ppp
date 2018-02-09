#include "../text_lib/std_lib_facilities.h"

// LOOKING BACK: Not sure why I didn't use char's for the operators..

int main()
{
    // Program
    cout << "Provide an operation and two values you'd like operated on:\n";
    string operatus;
    double val1;
    double val2;
    cin >> operatus >> val1 >> val2;

    double result = 0;
    if (operatus == "+" || operatus == "plus")
        result = val1 + val2;
    else if (operatus == "-" || operatus == "minus")
        result = val1 - val2;
    else if (operatus == "*" || operatus == "mul")
        result = val1 * val2;
    else if (operatus == "/" || operatus == "div")
        result = val1 / val2;

    cout << "The result of your operation is " << result << '\n';
}
