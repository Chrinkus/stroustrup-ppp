#include<string>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool find_repeats(string s)
{
    sort(s.begin(), s.end());

    for (int i = 1; i < s.length(); ++i)
        if (s[i] == s[i - 1])
            return true;

    return false;
}

int main()
{
    vector<string> test_strings = {
        "abcdefghijklmnopqrstuvwxyz",
        "123456!@#$%^789&*()0",
        "<article>Jump!",

        "Chris Chrinkus",
        "fask;j.2347.[]",
        "a=b=c=d=e=f=g=h=i"
    };

    for (string t : test_strings)
        if (find_repeats(t))
            cout << "duplicates found.\n";
        else
            cout << "all unique.\n";

    return 0;
}
