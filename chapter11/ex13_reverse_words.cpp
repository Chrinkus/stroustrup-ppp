#include "../text_lib/std_lib_facilities.h"

int main()
{
    cout << "Enter a file to reverse the words of:\n";
    string iname;
    cin >> iname;
    ifstream ifs {iname};
    if (!ifs) error("could not read from file ", iname);

    cout << "Enter a destination file for output:\n";
    string oname;
    cin >> oname;
    ofstream ofs {oname};
    if (!ofs) error("could not write to file ", oname);

    vector<string> v;
    for (string line; getline(ifs, line); )
        v.push_back(line);

    for (int i = v.size() - 1; i >= 0; --i) {
        vector<string> w;
        istringstream ss {v[i]};

        for (string s; ss >> s; )
            w.push_back(s);

        for (int j = w.size() - 1; j >= 0; --j)
            ofs << w[j] << ' ';

        ofs << '\n';
    }

}
