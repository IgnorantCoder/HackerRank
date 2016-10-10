#include <iostream>
#include <iomanip>
#include <string>

int main() {
    const int i = 4;
    const double d = 4.0;
    const std::string s = "HackerRank ";

    {
        std::string buf;
        std::getline(std::cin, buf);
        std::cout << i + std::stoi(buf) << std::endl;
    }

    {
        std::string buf;
        std::getline(std::cin, buf);
        std::cout
            << std::fixed << std::setprecision(1)
            << d + std::stod(buf) << std::endl;
    }

    {
        std::string buf;
        std::getline(std::cin, buf);
        std::cout << s + buf << std::endl;
    }

    return 0;
}