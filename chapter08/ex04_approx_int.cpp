#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

// pass by const reference
void print(string label, const vector<int>& v){
    cout << label << endl;
    for(int x: v){
        cout << x << " ";
    }
    cout << endl;

}

// keep generating integers until we have an overflow
int fibonacci(int x, int y, vector<int>& v){
    v.push_back(x);
    v.push_back(y);
    while(y > x){
        int z = x + y;
        v.push_back(z);
        x = y;
        y = z;
    }
    return x;
}

int main(){
    vector<int> v;
    cout << fibonacci(1, 2, v);
}
