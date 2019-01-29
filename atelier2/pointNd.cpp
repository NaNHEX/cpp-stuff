#include "pointNd.hpp"

PointNd::PointNd() {
    PointNd(0, 3);
}

PointNd::PointNd(const float &defaultValue, const size_t &n) {
    m_dimension = n;
    for(size_t i(0); i < m_dimension; ++i)
        m_coord.push_back(defaultValue);
}

size_t PointNd::getDimension() const {
    return m_dimension;
}

void PointNd::addCoord(const float &element) {
    m_coord.push_back(element);
    ++m_dimension;
}

void PointNd::removeCoord(const size_t &index) {
    assert(index < m_dimension);
    m_coord.erase(m_coord.begin() + static_cast<long int>(index));
}

float PointNd::operator[](const size_t &index) const {
    assert(index < m_dimension);
    return m_coord[index];
}

float& PointNd::operator[](const size_t &index) {
    assert(index < m_dimension);
    return m_coord[index];
}

PointNd& PointNd::operator=(const PointNd &otherPoint) {
    m_coord.clear();

    if(m_dimension != otherPoint.m_dimension)
        m_dimension = otherPoint.m_dimension;

    for(size_t i(0); i < m_dimension; ++i) {
        m_coord.push_back(otherPoint.m_coord[i]);
    }

    return *this;
}

bool operator==(const PointNd &point1, const PointNd &point2) {
    if(point1.m_dimension != point2.m_dimension)
        return false;

    for(size_t i(0); i < point1.m_dimension; ++i) {
        if(point1.m_coord[i] != point2.m_coord[i])
            return false;
    }
    return true;
}

bool operator!=(const PointNd &point1, const PointNd &point2) { return !(point1 == point2); }

std::ostream& operator<<(std::ostream &out, const PointNd &point) {
    out << "[";
    for (size_t i(0); i < point.m_dimension; ++i) {
        out << point.m_coord[i];
        if(i != (point.m_dimension - 1))
            out << ", ";
    }
    out << "] dimension : " << point.m_dimension;
    return out;
}

std::istream& operator>>(std::istream &in, PointNd &point) {
    std::cout << "dimension : ";
    in >> point.m_dimension;
    point.m_coord.clear();

    for(size_t i(0); i < point.m_dimension; ++i) {
        float coord;
        in >> coord;
        point.m_coord.push_back(coord);
    }
    return in;
}