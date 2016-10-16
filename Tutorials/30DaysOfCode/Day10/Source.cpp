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

    template <std::size_t B, std::size_t N>
    void convert_to_ary(
        std::bitset<N>& ret, int& x, const int digit, const int basis)
    {
        const int move_up_basis = basis * B;

        if (move_up_basis <= x) {
            convert_to_ary<B>(ret, x, digit + 1, move_up_basis);
        }

        if (basis <= x) {
            x -= basis;
            ret.set(digit);
        }

        return;
    }

    /**
    @brief convert to B-ary number.
    @detail
        if you want to convert x(x <= 10000) to binary,
            constexpr std::size_t B = 2;
            constexpr std::size_t N = max_digit<B, 10000>();
            const auto bits = convert_to_ary<B, N>(x);
    @tparam B basis-number
    @tparam N max digit of result, use max_digit<B, max_input>()
    @param [in] x input integer
    */
    template <std::size_t B, std::size_t N>
    std::bitset<N> convert_to_ary(int x) {
        std::bitset<N> ret = {};
        convert_to_ary<B>(ret, x, 0, 1);
        return ret;
    }

    template <int N, std::size_t B, std::size_t P, std::size_t I, bool F>
    struct max_digit_traits {
        static constexpr std::size_t value
            = max_digit_traits<N, B, P * B, I + 1, N < P * B>::value;
    };

    template <int N, std::size_t B, std::size_t P, std::size_t I>
    struct max_digit_traits<N, B, P, I, true> {
        static constexpr std::size_t value = I;
    };

    /**
    @brief calculate max digit of B basis-number with N in compile time.
    @tparam B basis-number
    @tparam N max input.
    */
    template <std::size_t B, int N>
    constexpr std::size_t max_digit() {
        return max_digit_traits<N, B, 1, 0, false>::value;
    }
}

template <std::size_t N>
int count_concequtive(const std::bitset<N>& binary)
{
    int i = 0;
    for (auto test = binary; test.any(); test = test & (test << 1)) {
        ++i;
    }
    return i;
}

int main() {
    constexpr int max_input = 1000000;
    constexpr auto B = 2;
    constexpr auto N = util::max_digit<2, max_input>();

    const auto n = util::read_from_cin<int>();
    const auto binary = util::convert_to_ary<B, N>(n);
    const auto shifted = binary << 2;
    std::cout << count_concequtive(binary) << std::endl;

    return 0;
}