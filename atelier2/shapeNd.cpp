#include "shapeNd.hpp"

ShapeNd::ShapeNd() {}

size_t ShapeNd::getD() const {
    return points.size();
}

void ShapeNd::addPoint(const PointNd &point) {
    points.push_back(point);
}

void ShapeNd::removePoint(const size_t &index) {
    assert(index < points.size());
    points.erase(points.begin() + static_cast<long int>(index));
}

PointNd ShapeNd::operator[](const size_t &index) const {
    assert(index < points.size());
    return points[index];
}

PointNd& ShapeNd::operator[](const size_t &index) {
    assert(index < points.size());
    return points[index];
}

bool operator==(const ShapeNd &shape1, const ShapeNd &shape2) {
    if(shape1.points.size() != shape2.points.size())
        return false;

    for(size_t i(0); i < shape1.points.size(); ++i) {
        if(shape1.points[i] != shape2.points[i])
            return false;
    }
    return true;
}

bool operator!=(const ShapeNd &shape1, const ShapeNd &shape2) { return !(shape1 == shape2); }

std::ostream& operator<<(std::ostream &out, const ShapeNd &shape) {
    for(size_t i(0); i < shape.points.size(); ++i) {
        out << shape.points[i] << " ; ";
    }
    return out;
}