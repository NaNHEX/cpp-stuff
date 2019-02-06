#include "point_2D.hpp"

Point_2D::Point_2D() : m_x(-1.0), m_y(-1.0) {}

Point_2D::Point_2D(double x, double y) : m_x(x), m_y(y) {}

const double& Point_2D::getX() const {
    return m_x;
}

const double& Point_2D::getY() const {
    return m_y;
}

void Point_2D::setX(const int &new_x) {
    m_x = new_x;
}

void Point_2D::setY(const int &new_y) {
    m_y = new_y;
}

std::ostream& operator<<(std::ostream &out, const Point_2D &point) {
    out << "(" << point.m_x
            << " , " << point.m_y
            << ");";
    return out;
}

std::istream& operator>>(std::istream &in, Point_2D &point) {
    float x, y;
    in >> x >> y;
    point.m_x = x;
    point.m_y = y;
    return in;
}