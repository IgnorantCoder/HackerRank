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

    std::getline(std::cin, buf);
    std::stringstream stream;
    stream << buf;

    std::vector<int> v;
    v.reserve(n);
    while (std::getline(stream, buf, ' ')) {
        v.push_back(std::stoi(buf));
    }
    std::sort(v.begin(), v.end());
    std::cout << v.front();
    for (std::size_t i = 1; i < v.size(); ++i) {
        std::cout << ' ' << v[i];
    }
    std::cout << std::endl;

    return 0;
}