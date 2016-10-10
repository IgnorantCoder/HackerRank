#include <iostream>
#include <string>
#include <utility>
#include <vector>

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

bool is_odd(const int n) 
{
    return n & 0x1;
}

int half(const int n) {
    return n >> 1;
}

std::pair<std::string, std::string> sieve(const std::string& str)
{
    std::pair<std::string, std::string> ret;
    const int reserve_size = half(str.size() + 1);
    ret.first.reserve(reserve_size);
    ret.second.reserve(reserve_size);
    for (std::size_t i = 0; i < str.size(); ++i) {
        if (is_odd(i)) {
            ret.second.push_back(str[i]);
        }
        else {
            ret.first.push_back(str[i]);
        }
    }
    return ret;
}

void solve(const std::string& str)
{
    const auto p = sieve(str);
    std::cout << p.first << " " << p.second << std::endl;
}

int main() {

    const auto t = read_from_cin<int>();
    for (int i = 0; i < t; ++i) {
        solve(read_from_cin<std::string>());
    }

    return 0;
}