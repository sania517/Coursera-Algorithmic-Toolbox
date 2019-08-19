#include <iostream>
#include <vector>

int get_change(const size_t size) {

    if (size <= 0)
        return 0;

    std::vector<int> coins = {1,3,4};
    std::vector<int> arr2(size, 0);
    for (size_t i{0} ; i < size; ++i){
        int temp_min {-1};

        //---------
        for (size_t q{0}; q< coins.size(); ++q){
           int temp_index = i - coins[q];
           if (temp_index == -1){
               temp_min = 0;
           }
           if (temp_index < 0)
               continue;

            if (temp_min < 0){

                temp_min = arr2[temp_index];
                continue;
            }
            if (arr2[temp_index] < temp_min)
                temp_min = arr2[temp_index];
        }
        //--------------
        if (temp_min == -1){
            arr2[i] = i+1;
            continue;
        }

        arr2[i] = temp_min + 1;
    }
    return arr2.back();
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
