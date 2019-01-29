#include <iostream>
#include <stdexcept>


class Fraction {
private:
    int m_numerator;
    int m_denominator;

public:
    Fraction (int numerator, int denominator)
        : m_numerator(numerator), m_denominator(denominator)
    {
        if (denominator == 0){
            throw std::runtime_error("Denominator can't be 0!");
        }
    }
};

int main () {
    int x;
    int y;
    std::cin >> x;
    std::cin >> y;

    try {
        Fraction f1(x, y);
    }
    catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }

    return 0;
}