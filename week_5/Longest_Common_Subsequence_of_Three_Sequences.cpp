#include <iostream>
#include <vector>

using std::vector;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {

    vector<vector<vector<int>>> arr_kub(a.size()+1);

    for(size_t i {0}; i< arr_kub.size(); ++i){
        arr_kub[i].resize(b.size()+1);
        for (size_t y {0}; y< arr_kub[i].size(); ++y){
            arr_kub[i][y].resize(c.size()+1, 0);
        }
    }
//    std:: cout << " SIZE 1: " << arr_kub.size() << " SIZE 2: " << arr_kub[a.size()].size() << " SIZE 3: " << arr_kub[a.size()][b.size()].size();

    for(size_t i {1}; i< arr_kub.size(); ++i){
        for (size_t y {1}; y< arr_kub[i].size(); ++y){
            for (size_t z {1}; z< arr_kub[i][y].size(); ++z){
                if(a[i-1] == b[y-1] && a[i-1] == c[z-1]){
                    arr_kub[i][y][z] = arr_kub[i-1][y-1][z-1] +1;
                } else {
                    arr_kub[i][y][z] = arr_kub[i][y][z-1] > arr_kub[i][y-1][z] ?
                                arr_kub[i][y][z-1] : arr_kub[i][y-1][z];
                    arr_kub[i][y][z] = arr_kub[i][y][z]   > arr_kub[i-1][y][z] ?
                                arr_kub[i][y][z]   : arr_kub[i-1][y][z];
                }
            }

        }
    }

//    vector<vector<int>> arr_main(a.size()+1);
//    for(size_t i {0}; i< arr_main.size(); ++i)
//        arr_main[i].resize(b.size()+1,0);

//    for(size_t i{1}; i < arr_main.size(); ++i){
//        for (size_t y{1}; y < arr_main[i].size(); ++y){
//            if (a[i-1] == b[y-1])
//                arr_main[i][y] = arr_main[i-1][y-1]+1;
//            else {
//                arr_main[i][y] = arr_main[i][y-1] > arr_main[i-1][y] ? arr_main[i][y-1]:arr_main[i-1][y];
//            }
//        }
//    }

    return arr_kub[a.size()][b.size()][c.size()];

}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
//      vector<int> a {8,3,2, 1,7};
//      vector<int> b {8,2,1,3,8,10,7};
//      vector<int> c {6,8,3,1,4,7};
  std::cout << lcs3(a, b, c) << std::endl;
}
