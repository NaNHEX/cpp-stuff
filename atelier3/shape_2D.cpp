#include "shape_2D.hpp"


Shape_2D::Shape_2D() {
    m_points.push_back(Point_2D());
}

Shape_2D::Shape_2D(const std::vector<Point_2D> &points) {
    m_points = points;
}

Shape_2D::~Shape_2D() {}

const std::vector<Point_2D>& Shape_2D::getPoints() const {
    return m_points;
}

void Shape_2D::setPoints(const std::vector<Point_2D> &points) {
    m_points = points;
}