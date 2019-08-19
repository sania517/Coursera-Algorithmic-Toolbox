#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

string largest_number(vector<string> a) {
  //write your code here
    string result{};

    while (a.size()>1){
    vector<string>::iterator it =a.begin();
    vector<string>::iterator temp_it =a.begin();
    string temp = a[0];

    for (int i{1};i < a.size();++i) {
        string temp_str1 = temp + a[i];
        string temp_str2 = a[i] + temp;
        ++temp_it;
        if(temp_str1 < temp_str2){
            temp = a[i];
            it = temp_it;
        }
    }
    result = result + *it;
    a.erase(it);
    }
    result = result + a[0];

  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
