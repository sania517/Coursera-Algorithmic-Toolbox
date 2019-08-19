#include <iostream>
#include <vector>

using std::vector;

void print(vector<vector<int>> &a);

int lcs2(vector<int> &a, vector<int> &b) {

    vector<vector<int>> arr_main(a.size()+1);
    for(size_t i {0}; i< arr_main.size(); ++i)
        arr_main[i].resize(b.size()+1,0);
//    print(arr_main);

    for(size_t i{1}; i < arr_main.size(); ++i){
        for (size_t y{1}; y < arr_main[i].size(); ++y){
            if (a[i-1] == b[y-1])
                arr_main[i][y] = arr_main[i-1][y-1]+1;
            else {
                arr_main[i][y] = arr_main[i][y-1] > arr_main[i-1][y] ? arr_main[i][y-1]:arr_main[i-1][y];
            }
        }
    }
//    print(arr_main);

    return arr_main[a.size()][b.size()];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }
//    vector<int> a {5,2,8,7,4};
//    vector<int> b {2, 7,8,3};

  std::cout << lcs2(a, b) << std::endl;
}

void print(vector<vector<int>> &a){
    for(size_t i{0}; i < a.size(); ++i){
        for (size_t y{0}; y < a[i].size(); ++y){
            std::cout << a[i][y] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
