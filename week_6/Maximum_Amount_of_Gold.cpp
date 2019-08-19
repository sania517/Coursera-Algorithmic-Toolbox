#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {

    vector<vector<size_t>> arr(W+1);
    for(size_t i{0}; i< arr.size(); ++i)
        arr[i].resize(w.size()+1,0);

    for(size_t y{1}; y < arr[0].size(); ++y){
        for(size_t i{1}; i < arr.size(); ++i){
            if (i < w[y-1]){
                arr[i][y] = arr[i][y-1];
                continue;
            }
            arr[i][y] = arr[i][y-1] >= (arr[i-w[y-1]][y-1] + w[y-1]) ?  arr[i][y-1] : (arr[i-w[y-1]][y-1] + w[y-1]);
        }
    }

    return arr.back().back();



}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
//  W = 10;
//  vector<int> w {1,4,8};
  std::cout << optimal_weight(W, w) << '\n';
}
