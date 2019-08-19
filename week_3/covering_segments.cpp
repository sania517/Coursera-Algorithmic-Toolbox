#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  int max_b;

  while(segments.size() > 0){
      max_b = segments[0].end;
     for (auto var : segments){
         if (var.end < max_b){
             max_b = var.end;
         }
    }
//     std::cout << "max_b: " << max_b << std::endl;
     points.push_back(max_b);
//     std::cout << "points.size: "<< points.size()<< std::endl;


     for(auto i{segments.begin()}; i != segments.end(); ++i){
         if ((max_b <= (i->end)) && max_b >= i->start){
             segments.erase(i);
             i= segments.begin()-1;
         }
     }




  }




  //write your code here
//  for (size_t i = 0; i < segments.size(); ++i) {
//    points.push_back(segments[i].start);
//    points.push_back(segments[i].end);
//  }
//  std::cout << "points.size: "<< points.size()<< std::endl;
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
