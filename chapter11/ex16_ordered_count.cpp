#include "../text_lib/std_lib_facilities.h"

int main()
try {
    cout << "Enter a file of numbers to order & count:\n";
    string iname;
    cin >> iname;
    ifstream ifs {iname};
    if (!ifs) error("could not read from file ", iname);

    vector<int> nums;
    for (int i; ifs >> i; )
        nums.push_back(i);

    sort(nums);

    cout << "num" << '\t' << "count\n";     // headers

    int count = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (i == 0) {       // first iteration

            cout << nums[i];
            count += 1;

        } else if (nums[i] == nums[i -1]) { // same as previous

            count += 1;

        } else {            // must be new number

            if (count > 1) cout << '\t' << count;
            count = 1;
            cout << '\n' << nums[i];
        }
    }
    if (count > 1) cout << '\t' << count;
    cout << '\n';
}
catch(exception& e) {
    cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Error!!\n";
    return 2;
}
