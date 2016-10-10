#include <iostream>
#include <algorithm>

bool isNegative(const int n)
{
    return n < 0;
}

class Person {
public:
    int age;
    Person(int initialAge);
    void amIOld();
    void yearPasses();
};

Person::Person(int initialAge)
    : age(std::max(0, initialAge))
{
    if (isNegative(initialAge)) {
        std::cout << "Age is not valid, setting age to 0." << std::endl;
    }
}

void Person::amIOld() {
    if (this->age < 13) {
        std::cout << "You are young." << std::endl;
        return;
    }
    if (this->age < 18) {
        std::cout << "You are a teenager." << std::endl;
        return;
    }
    std::cout << "You are old." << std::endl;
    return;
}

void Person::yearPasses() {
    ++age;
}

int main() {
    int t;
    int age;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        std::cin >> age;
        Person p(age);
        p.amIOld();
        for (int j = 0; j < 3; j++) {
            p.yearPasses();
        }
        p.amIOld();

        std::cout << '\n';
    }

    return 0;
}