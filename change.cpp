/**
 * simple case of greedy algorithm by maximising change required for a given amount of money. 
 * coins are in the values 10, 5 and 1.
 **/

#include <iostream>

int get_change(int m) {
  int count= 0;
  while (m>=10){
    m = m-10;
    count+=1;
  }
  while ((10>m) && (m>=5)){
    m = m-5;
    count+=1;
  }
  return count+m;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
