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

    std::vector<std::string> split(const std::string& s, const char delim) 
    {
        std::stringstream stream;
        stream << s;

        std::string buf;
        std::vector<std::string> ret;
        for (;std::getline(stream, buf, delim);) {
            ret.emplace_back(buf);
        }
        return ret;
    }
}

template <std::size_t M, std::size_t N>
void initialize(int (&arr)[M][N])
{
    for (std::size_t i = 0; i < M; ++i) {
        const auto input = util::read_from_cin<std::string>();
        const auto separated = util::split(input, ' ');
        for (std::size_t j = 0; j < N; ++j) {
            arr[i][j] = std::stoi(separated.at(j));
        }
    }
}

template <std::size_t M, std::size_t N>
int hour_glass_sum(int(&arr)[M][N], const std::size_t u, const std::size_t l)
{
    return arr[u    ][l] + arr[u    ][l + 1] + arr[u    ][l + 2]
                         + arr[u + 1][l + 1]
         + arr[u + 2][l] + arr[u + 2][l + 1] + arr[u + 2][l + 2];
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    constexpr std::size_t m = 6;
    constexpr std::size_t n = 6;
    int arr[m][n];
    initialize(arr);
    int ret = -9 * 7;
    for (std::size_t i = 0; i < m - 2; ++i) {
        for (std::size_t j = 0; j < n - 2; ++j) {
            const int tmp = hour_glass_sum(arr, i, j);
            if (ret < tmp) {
                ret = tmp;
            }
        }
    }
    std::cout << ret << std::endl;

    return 0;
}