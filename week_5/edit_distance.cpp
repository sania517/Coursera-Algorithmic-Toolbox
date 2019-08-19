#include <iostream>
#include <string>

using std::string;
void print(size_t ( &a )[101][101]);

int edit_distance(const string &str1, const string &str2) {

    size_t arr[101][101]{};
    for(size_t i{0}; i <= str1.size();++i){
        arr[0][i] = i;
    }
    for(size_t i{0}; i <= str2.size();++i){
        arr[i][0] = i;
    }
    bool temp = false;
    size_t temp_int {0};
    for (size_t i {1} ; i <= str1.size(); ++i){
        for (size_t y {1} ; y <= str2.size(); ++y){
            temp = (str1[i-1] != str2[y-1]) ? true :false;
            temp_int = arr[y][i-1] < arr[y-1][i] ?  arr[y][i-1] : arr[y-1][i];

            if (temp_int < arr[y-1][i-1]){
                arr[y][i] = temp_int + 1;
            }
            else {
                temp_int = arr[y-1][i-1];
                arr[y][i] = temp_int + temp;
            }
        }
    }
//    std::cout<< arr;
//    print(arr);
  return static_cast<int>( arr[str2.size()][str1.size()]);
}

int main() {
  string str1;
  string str2;
//      string str1 = "distance";
//      string str2 = "editing";
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}

void print(size_t ( &a )[101][101]){
    for(size_t i{0}; i < 101 ; ++i){
        for(size_t y{0}; y < 101 ; y++){
            std::cout << a[i][y] <<' ' ;
        } std::cout << '\n';
    }
}
