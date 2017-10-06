/*
#include<string>
#include<vector>
#include<iostream>
#include<fstream>

using namespace std;
*/
#include "../text_lib/std_lib_facilities.h"

struct Reading {
    int hour;
    double temperature;
};

/*
void stream_states()
{
    int i = 0;
    cin >> i;
    if (!cin) {     // we get here if the input operation failed
        if (cin.bad()) error("cin is bad");  // stream corrupted!!
        if (cin.eof()) {
            // no more input (end of file)
            // this is how we want the stream to end
        }
        if (cin.fail()) {   // stream encountered something unexpected
            cin.clear();    // make ready for more input
            // somehow recover
        }
    }
}

void fill_vector(istream& ist, vector<int>& v, char terminator)
    // read integers from ist into v until we reach eof() or terminator
{
    for (int i; ist >> i; ) v.push_back(i);
    if (ist.eof()) return;              // fine: we found the end of file

    if (ist.bad()) error("ist is bad"); // stream corrupted: lets get out!
    if (ist.fail()) {   // clean up the mess as best as we can and report prob
        ist.clear();    // clear stream state,
                        // so that we can look for terminator
        char c;
        ist >> c;       // read a character, hopefully terminator
        if (c != terminator) {              // unexpected character
            ist.unget();                    // put that character back
            ist.clear(ios_base::failbit);   // set the state to fail()
        }
    }
}
*/

int main()
try {
    cout << "Please enter input file name: ";
    string iname;
    cin >> iname;
    ifstream ist {iname};
    //if (!ist) error("can't open iutput file", iname);

    cout << "Please enter name of output file: ";
    string oname;
    cin >> oname;
    ofstream ost {oname};
    //if (!ost) error("can't open output file", oname);
    
    vector<Reading> temps;
    int hour;
    double temperature;
    while (ist >> hour >> temperature) {
        //if (hour < 0 || 23 < hour) error("hour out of range");
        temps.push_back(Reading{hour, temperature});
    }

    for (int i=0; i<temps.size(); ++i)
        ost << '(' << temps[i].hour << ','
            << temps[i].temperature << ")\n";
}
