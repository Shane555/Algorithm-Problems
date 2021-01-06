#include <iostream>
long long gcd_fast(long long a, long long b){
  if (b==0)
    return a;
  
  long long a_prime = a%b;
  return gcd_fast(b, a_prime);

}

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long lcm_fast(long long a, long long b){
  long long result= (a*b)/gcd_fast(a,b); //uses euclidean algorithm formulation to solve for LCM efficiently without prime factorisation
  return result;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
