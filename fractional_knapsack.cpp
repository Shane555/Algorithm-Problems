/**
 * Solves the fractional knapsack algorithm problem using greedy algorithm. 
 * Optimise based on value per weight unit and uses vectors from std c++ library
**/
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  vector<double> v_per_w(weights.size(), 0);
  for (int i =0; i<weights.size(); ++i){
    v_per_w[i] = double(values[i])/double(weights[i]); //calculate v/w for the vector
  }

  //as long as capacity is not full and there are still items available for taking
  while (capacity !=0 && weights.size()!=0){
    auto it = std::max_element(v_per_w.begin(), v_per_w.end()); //find max element in v/w
    auto it2 = std::find(v_per_w.begin(), v_per_w.end(), *it); // find the index of that max element in v/w
    int largest_index = std::distance(v_per_w.begin(), it2); //using it2 to return index number 
    if (capacity>=weights[largest_index]){ 
      value+= values[largest_index]; //if capacity is more than the weight of that max v/w, add it all in
      capacity -= weights[largest_index]; //reduce capacity accordingly to keep track of capacity
    }
    else{
      value += v_per_w[largest_index] * capacity; //else add whatever weight you can of that max v/w
      capacity = 0; //reduce capacity accordingly to keep track of capacity
    }
    values.erase(values.begin()+largest_index); //remove that item from all the 3 vectors
    weights.erase(weights.begin()+largest_index);
    v_per_w.erase(v_per_w.begin()+largest_index);
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
