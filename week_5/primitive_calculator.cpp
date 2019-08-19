#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::vector;
vector<int> dynamic_sequence(int n);

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);

    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
        bool temp = ((n-1) % 9);
        bool temp2 = (n % 4) && !((n+1) % 6);
//        std::cout  << "n: " << n << " %9 ?:" << temp << '\n';
        if ( temp || temp2 ) {
            n /= 2;
        }else{
            n = n - 1;
        }
    } else {
      n = n - 1;
    }


  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
//  n= 96234;
//  n= 30;
  vector<int> sequence = dynamic_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}

vector<int> dynamic_sequence(int n) {
    std::vector<int> sequence;
    vector<int> num(n+1,-1);
    vector<size_t> previous;
    previous.push_back(0);
    previous.push_back(0);
    previous.push_back(1);
    previous.push_back(1);
    num[1] = num[2] = num [3] = 1;

    int temp;
    for(size_t i{4} ; i < num.size(); ++i){
        temp = num[i-1];

        previous.push_back(i-1);
        if (i % 2 == 0){
            if(num[i/2] < temp){
                temp = num[i/2];
                previous[i] = i/2;
            }
        }

        if (i % 3 == 0){
            if(num[i/3] < temp){
                temp = num[i/3];
              previous[i] = i/3;
            }
        }
        num[i] = temp + 1;
//        std::cout << " i: " << i << " n = " << num[i] << " | ";


    }
//    std::cout << "\nsize : previous = " << previous.size()<< "  =  " << previous[n]<<'\n';

          sequence.push_back(n);
          temp = previous[n];
    while(temp > 0){

        sequence.push_back(temp);
        temp = previous[temp];

    }




    reverse(sequence.begin(), sequence.end());
    return sequence;

}
