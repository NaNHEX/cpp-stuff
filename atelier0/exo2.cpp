// Exercice 2
#include <iostream>
#include <string>

class Person {
private:
    std::string m_name;

public:
    Person(const std::string &name) : m_name(name) {}

    std::string getName() const {
        return m_name;
    }
};

int main () {
    int a;
    std::cin >> a;

    int b;
    std::cin >> b;

    b += a;
    a = b - a;
    b = b - a;
    std::cout << "a : " << a << " b : " << b << '\n';
    return 0;
}