#include <iostream>
#include <vector>
#include <cstdlib>
#include <utility>

using std::vector;
using std::swap;
using std::pair;

pair<int,int> partition3(vector<int> &a, int l, int r);
void randomized_quick_sort(vector<int> &a, int l, int r);
int foo1(vector<int> &vec, int start, int end, int key, bool min);

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  randomized_quick_sort(starts,0, starts.size()-1);
  randomized_quick_sort(ends,0, ends.size()-1);
//------------------------------------------------------------------------------
  for (int i{0}; i < points.size(); ++i){
  int temp_start = foo1(starts,0, starts.size() -1, points[i], false );
  int temp_end = foo1(ends,0, ends.size() -1, points[i], true );

      if (temp_start ==-2 || temp_end == -2){
          points[i] = 0;
          continue;
      }

      if (temp_start == -1){
          cnt[i] = starts.size() - (temp_end + 1);
          continue;
      } else {
          cnt[i] = temp_start - (temp_end+1);
      }

  }

//------------------------------------------------------------------------------
  return cnt;
}

//vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
//  vector<int> cnt(points.size());
//  for (size_t i = 0; i < points.size(); i++) {
//    for (size_t j = 0; j < starts.size(); j++) {
//      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
//    }
//  }
//  return cnt;
//}

int main() {
  int n, m;
  std::cin >> n >> m;
//  n = 18;

//  m = 19;
  vector<int> starts(n);
//  vector<int> starts{0,-3,7,0,0,   0,1,1,1,1,  2,2,2,2,3,    3,3,3};
  vector<int> ends(n);
//  vector<int>   ends{5,2, 10,4,1,  6,7,3,9,2,  9,10,4,8,11,  10,5,4};
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
 }
//  vector<int> points{-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,10,11,12,13};
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
//  vector<int> cnt = naive_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  pair<int,int> m = partition3(a, l, r);

  randomized_quick_sort(a, l, m.first - 1);
  randomized_quick_sort(a, m.second + 1, r);
}

pair<int,int> partition3(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  int j_second = l;


    for (int i = l + 1; i <= r; i++) {
      if (a[i] == x) {
        j_second++;
        swap(a[i], a[j_second]);
      } else if (a[i] < x){
          j++;
          swap(a[j], a[i]);
          if(j != j_second+1){
              j_second++;
          swap(a[j_second], a[i]);
          }else {
              j_second++;
          }
      }
    }


  swap(a[l], a[j]);
  return {j,j_second};
}



int foo1(vector<int> &vec, int start, int end, int key, bool min){
    if ((vec[start] > key && !min) ||(vec[end] < key && min))
        return -2;
    if (vec[start] > key && min)
        return -1;
    if (vec[end]   < key && !min)
        return -1;


    int temp_return {-1};


    int dim = (end+start)/2;
    if (key == vec[dim]){
        temp_return = dim;
    } else if (start+1  == end){
        if (vec[end] == key){
            temp_return = end;

        } else if (min){
            return start;
        }else {
            return end;
        }
    }

    if (temp_return != -1){
        if (min){
            while (temp_return >= 0 &&  vec[temp_return] == key){
                temp_return--;
                if(temp_return < 0){
                    return -1;
                }
             }
        } else{
            while (temp_return <= vec.size()-1 &&  vec[temp_return] == key){
                temp_return++;
                if(temp_return == vec.size()){
                    return -1;
                }
             }
        }
        return temp_return;
    }


    if (key < vec[dim]){
        return foo1(vec, start, dim, key, min);
    } else{
        return foo1(vec, dim, end, key, min);
    }
}
