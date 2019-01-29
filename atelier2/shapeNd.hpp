#pragma once
#include "pointNd.hpp"

class ShapeNd {
private:
    std::vector<PointNd> points;

public:
    ShapeNd();

    size_t getD() const;

    void addPoint(const PointNd &point);

    void removePoint(const size_t &index);

    PointNd operator[](const size_t &index) const;

    PointNd& operator[](const size_t &index);

    friend bool operator==(const ShapeNd &point1, const ShapeNd &point2);

    friend bool operator!=(const ShapeNd &point1, const ShapeNd &point2);

    friend std::ostream& operator<<(std::ostream &out, const ShapeNd &shape);
};