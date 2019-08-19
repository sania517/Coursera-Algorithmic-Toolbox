#include <iostream>

int get_change(int m) {

    int count_coin{0};
    int coins[]{10,5,1};
        int temp{0};

        for(int i{0}; i<3; ++i){
           temp =  m/coins[i];
           if(temp){
               count_coin += temp;
               m = m % coins[i];
           }else if(m == 0)
               break;

        }


    //write your code here
  return count_coin;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
