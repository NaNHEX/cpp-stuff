#include "rectangleNd.hpp"

RectangleNd::RectangleNd() {}

RectangleNd::RectangleNd(const PointNd &A, const PointNd &B) {
    m_A = A;
    m_B = B;
}

PointNd RectangleNd::getA() const{
    return m_A;
}

PointNd RectangleNd::getB() const {
    return m_B;
}

void RectangleNd::setA(const PointNd &A) {
    m_A = A;
}

void RectangleNd::setB(const PointNd &B) {
    m_B = B;
}

RectangleNd& RectangleNd::operator=(const RectangleNd &otherRectangle) {
    m_A = otherRectangle.m_A;
    m_B = otherRectangle.m_B;
    return *this;
}


bool operator==(RectangleNd &rectangle, RectangleNd&otherRectangle) {
    if(rectangle.m_A == otherRectangle.m_A && rectangle.m_B == otherRectangle.m_B)
        return true;
    return false;
}

bool operator!=(RectangleNd &rectangle, RectangleNd &otherRectangle) {
    return !(rectangle == otherRectangle);
}

std::ostream& operator<<(std::ostream &out, const RectangleNd &rectangle) {
    out << rectangle.m_A << " ; " << rectangle.m_B;
    return out;
}

std::istream& operator>>(std::istream &in, RectangleNd &rectangle) {
    in >> rectangle.m_A;
    in >> rectangle.m_B;
    return in;
}