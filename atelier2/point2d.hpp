#pragma once
#include <iostream>

class Point2d {
private:
    double m_x;
    double m_y;

public:
    Point2d();

    Point2d(int x, int y);

    Point2d(const Point2d &otherpoint);

    void setX(const int& new_x);

    void setY(const int& new_y);

    Point2d& operator=(const Point2d &point);

    friend std::ostream& operator<<(std::ostream &out, const Point2d &point);

    friend std::istream& operator>>(std::istream &in, Point2d &point);
};