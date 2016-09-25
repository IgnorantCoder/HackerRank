#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main()
{
    std::string buf;
    std::getline(std::cin, buf);
    const int n = std::stoi(buf);

    std::vector<int> v;
    {
        std::getline(std::cin, buf);
        std::stringstream stream;
        stream << buf;

        v.reserve(n);
        while (std::getline(stream, buf, ' ')) {
            v.push_back(std::stoi(buf));
        }
    }

    std::getline(std::cin, buf);
    const int m = std::stoi(buf);

    std::vector<int> e;
    {
        std::getline(std::cin, buf);
        std::stringstream stream;
        stream << buf;

        e.reserve(m);
        while (std::getline(stream, buf, ' ')) {
            e.push_back(std::stoi(buf));
        }
    }

    v.erase(v.begin() + m - 1);
    v.erase(v.begin() + e[0] - 1, v.begin() + e[1] - 1);
    std::cout << v.size() << std::endl;
    std::cout << v.front();
    for (std::size_t i = 1; i < v.size(); ++i) {
        std::cout << ' ' << v[i];
    }
    std::cout << std::endl;

    return 0;
}