#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using std::vector;
using std::string;
using std::pair;
using std::min;
using std::swap;
using std::cout;


pair<int,int> partition3_(vector<int> &a, int l, int r);
pair<int,int> partition3(vector<int> &a, int l, int r);
void randomized_quick_sort(vector<pair <int,int>> &a, int l, int r, bool first = true);
int foo1(vector<pair <int,int>> &vec, int start, int end, int key, bool min);


double distants(vector<pair<int,int>> &p, int start, int end){
    int med = (start + end)/2;
    if (start+2 >= end){
        if (start + 1 == end){

            double temp = std::sqrt(pow((p[start].first - p[end].first),2)
                            +pow((p[start].second - p[end].second),2));
//            cout << "p["<<start <<"]-> " << p[start].first << " : "<< p[start].second <<" | " << "p["<<end <<"]-> " << p[end].first << " : "<< p[end].second
//                 << "distance: " << temp << "\n\n";
            return temp;
        } else{
            double first_ = std::sqrt(pow((p[start].first - p[end].first),2)
                                     +pow((p[start].second - p[end].second),2));
            double second_ = std::sqrt(pow((p[start].first - p[start+1].first),2)
                                      +pow((p[start].second - p[start+1].second),2));
            double therd = std::sqrt(pow((p[start+1].first - p[end].first),2)
                                    +pow((p[start+1].second - p[end].second),2));
            double temp = first_ < second_ ? ( first_ < therd ? first_:therd) : (second_ < therd ? second_ : therd);
//            cout << "p["<<start <<"]-> " << p[start].first << " : "<< p[start].second <<" | "
//                 << "p["<<start+1 <<"]-> " << p[start+1].first << " : "<< p[start+1].second <<" | "
//                 << "p["<<end <<"]-> " << p[end].first << " : "<< p[end].second
//                 << "distance1: " << first_ << " distance2: " << second_ << "distance3: " << therd<<  " return" <<temp << "\n\n";

            return temp;
        }

    } else{
       double temp_dist1 = distants(p, start, med);
       double temp_dist2 = distants(p,med+1,end);
       if (temp_dist1 == 0 || temp_dist2 == 0)
           return 0;
       double temp_dist = temp_dist1 < temp_dist2 ? temp_dist1 : temp_dist2;
//       cout << "\n1 temp dist:" << temp_dist << "\n";
       int temp_start = p[med].first - static_cast<int>(temp_dist);
//       int temp_end = p[med+1].first + static_cast<int>(temp_dist);
       int temp_end = p[med].first + static_cast<int>(temp_dist);
//       cout << "temp start and end " << temp_start << " | " << temp_end << '\n';
       int temp_start_index {-1};
       int temp_end_index = {-1};
       //поиск левого индекса
//       for (int i{0};;++i){
//           if((med - i) < 0)
//               break;
//           if (p[med - i].first >= temp_start){
//               temp_start_index = med - i;
//           } else{
//               break;
//           }
//       }
       //поиск правого индекса
//       for (int i{0};;++i){
//           if((med + 1 + i) > (p.size() - 1) )
//               break;
//           if (p[med +1 + i].first <= temp_end){
//               temp_end_index = med + 1 + i;
//           } else{
//               break;
//           }
//       }
//       cout << " main : left index: " << temp_start_index << " right index:" << temp_end_index << '\n';

//       int temp_start_index_1 {-1};
//       int temp_end_index_1 = {-1};
       temp_start_index = foo1(p, 0,med,temp_start,true)+1;

       int temp_3 = foo1(p,med,end,temp_end,false);

       temp_end_index = temp_3 < 0 ? end : temp_3 - 1;
//       cout << " foo1 : left index: " << temp_start_index_1 << " right index:" << temp_end_index_1 << '\n';



       vector <pair<int,int>> sort_by_y;
       for(int i {temp_start_index}; i <= temp_end_index; ++i){
           sort_by_y.push_back(p[i]);
       }
       randomized_quick_sort(sort_by_y,0,sort_by_y.size()-1, false);
//       int temp_count = sort_by_y.size() <=  7 ? sort_by_y.size() : sort_by_y.size() - 7;

//       for(auto var : sort_by_y)
//           cout << "x: "<< var.first << " | y: " << var.second<< '\n';


       double temp_calk_1{-1.};
       double temp_calk_2{-1.};

       for(int i{0}; i < sort_by_y.size()-1;++i){
           for (int y{i+1}; y < i+7 && y < sort_by_y.size() ;++y){
               temp_calk_2 = std::sqrt(pow((sort_by_y[i].first - sort_by_y[y].first),2)
                         +pow((sort_by_y[i].second - sort_by_y[y].second),2));
               if (temp_calk_1 < 0)
                   temp_calk_1 = temp_calk_2;
               else if (temp_calk_2 < temp_calk_1)
                   temp_calk_1 = temp_calk_2;
//               cout <<'['<< i<<"] [" << y  << "] temp_calk_2: " << temp_calk_2 << "  temp_calk_1: " << temp_calk_1<< '\n';
           }
       }
       if (temp_calk_1 < temp_dist)
           temp_dist = temp_calk_1;
//       cout << "!!!!!!!temp_dist: " << temp_dist << '\n';
//       cout << "-----------------------------------------------";

       return temp_dist;
    }

}


double minimal_distance(vector<int> x, vector<int> y) {
    vector<pair<int,int>>points;
    for (int i{0}; i<x.size(); ++i){
        points.push_back({x[i],y[i]});
    }
    randomized_quick_sort(points,0,points.size()-1);

//    for (auto var : points)
//        cout << "x: "<< var.first << " | y: " << var.second<< '\n';
//    cout << "-------------------------------------------------------------------\n";

    double dist = distants(points, 0 , points.size()-1);
















  return dist;
}

int main() {
  size_t n;
//  std::cin >> n;
//  vector<int> x(n);
//  vector<int> y(n);
  vector<int> x{4,-2,-3,-1,2,-4,1,-1, 3,-4,-2};
  vector<int> y{4,-2,-4, 3,3, 0,1,-1,-1, 2, 4};
//  for (size_t i = 0; i < n; i++) {
//    std::cin >> x[i] >> y[i];
//  }
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(x, y) << "\n";
}






pair<int,int> partition3_(vector<pair <int,int>> &a, int l, int r) {
  int x = a[l].first;
  int j = l;
  int j_second = l;


    for (int i = l + 1; i <= r; i++) {
      if (a[i].first == x) {
        j_second++;
        swap(a[i], a[j_second]);
      } else if (a[i].first < x){
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

pair<int,int> partition3(vector<pair <int,int>> &a, int l, int r) {
  int x = a[l].second;
  int j = l;
  int j_second = l;


    for (int i = l + 1; i <= r; i++) {
      if (a[i].second == x) {
        j_second++;
        swap(a[i], a[j_second]);
      } else if (a[i].second < x){
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

void randomized_quick_sort(vector<pair<int,int>> &a, int l, int r,bool first ) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  pair<int,int> m;
  if (first){
     m = partition3_(a, l, r);
  }else {

       m = partition3(a, l, r);
  }

  randomized_quick_sort(a, l, m.first - 1,first);
  randomized_quick_sort(a, m.second + 1, r,first);
}


int foo1(vector<pair <int,int>> &vec, int start, int end, int key, bool min){
    if ((vec[start].first > key && !min) ||(vec[end].first < key && min))
        return -2;
    if (vec[start].first > key && min)
        return -1;
    if (vec[end].first   < key && !min)
        return -1;

    int temp_return {-1};

    int dim = (end+start)/2;
    if (key == vec[dim].first){
        temp_return = dim;
    } else if (start+1  == end){
        if (vec[end].first == key){
            temp_return = end;

        } else if (min){
            return start;
        }else {
            return end;
        }
    }

    if (temp_return != -1){
        if (min){
            while (temp_return >= 0 &&  vec[temp_return].first == key){
                temp_return--;
                if(temp_return < 0){
                    return -1;
                }
             }
        } else{
            while (temp_return <= vec.size()-1 &&  vec[temp_return].first == key){
                temp_return++;
                if(temp_return == vec.size()){
                    return -1;
                }
             }
        }
        return temp_return;
    }

    if (key < vec[dim].first){
        return foo1(vec, start, dim, key, min);
    } else{
        return foo1(vec, dim, end, key, min);
    }
}
