#include <iostream>
#include <vector>

int fibonacci_sum_squares_fast(long long n);

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n);
    std::cout << '\n';
}

int fibonacci_sum_squares_fast(long long n) {
    if (n < 2)
        return n;

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
//    for (auto var : vec)
//        std::cout << var << ' ';
//    std::cout << std::endl;




    int count_period = n / period;
    int add_period = n % period;
    int sum_period{0};
    int add_sum_period{0};

    for (size_t t{0}; t < vec.size(); ++t){
        vec[t] = (vec[t]*vec[t]) % 10;
        sum_period = (sum_period+vec[t]) % 10;
        if (t == add_period)
            add_sum_period = sum_period;
    }

    return (count_period * sum_period + add_sum_period) % 10;


}
