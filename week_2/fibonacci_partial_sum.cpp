#include <iostream>
#include <vector>
using std::vector;

int get_fibonacci_partial_sum_fast(long long from, long long to);

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
//    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}

int get_fibonacci_partial_sum_fast(long long from, long long to) {
    if (to < from)
        return 0;
    if (to < 2)
        return to;
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
        long count_period_to {to/period};
        long count_add_to {to % period};
        long count_period_from {from/period};
        long count_add_from {from % period};
        int sum_period{0};
        int sum_count_to{0};
        int sum_count_from{0};


    //---------------------------------------------------------
        for(size_t r {0}; r < vec.size(); ++r){
            sum_period = (sum_period+vec[r])%10;
            if (r == count_add_to)
                sum_count_to = sum_period;
            if (r == count_add_from-1)
                sum_count_from = sum_period;
        }
//        std::cout << (count_period_to*sum_period+sum_count_to) << " " << (count_period_from*sum_period + sum_count_from) << '\n';
        int tmp = (count_period_to*sum_period+sum_count_to) - (count_period_from*sum_period + sum_count_from);

        return tmp >=0 ? tmp : tmp+10;

//        return (count_period * sum_period + sum_count)% 10;






}

