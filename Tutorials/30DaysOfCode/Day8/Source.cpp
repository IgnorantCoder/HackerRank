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

int main() {
    const auto n = util::read_from_cin<int>();
    std::map<std::string, int> phoneNumber;
    for (int i = 0; i < n; ++i) {
        const auto key_value
            = util::split(util::read_from_cin<std::string>(), ' ');
        const auto key = key_value[0];
        const auto val = std::stoi(key_value[1]);
        phoneNumber.emplace(key, val);
    }

    for (;true;) {
        const auto k = util::read_from_cin<std::string>();
        if (k == "") {
            break;
        }
        const auto it = phoneNumber.find(k);
        if (it == phoneNumber.cend()) {
            std::cout << "Not found" << std::endl;
        }
        else {
            std::cout << it->first << "=" << it->second << std::endl;
        }
    }

    return 0;
}