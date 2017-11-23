#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector< vector<int> > v;

    for (int k = 0; k < 4; ++k)
        for (int l = 0; l < 4; ++l)
            v[k].push_back(9);


    for (int i = 0; i < v.size(); ++i)
        for (int j = 0; j < v[i].size(); ++j)
            cout << i << '\t' << j << '\t' << v[i][j] << '\n';
}

