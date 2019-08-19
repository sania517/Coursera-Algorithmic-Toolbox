#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const string &exp) {
    if(!(exp.size() % 2))
        return 0;
 vector<int> numbers(exp.size()/2 + 1);
 vector<char> operators(exp.size()/2);
 std::istringstream ss{exp};
 ss >> numbers[0];
 for(size_t i {0}; i < operators.size(); ++i){
     ss >> operators[i] >> numbers[i+1];
 }

 vector<vector<long long>> Min(numbers.size());
 vector<vector<long long>> Max(numbers.size());
 for(size_t i {0}; i< numbers.size(); ++i){
     Min[i].resize(numbers.size(),0);
     Max[i].resize(numbers.size(),0);
 }

 for(size_t i {0}; i< numbers.size(); ++i){
     Min[i][i] = numbers[i];
     Max[i][i] = numbers[i];
 }
 for(size_t i {0}; i< numbers.size()-1; ++i){
     Min[i][i+1] = eval(numbers[i], numbers[i+1], operators[i]);
     Max[i][i+1] = eval(numbers[i], numbers[i+1], operators[i]);
 }
 //
 {
     for(size_t y {2}; y < numbers.size(); ++y)
        for(size_t i {0}; i< numbers.size() - y ; ++i){
//         Min[i][i+y]=10;
//         Max[i][i+y]=10;
           for (size_t p {0}; p < y; ++p){
               if(p == 0){
                   Min[i][i+y]=min(eval(Min[i][i+p], Min[i+1+p][y+i], operators[p+i]),eval(Min[i][i+p], Max[i+1+p][y+i], operators[p+i]));
                   Max[i][i+y]=max(eval(Min[i][i+p], Min[i+1+p][y+i], operators[p+i]),eval(Min[i][i+p], Max[i+1+p][y+i], operators[p+i]));
               }
               long long min_min = eval(Min[i][i+p], Min[i+1+p][y+i], operators[p+i]);
               long long max_max = eval(Max[i][i+p], Max[i+1+p][y+i], operators[p+i]);
               long long min_max = eval(Min[i][i+p], Max[i+1+p][y+i], operators[p+i]);
               long long max_min = eval(Max[i][i+p], Min[i+1+p][y+i], operators[p+i]);
               Min[i][i+y] = min(min(min(min_min,max_max), min(min_max,max_min)),Min[i][i+y]);
               Max[i][i+y] = max(max(max(min_min,max_max), max(min_max,max_min)), Max[i][i+y]);
         }

     }
 }

  return Max[0].back();
}

int main() {
  string s;
  std::cin >> s;
//    string s{"5-8+7*4-8+9"};
  std::cout << get_maximum_value(s) << '\n';
}
