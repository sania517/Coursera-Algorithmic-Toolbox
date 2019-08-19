#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;
    int tmp_previous{0};

    for (int i = 0; i < n - 1; ++i) {
        tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }


    return current % 10;
}

int get_fibonacci_last_digit_fast(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;
    int tmp_previous{0};

    for (int i = 0; i < n - 1; ++i) {
        tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
    }

    return current % 10;
}

int main() {
    int n;
    std::cin >> n;
//    while (true){
//    n = rand()%50+2;
//    int c = get_fibonacci_last_digit_naive(n);
//    int c1 = get_fibonacci_last_digit_fast(n);
//    std::cout << c << '\n';
//    std::cout << c2 << '\n';
//    if (c1 != c){
//        std::cout << n << " "<< c << " " << c1 << " BREAK\n";
//        break;
//    }else {
//        std::cout << c << " " << c1 << " OK\n";
//    }
//    }
    std::cout << get_fibonacci_last_digit_fast(n) << '\n';
    }
