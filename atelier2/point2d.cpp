#include "point2d.hpp"

Point2d::Point2d() : m_x(-1), m_y(-1) {}

Point2d::Point2d(int x = 0, int y = 0) : m_x(x), m_y(y) {}

Point2d::Point2d(const Point2d &otherpoint)
    : m_x(otherpoint.m_x), m_y(otherpoint.m_y) {
}

void Point2d::setX(const int& new_x) {
    m_x = new_x;
}

void Point2d::setY(const int& new_y) {
    m_y = new_y;
}

Point2d& Point2d::operator=(const Point2d &point) {
    m_x = point.m_x;
    m_y = point.m_y;
    return *this;
}

std::ostream& operator<<(std::ostream &out, const Point2d &point) {
    out << "x: " << point.m_x
            << " y: " << point.m_y
            << '\n';
    return out;
}

std::istream& operator>>(std::istream &in, Point2d &point) {
    float x, y;
    in >> x >> y;
    point.m_x = x;
    point.m_y = y;
    return in;
}