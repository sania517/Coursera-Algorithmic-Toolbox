#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    stops.push_back(dist);
    int gone{0};
    int count_stop{0};
    int temp_start_index{0};
    while (dist > 0){

        if (dist <= tank)
            break;

        int temp_distance{0};
        for (int i{temp_start_index}; i < stops.size(); ++i){
            if(stops[i] - gone <= tank)
                temp_distance = stops[i]- gone;
            else {
                if (temp_distance == 0)
                    return -1;
                temp_start_index = i;
                gone = gone + temp_distance;
//                ++count_stop;
                break;
            }
        }
        ++count_stop;
        dist = dist-temp_distance;


    }




    // write your code here
    return count_stop;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
