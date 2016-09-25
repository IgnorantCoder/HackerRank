#include <cmath>
#include <iostream>
#include <string>

int to_int(const char ch)
{
    return int(ch) - 97;    //return 0 to 25.
}

int distance(const char ch0, const char ch1)
{
    return std::abs(to_int(ch0) - to_int(ch1));
}

std::size_t half(const std::size_t n)
{
    return n >> 1;
}

int solve(const std::string& str) {
    int sum = 0;
    for (std::size_t i = 0; i < half(str.size()); ++i) {
        sum += distance(str[i], str[str.size() - i - 1]);
    }
    return sum;
}

int main()
{
    int t;
    std::cin >> t;
    std::cin.ignore();

    for (int i = 0; i < t; ++i) {
        std::string input;
        std::cin >> input;
        std::cin.ignore();
        std::cout << solve(input) << std::endl;
    }

    return 0;
}