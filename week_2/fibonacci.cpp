#include <iostream>
#include <cassert>


int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int fibonacci_fast(int n) {
    if (n <=1)
        return n;
    int *arr = new int[n+1];
    arr[0] = 0;
    arr[1] = 1;
    for (int i{2}; i < n+1 ; ++i ){
        arr[i] = arr[i-2] + arr [i-1];
//        std::cout << arr[i] << " ";
    }
    int result = arr[n];
    delete[] arr;
    return result;
}

void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main() {
    int n = 0;
    std::cin >> n;

    std::cout << fibonacci_fast(n) << '\n';
    return 0;
}
