#include <iostream>

bool is_odd(const int n) {
    return n & 0x1;
}

bool is_even(const int n) {
    return !(is_odd(n));
}

auto create_is_inclusive_range(const int a, const int b) /*->int->bool*/
{
    return [a, b](const int x) {
        return a <= x && x <= b;
    };
}

bool is_weird(const int x) {
    if (is_odd(x)) {
        return true;
    }

    static const auto is_inclusive_2_5 = create_is_inclusive_range(2, 5);
    if (is_inclusive_2_5(x)) {
        return false;
    }

    static const auto is_inclusive_6_20 = create_is_inclusive_range(6, 20);
    if (is_inclusive_6_20(x)) {
        return true;
    }

    return false;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << (is_weird(n) ? "Weird" : "Not Weird") << std::endl;

    return 0;
}