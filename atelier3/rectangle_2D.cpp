#include "rectangle_2D.hpp"


Rectangle_2D::Rectangle_2D() : Shape_2D() {

}

Rectangle_2D::Rectangle_2D(const std::vector<Point_2D> &points) : Shape_2D(points) {}

Rectangle_2D::Rectangle_2D(const Point_2D &a,
                            const Point_2D &b,
                            const Point_2D &c,
                            const Point_2D &d) : Shape_2D() {
    m_points.clear();
    m_points.push_back(a);
    m_points.push_back(b);
    m_points.push_back(c);
    m_points.push_back(d);
}

void Rectangle_2D::print() const {
    std::cout << "Je suis un rectangle:\n[ ";
    for(const auto &point : m_points) {
        std::cout << point << " ";
    }
    std::cout << "]";
}