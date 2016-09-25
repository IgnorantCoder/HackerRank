#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <utility>
#include <string>

std::size_t half(const std::size_t n)
{
    return n >> 1;
}

int to_int(const char ch)
{
    return int(ch) - 97;    //return 0 to 25.
}

std::deque<int> to_int(const std::string& str)
{
    std::deque<int> ret = {};
    std::transform(
        str.cbegin(),
        str.cend(),
        std::inserter(ret, ret.end()),
        static_cast<int(*)(const char)>(to_int));
    std::sort(ret.begin(), ret.end());
    return ret;
}


int distance(const std::pair<std::string, std::string>& p)
{
    const auto l = to_int(p.first);
    auto r = to_int(p.second);
    for (auto itl = l.cbegin(); itl != l.cend(); ++itl) {
        auto itr = std::find(r.begin(), r.end(), *itl);
        if (itr != r.end()) {
            r.erase(itr);
        }
    }

    return r.size();
}

std::pair<std::string, std::string> split(const std::string& str)
{
    const auto m = half(str.size());
    return std::make_pair(
        str.substr(0, m),
        str.substr(m, m));
}

bool is_odd(const std::size_t n) 
{
    return n & 0x1;
}

int solve(const std::string& input) {
    if (is_odd(input.size())) {
        return -1;
    }
    
    return distance(split(input));
}

int main()
{
    int t;
    std::cin >> t;
    std::cin.ignore();

    for (int i = 0; i < t; ++i) {
        std::string buf;
        std::cin >> buf;
        std::cin.ignore();
        std::cout << solve(buf) << std::endl;
    }

    return 0;
}