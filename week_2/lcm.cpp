#include <iostream>

int gcd_fast(int a, int b);
unsigned long long lcm_fast(int a, int b);

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= static_cast<long long>(a * b) ; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return static_cast<long long> (a * b);
}

int main() {
  int a, b;
//  while (true){
  std::cin >> a >> b;
//  std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_fast(a, b) << std::endl;
//  }
  return 0;
}

int gcd_fast(int a, int b) {

    if (b > a)
        std::swap(a,b);
    if (b == 0)
        return a;
    return gcd_fast(b, a % b);

}

 unsigned long long lcm_fast(int a, int b){
//     std::cout << a << " " << b << "\n";
//    std::cout << static_cast<unsigned long long>(a*b)<< ' '<< gcd_fast(a,b)<< "\n";
    return static_cast<unsigned long long>(a/gcd_fast(a,b))*b;

}
