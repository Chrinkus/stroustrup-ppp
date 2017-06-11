#include "../text_lib/std_lib_facilities.h"

class Name_value {
    public:
        string name;
        int value;
        Name_value(string n, int v)
            :name(n), value(v) { }
};

int main()
{
    // Accept name value pairs, store them in vectors, print them in the end.
    
    vector<Name_value> record;

    bool end = false;
    bool repeat = false;

    while (!end) {
        cout << "Enter a name and a value:\n";
        string name;
        int score;
        cin >> name >> score;

        if (name == "NoName" && score == 0)
            end = true;
        else {
            for (Name_value n : record)
                if (n.name == name)
                    repeat = true;
            
            if (repeat) {
                cout << "Error: duplicate name\n";
                repeat = false;
            } else {
                record.push_back(Name_value{name, score});
            }
        }
    }

    cout << "RESULTS:\n";

    for (Name_value n : record)
        cout << n.name << '\t' << n.value << '\n';
}
