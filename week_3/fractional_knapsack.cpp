#include <iostream>
#include <vector>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  // write your code here
  struct Item{
      Item(int w,int v, double va)
          :weight{w}, value{v},value_per_weight{va}{}
      int weight;
      int value;
      double value_per_weight;
  };
  vector<Item>items;
  for(size_t i{0}; i < weights.size(); ++i){
      items.push_back({weights[i],values[i], static_cast<double>(values[i] )/weights[i]});
//      std::cout << items[i].weight << ':'<< items[i].value << ':' << items[i].value_per_weight << std::endl;

  }
//  items[2].value_per_weight = 0;
//  std::cout << "items[2].value_per_weight: "<< items[2].value_per_weight << '\n';

  double max_per{0.0};
  int temp_index{-1};

  while (capacity > 0){
//      std::cout << "items[2].value_per_weight: "<< items[2].value_per_weight << '\n';
      max_per= 0;
      temp_index =-1;
      for (size_t i{0}; i < items.size(); ++i){
          if (items[i].value_per_weight > max_per){
          max_per = items[i].value_per_weight;
          temp_index = i;
          }

//          std::cout << "max_per :"<< max_per<<' ';

      }
      if (temp_index < 0)
          break;
//      std::cout << "temp_index: " << temp_index << ' ';
      if (capacity >= items[temp_index].weight){
          capacity  -= items[temp_index].weight;
          value += items[temp_index].value;
          items[temp_index].value_per_weight = 0;
//          std::cout << "items[temp_index] " << items[temp_index].value_per_weight <<'\n';
      }else {
          value +=capacity * items[temp_index].value_per_weight;
          capacity = 0;
      }
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
