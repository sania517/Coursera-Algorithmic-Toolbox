#include <iostream>
#include <vector>
long long get_fibonacci_huge_fast(long long n, long long m) ;

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long tmp_previous;

    for (long long i = 0; i < n - 1; ++i) {
        tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m)<< '\n';

}

long long get_fibonacci_huge_fast(long long n, long long m) {
    if (n <= 1)
        return n;
    std::vector<unsigned long long> vec;
    vec.push_back(static_cast<long long>(0));
    vec.push_back(static_cast<long long>(1));
    long period {2};
//    long long temp_mod{-1};
//    long long temp_mod_previoos{-1};

    for (unsigned long long i = 2;; ++i) {
//        std::cout << "i: "<< i<< " ";
        vec.push_back((vec[i-1]+vec[i-2]) % m);
//        temp_mod = vec[i] % m;
//        std::cout << "temp_mod: " << vec[i] << " temp_mod_previoos: " << vec[i-1]<< ' ';
        if(vec[i] == 1 && vec[i-1] == 0){
            --period;
//            std::cout << "period: "<< period << std::endl;
            break;
        }
        ++period;
//        std::cout << "period: "<< period << std::endl;
//        temp_mod_previoos  = temp_mod;
//        std::cout << current % m << ' ';
    }
//    std::cout <<period << std::endl;

    return vec[n % period];
}



