#include "shape_2D.hpp"

class Rectangle_2D : public Shape_2D {
public:
    Rectangle_2D();

    Rectangle_2D(const std::vector<Point_2D> &points);

    Rectangle_2D(const Point_2D &a,
                    const Point_2D &b,
                    const Point_2D &c,
                    const Point_2D &d);

    virtual void print() const override;
};