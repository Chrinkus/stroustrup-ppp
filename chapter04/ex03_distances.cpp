#include "../text_lib/std_lib_facilities.h"

int main()
{
    vector<double> distances;

    double distance;
    double mean;
    double smallest = 0;
    double largest = 0;
    double total_distance = 0;

    while(cin >> distance) {
        distances.push_back(distance);

        if (smallest == 0 && largest == 0) {

            smallest = distance;
            largest = distance;

        } else {

            if (distance < smallest)
                smallest = distance;
            else if (distance > largest)
                largest = distance;

        }

        total_distance += distance;
    }

    mean = total_distance / distances.size();

    cout << "The smallest distance between cities was: " << smallest << '\n'
         << "The largest distance between cities was: " << largest << '\n'
         << "The total distance travelled was: " << total_distance << '\n'
         << "The mean distance between citeis was: " << mean << '\n';
}
