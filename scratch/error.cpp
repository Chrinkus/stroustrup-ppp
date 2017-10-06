#include<iostream>
#include<string>

using namespace std;

int main()
try {
    cout << "Try entering something..";
    string input;
    cin >> input;

    if (input != "safe") throw runtime_error("Totally not safe");

    cout << "Must have been safe!\n";
}
catch(exception& e) {
    cout << "Error: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cout << "Exception: something unexpected went wrong\n";
    return 2;
}
