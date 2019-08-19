#include <iostream>
#include <vector>

using std::vector;

int partition3(vector<int> &A) {

    int sum{0};
    for(auto var : A)
        sum += var;
    if(sum % 3 || A.size() < 3 )
        return 0;
    int temp{sum/3};

    vector<vector<size_t>> arr(sum+1);
    for(size_t i{0}; i< arr.size(); ++i)
        arr[i].resize(A.size()+1,0);

    for(size_t y{1}; y < arr[0].size(); ++y){
        for(size_t i{1}; i < arr.size(); ++i){
            if (i < A[y-1]){
                arr[i][y] = arr[i][y-1];
                continue;
            }
            arr[i][y] = arr[i][y-1] >= (arr[i-A[y-1]][y-1] + A[y-1]) ?  arr[i][y-1] : (arr[i-A[y-1]][y-1] + A[y-1]);
        }
    }

    if ( (!(arr[temp].back() % temp)) && (!(arr[temp*2].back() % temp*2)) && (!(arr[temp*3].back() % temp*3)))
        return 1;
    else
        return 0;


}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
//  vector<int> A {1, 2, 3, 4, 5, 5, 7, 7, 8, 10, 12, 19, 25};
  std::cout << partition3(A) << '\n';
}

