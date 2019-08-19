#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int foo(const vector<int> &vec, int start, int end, int key){

    if (start == end){
        if (key == vec[start])
            return start;
        else {
            return -1;
        }
    }


    int med = (end  - start)/2;
    if (med == 0){
        if(vec[start] == key){
            return start;
        } else if(vec[end] == key){
            return end;
        }else{
            return -1;
        }
    }


    if (vec[med + start] == key){
        return med+start;
    }else if (key < vec[med+start]){
        return foo(vec, start, med+start-1, key);
    }else {
        return foo(vec,med+start+1, end ,key);
    }
}

int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size()-1;
  return foo(a,left,right, x);


//  int med = (right  -left)/2;
//  if (a[med] == x){
//      return med;
//  }else if (x > a[med]){
//      return foo(a, 0, med-1, x);
//  }else {
//      return foo(a,med+1, right,x);
//  }



  //write your code here
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
//  n = 100;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
//      a[i] = i*2;
  }
  int m;
  std::cin >> m;
//  m = 100;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
//      b[i] = i;
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
}

