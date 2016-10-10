#include <cmath>
#include <iostream>
#include <string>

template <typename T>
struct convert_traits;

template <>
struct convert_traits<int> {
    using result_type = int;
    static result_type apply(const std::string& buf) {
        return std::stoi(buf);
    }
};

template <>
struct convert_traits<double> {
    using result_type = double;
    static result_type apply(const std::string& buf) {
        return std::stod(buf);
    }
};

template <typename T>
T read_from_cin() {
    std::string buf;
    std::getline(std::cin, buf);
    return convert_traits<T>::apply(buf);
}

double calculate_fraction(const double principal, const int percent)
{
    constexpr double onehundredth = 1e-2;
    const double tip
        = principal
        * static_cast<double>(percent)
        * onehundredth;
    return tip;
}

int main() {
    const double meal_cost = read_from_cin<double>();

    const int tip_percent = read_from_cin<int>();
    const double tip_cost = calculate_fraction(meal_cost, tip_percent);

    const int tax_percent = read_from_cin<int>();
    const double tax_cost = calculate_fraction(meal_cost, tax_percent);

    const double total_cost = meal_cost + tip_cost + tax_cost;
    const double rounded_total_cost = std::round(total_cost);

    std::cout
        << "The total meal cost is "
        << rounded_total_cost
        << " dollars."
        << std::endl;

    return 0;
}