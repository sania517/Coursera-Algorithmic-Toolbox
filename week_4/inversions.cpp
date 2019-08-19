#include <iostream>
#include <vector>
#include <deque>

using std::vector;
using std::swap;
using std::deque;

//long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
//  long long number_of_inversions = 0;
//  if (right <= left + 1) return number_of_inversions;
//  size_t ave = left + (right - left) / 2;
//  number_of_inversions += get_number_of_inversions(a, b, left, ave);
//  number_of_inversions += get_number_of_inversions(a, b, ave, right);
//  //write your code here
//  return number_of_inversions;
//}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;

  if(left+2 < right){
      number_of_inversions += get_number_of_inversions(a, b, left, ave);
      deque<int> temp_first;
      for(size_t i {left}; i < ave;++i){
          temp_first.push_back(a[i]);
      }

      number_of_inversions += get_number_of_inversions(a, b, ave, right);
      deque<int> temp_second;
      for(size_t i {ave}; i < right;++i){
          temp_second.push_back(a[i]);
      }

      for(size_t i {left}; i < right;++i){
          if (temp_first.size() > 0 && temp_second.size() > 0){
              if (temp_first.front() > temp_second.front()){
                  a[i] = temp_second.front();
                  temp_second.pop_front();
                  number_of_inversions = number_of_inversions+ temp_first.size();
              } else{
                  a[i] = temp_first.front();
                  temp_first.pop_front();
              }
          } else if (temp_second.size() > 0 && temp_first.size() == 0){
              a[i] = temp_second.front();
              temp_second.pop_front();
          } else if (temp_first.size() > 0 && temp_second.size() == 0){
              a[i] = temp_first.front();
              temp_first.pop_front();
              //++number_of_inversions;
          }
      }



      return number_of_inversions;
  } else if (left+2 == right){
      if(a[left] > a[left+1]){
          swap(a[left],a[left+1]);
          ++number_of_inversions;
          return number_of_inversions;
      }
  }


  //write your code here






  //write your code here
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
