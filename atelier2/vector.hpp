#pragma once
#include "point2d.hpp"

class Vector {
private:
    Point2d m_A, m_B;

public:
    Vector(const Point2d &A, const Point2d &B);

    Vector& operator=(const Vector &vector);

//    friend bool operator==(const Vector &vector, const Vector &otherVector);

//    friend bool operator!=(const Vector &vector, const Vector &otherVector);

    friend std::ostream& operator<<(std::ostream &out, const Vector &vector);
};