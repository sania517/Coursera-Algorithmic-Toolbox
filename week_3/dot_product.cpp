#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long max_dot_product(vector<int> a, vector<int> b) {
  // write your code here
    long long result = 0;
    int max_a{0};
    vector<int>::iterator it_a;
    int max_b{0};
    vector<int>::iterator it_b;
    while(a.size() > 0 ){
    max_a = a[0];
    max_b = b[0];
    it_a = a.begin();
    it_b = b.begin();

    for(auto i {a.begin()}; i != a.end(); ++i ) {
        if(max_a < *i){
            max_a = *i;
            it_a = i;
        }
    }

    for(auto y {b.begin()}; y != b.end(); ++y ) {
        if(max_b < *y){
            max_b = *y;
            it_b = y;
        }
    }
    a.erase(it_a);
    b.erase(it_b);
//    std::cout << "a*b: " << max_a * max_b << '\n';
    result += (static_cast<long long>(max_a))*max_b;



    }

    // write your code here

  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
