#include "../text_lib/std_lib_facilities.h"

class Name_pairs {
    public:
        void read_names();
        void read_ages();
        void sort_pairs();

        string get_name(int i) { return names[i]; }
        int get_age(int i) { return ages[i]; }
        int get_size() { return names.size(); }
    private:
        vector<string> names;
        vector<double> ages;
};

void Name_pairs::read_names()
{
    cout << "Enter some names. Type 'DONE' when you are finished.\n";

    for (string n; cin >> n; ) {
        if (n == "DONE") return;
        names.push_back(n);
    }
}

void Name_pairs::read_ages()
{
    cout << "For each name, enter the person's age.\n";

    for (string n : names) {
        cout << n << " => ";
        int a;
        cin >> a;
        ages.push_back(a);
    }
}

void Name_pairs::sort_pairs()
{
    vector<string> temp_names = names;
    vector<double> sort_ages;
    sort(names);

    for (string n : names)
        for (int i = 0; i < temp_names.size(); ++i)
            if (temp_names[i] == n)
                sort_ages.push_back(ages[i]);

    ages = sort_ages;
}

ostream& operator<<(ostream& os, Name_pairs np)
{
    for (int i = 0; i < np.get_size(); ++i)
        os << np.get_name(i) << " is " << np.get_age(i) << " years old.\n";

    return os;
}

int main()
try {
    Name_pairs np;
    np.read_names();
    np.read_ages();
    np.sort_pairs();
    cout << np << '\n';
    return 0;
}
catch(exception& e) {
    cerr << e.what();
}
catch(...) {
    cerr << "unknown error\n";
}
