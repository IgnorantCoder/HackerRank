#include <iostream>
#include <vector>
#include <string>
#include <sstream>

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

std::vector<int> split(const int n, const std::string& source) {
    std::vector<int> ret = {};
    ret.reserve(n);
    std::stringstream stream;
    stream << source;
    std::string buf = {};
    for (;std::getline(stream, buf, ' '); ) {
        ret.push_back(std::stoi(buf));
    }
    return ret;
}

void solve(const int n, const std::string& source) {
    const std::vector<int> arr = split(n, source);
    for (auto it = arr.crbegin(); it != arr.crend(); ++it) {
        std::cout << (it == arr.crbegin() ? "" : " ") << *it;
    }
    return;
}

int main() {
    const int n = read_from_cin<int>();
    const std::string source = read_from_cin<std::string>();
    solve(n, source);

    return 0;
}