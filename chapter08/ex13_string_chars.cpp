#include "../text_lib/std_lib_facilities.h"

vector<int> get_lengths(const vector<string>& s)
{
    vector<int> lengths;

    for (string str : s)
        lengths.push_back(str.size());

    return lengths;
}

string get_smallest(const vector<string>& s)
{
    string small = s[0];

    for (string str : s)
        if (str.size() < small.size()) small = str;

    return small;
}

string get_largest(const vector<string>& s)
{
    string large = s[0];

    for (string str : s)
        if (str.size() > large.size()) large = str;

    return large;
}

int main()
{
    vector<string> games = { "Crackdown", "Halo", "Gears of War", "Forza",
                             "Tomb Raider", "Bioshock", "Fallout" };

    vector<int> lengths = get_lengths(games);

    cout << "List of Games\n"
         << "=============\n";

    for (int i = 0; i < games.size(); ++i)
        cout << games[i] << " " << lengths[i] << '\n';

    cout << '\n'
         << "Smallest: " << get_smallest(games) << '\n'
         << "Largest: " << get_largest(games) << '\n';

    sort(games);

    cout << "First: " << games[0] << '\n'
         << "Last: " << games[games.size() - 1] << '\n';
}
