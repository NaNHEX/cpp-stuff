#pragma once
#include <iostream>

class Point_2D {
private:
    double m_x;
    double m_y;

public:
    Point_2D();

    Point_2D(double x, double y);

    const double& getX() const;

    const double& getY() const;

    void setX(const int &new_x);

    void setY(const int &new_y);

    friend std::ostream& operator<<(std::ostream &out, const Point_2D &point);

    friend std::istream& operator>>(std::istream &in, Point_2D &point);
};