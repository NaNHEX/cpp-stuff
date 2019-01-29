#include <iostream>
#include <cstdint>
#include <cmath>


class FixedPoint2 {
private:
    std::int16_t m_leftPart = 0;
    std::int8_t m_rightPart = 0;

public:
    FixedPoint2 () {}

    FixedPoint2 (std::int16_t left, std::int8_t right)
        : m_leftPart(left), m_rightPart(right)
    {
 		if (m_leftPart < 0.0 || m_rightPart < 0.0)
		{
			if (m_leftPart > 0.0)
				m_leftPart = -m_leftPart;

			if (m_rightPart > 0.0)
				m_rightPart = -m_rightPart;
		}
    }

    FixedPoint2 (double num) {
        m_leftPart = static_cast<std::int16_t>(num);
        m_rightPart = static_cast<std::int8_t>(std::round((num - m_leftPart) * 100));
    }

    operator double() const {
        return m_leftPart + static_cast<double>(m_rightPart) / 100;
    }

    friend std::ostream& operator<< (std::ostream &out, const FixedPoint2 &fixed);
};

std::ostream& operator<< (std::ostream &out, const FixedPoint2 &fixed) {
    out << static_cast<double>(fixed);
    return out;
}

int main() {
	FixedPoint2 a(34, 56);
	std::cout << a << '\n';

	FixedPoint2 b(-2, 8);
	std::cout << b << '\n';

	FixedPoint2 c(2, -8);
	std::cout << c << '\n';

	FixedPoint2 d(-2, -8);
	std::cout << d << '\n';

	FixedPoint2 e(0, -5);
	std::cout << e << '\n';

	std::cout << static_cast<double>(e) << '\n';

    FixedPoint2 f(0.01);
	std::cout << f << '\n';

	FixedPoint2 g(-0.01);
	std::cout << g << '\n';

	FixedPoint2 h(5.01); // stored as 5.0099999... so we'll need to round this
	std::cout << h << '\n';

	FixedPoint2 i(-5.01); // stored as -5.0099999... so we'll need to round this
	std::cout << i << '\n';

	return 0;
}