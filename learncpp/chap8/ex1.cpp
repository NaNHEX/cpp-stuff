#include <iostream>
#include <cmath>


class Point2d {
private:
    double m_x;
    double m_y;

public:

    Point2d(double x = 0.0, double y = 0.0) : m_x(x), m_y(y) {}

    void print() {
        std::cout << "x :" << m_x
                  << "y: " << m_y
                  << '\n';
    }

    double distanceTo (Point2d otherPoint) {
        return sqrt((m_x - otherPoint.m_x)*(m_x - otherPoint.m_x) + (m_y - otherPoint.m_y)*(m_y - otherPoint.m_y));
    }

    friend double distanceFrom(Point2d, Point2d);
};

double distanceFrom(Point2d startPoint, Point2d endPoint) {
    return sqrt(
                (startPoint.m_x - endPoint.m_x)*(startPoint.m_x - endPoint.m_x)
                + (startPoint.m_y - endPoint.m_y)*(startPoint.m_y - endPoint.m_y)
               );
}

int main() {
    Point2d first;
    Point2d second(3.0, 4.0);
    first.print();
    second.print();
    std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';

    return 0;
}