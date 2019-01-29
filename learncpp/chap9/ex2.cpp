#include <iostream>

class Average {
private:
    int32_t m_int = 0;
    int8_t m_count = 0;

public:
    Average& operator+= (int32_t toAdd) {
        m_int += toAdd;
        ++m_count;

        return *this;
    }

    friend std::ostream& operator<< (std::ostream &out, const Average &avg);
};

std::ostream& operator<< (std::ostream &out, const Average &avg) {
    out << avg.m_int / (double)avg.m_count;

    return out;
}

int main() {
	Average avg;

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy = avg;
	std::cout << copy << '\n';

	return 0;
}