#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
//  if (left == right) return -1;
//  if (left + 1 == right) return a[left];
  //write your code here

    if(left+1 == right){
        if (a[left] == a[right]){
            return a[left];
        }else {
            return -1;
        }
    }

    if (left + 2 == right){
        if(a[left] == a[left +1]){
            return a[left];
        }else if (a[right] == a[right -1]){
            return a[right];
        }else if (a[left] == a[right]){
            return a[left];
        }else {
            return -1;
        }
    }

  int med = (right  + left)/2;


  int temp_left_path = get_majority_element(a,left , med);
  int temp_right_path = get_majority_element(a, med +1, right);
  int count_left_path{0};
  int count_right_path{0};

  if (temp_left_path != -1){
      for (int i{left}; i <= right ;++i){
          if(a[i] == temp_left_path)
              ++count_left_path;
      }
  }

  if (temp_right_path != -1){
      for (int i{left}; i <= right ;++i){
          if(a[i] == temp_right_path)
              ++count_right_path;
      }
  }

  if (count_left_path*2 > (right - left+1)){
      return temp_left_path;
  } else if (count_right_path*2 > (right - left+1)){
      return temp_right_path;
  }else
      return -1;










  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size() - 1) != -1) << '\n';
}
