#include <cmath>
#include <ctime>
#include "Image.hpp"
#include "pgm.hpp"

class Point2d {
private:
    double m_x;
    double m_y;

public:

    Point2d(int x = 0, int y = 0) : m_x(x), m_y(y) {}


    Point2d(const Point2d &otherpoint)
        : m_x(otherpoint.m_x), m_y(otherpoint.m_y) {
    }

    void print() {
        std::cout << "x: " << m_x
                  << " y: " << m_y
                  << '\n';
    }

    double distanceTo (Point2d otherPoint) {
        return sqrt((m_x - otherPoint.m_x)*(m_x - otherPoint.m_x) + (m_y - otherPoint.m_y)*(m_y - otherPoint.m_y));
    }

    void setX(const int& new_x) {
        m_x = new_x;
    }

    void setY(const int& new_y) {
        m_y = new_y;
    }

    friend double distanceFrom(Point2d, Point2d);

    friend class Rectangle2d;
};

double distanceFrom(Point2d startPoint, Point2d endPoint) {
    return sqrt(
                (startPoint.m_x - endPoint.m_x)*(startPoint.m_x - endPoint.m_x)
                + (startPoint.m_y - endPoint.m_y)*(startPoint.m_y - endPoint.m_y)
               );
}

int main() {
    srand(time(NULL));
    Image image;
    PGMBitmap I(512, 512);
    for(size_t i(0); i < 512; ++i) {
        for(size_t j(0); j < 512; ++j) {
            I.setPixel(i, j, image.m_pixels[i][j]);
        }
    }
    I.saveTo("randimg.pgm");
    return 0;
}