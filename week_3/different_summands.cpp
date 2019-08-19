#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here

      for (int i{0};(i+1) <= n;++i){

              summands.push_back(i+1);
              n = n - i -1;
      }
      if(n!=0){
          summands[summands.size()-1] +=n;
      }



  //write your code here

  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
