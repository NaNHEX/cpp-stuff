#include "rectangle_2D.hpp"


int main() {
    std::vector<Point_2D> points;
    points.push_back(Point_2D(42.0, 42.0));
    Rectangle_2D rect(points);
    rect.print();
    return 0;
}