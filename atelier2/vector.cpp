#include "vector.hpp"

Vector::Vector(const Point2d &A, const Point2d &B) {
    m_A = A;
    m_B = B;
}

Vector& Vector::operator=(const Vector &vector) {
    m_A = vector.m_A;
    m_B = vector.m_B;
    return *this;
}

/* bool operator==(const Vector &vector, const Vector &otherVector) {
    float scalarProduct = (vector.m_B.m_x - vector.m_A.m_x)*(otherVector.m_B.m_x - otherVector.m_A.m_x)
                            + (vector.m_B.m_y - vector.m_A.m_y)*(otherVector.m_B.m_y - otherVector.m_A.m_y);

    return (scalarProduct == 0.0);
} */

//bool operator!=(const Vector &vector, const Vector &otherVector) { return !(vector == otherVector); }

std::ostream& operator<<(std::ostream &out, const Vector &vector) {
    out << vector.m_A << vector.m_B;
    return out;
}