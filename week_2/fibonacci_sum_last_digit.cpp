#include <iostream>
#include <vector>
int fibonacci_sum_fast(long long n);

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
//    std::cout << fibonacci_sum_naive(n);
//    std::cout << std::endl;
    std::cout << fibonacci_sum_fast(n);
}

int fibonacci_sum_fast(long long n) {
    if (n <= 1)
        return n;
//________________________________________________________
    std::vector<unsigned long long> vec;
    vec.push_back(static_cast<long long>(0));
    vec.push_back(static_cast<long long>(1));
    long period {2};

    for (unsigned long long i = 2;; ++i) {
        vec.push_back((vec[i-1]+vec[i-2]) % 10);
        if(vec[i] == 1 && vec[i-1] == 0){
            --period;
            vec.pop_back();
            vec.pop_back();
            break;
        }
        ++period;
    }
    long count_period {n/period};
    long count_add {n % period};
    int sum_period{0};
    int sum_count{0};

//---------------------------------------------------------
    for(size_t r {0}; r < vec.size(); ++r){
        sum_period = (sum_period+vec[r])%10;
        if (r == count_add)
            sum_count = sum_period;
    }

    return (count_period * sum_period + sum_count)% 10;
}
