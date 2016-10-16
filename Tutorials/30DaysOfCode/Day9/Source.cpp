#include <bits/stdc++.h>

namespace util {
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

    template <>
    struct convert_traits<std::string> {
        using result_type = std::string;
        static result_type apply(const std::string& buf) {
            return buf;
        }
    };

    template <typename T>
    T read_from_cin()
    {
        std::string buf;
        std::getline(std::cin, buf);
        return convert_traits<T>::apply(buf);
    }
}

int factorial(const int i, const int intermediate) {
    if (i == 1) {
        return intermediate;
    }

    return factorial(i - 1, intermediate * i);
}

int factorial(const int i) {
    return factorial(i, 1);
}

int main() {
    const int n = util::read_from_cin<int>();
    std::cout << factorial(n) << std::endl;

    return 0;
}