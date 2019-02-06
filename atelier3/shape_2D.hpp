#pragma once
#include "point_2D.hpp"
#include <vector>


class Shape_2D {
protected:
    std::vector<Point_2D> m_points;

public:
    Shape_2D();

    Shape_2D(const std::vector<Point_2D> &points);

    virtual ~Shape_2D();

    const std::vector<Point_2D>& getPoints() const;

    void setPoints(const std::vector<Point_2D> &points);

    virtual void print() const = 0;
};