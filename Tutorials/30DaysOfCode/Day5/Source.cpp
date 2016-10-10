#include <iostream>
#include <sstream>

auto create_printer(const int cardinal)
{
    return [cardinal](const int i) {
        std::stringstream stream;
        stream << cardinal << " x " << i << " = " << cardinal * i << std::endl;
        std::cout << stream.str();
        return;
    };
}

int main() 
{
    int n = {};
    std::cin >> n;

    const auto printer = create_printer(n);
    for (int i = 1; i <= 10; ++i) {
        printer(i);
    }

    return 0;
}