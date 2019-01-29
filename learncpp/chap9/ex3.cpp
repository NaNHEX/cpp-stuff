#include <iostream>
#include <cassert>


class IntArray {
private:
    int *m_array {0};
    size_t m_size = 0;

public:
    IntArray (size_t size) : m_size(size) {
        assert(m_size > 0);
        m_array = new int[m_size] {0};
    }

    IntArray (const IntArray& otherArray) : m_size(otherArray.m_size) {
        m_size = otherArray.m_size;

        m_array = new int[m_size];

        for(size_t i(0); i < m_size; ++i) {
            m_array[i] = otherArray.m_array[i];
        }
    }

    ~IntArray () {
        delete[] m_array;
    }

    int& operator[] (const size_t index) {
        assert(index < m_size);
        return m_array[index];
    }

    IntArray& operator= (const IntArray& otherArray) {
        if (this == &otherArray) {
            return *this;
        }

        delete[] m_array;

        m_size = otherArray.m_size;

        if(otherArray.m_array) {
            m_array = new int[m_size];

            for(size_t i(0); i < m_size; ++i) {
                m_array[i] = otherArray.m_array[i];
            }
        }
        else {
            m_array = 0;
        }

        return *this;
    }

    friend std::ostream& operator<< (std::ostream &out, const IntArray &array);
};

std::ostream& operator<< (std::ostream &out, const IntArray &array) {
    for(size_t i(0); i < array.m_size; ++i) {
        out << array.m_array[i] << ' ';
    }

    return out;
}


IntArray fillArray() {
	IntArray a(5);
	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main() {
	IntArray a = fillArray();
	std::cout << a << '\n';

	IntArray b(1);
	a = a;
	b = a;

	std::cout << b << '\n';

	return 0;
}