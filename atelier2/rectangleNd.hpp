#pragma once
#include "pointNd.hpp"

class RectangleNd {
private:
    PointNd m_A, m_B;

public:
    RectangleNd();

    RectangleNd(const PointNd&, const PointNd&);

    PointNd getA() const;

    PointNd getB() const;

    void setA(const PointNd&);

    void setB(const PointNd&);

    RectangleNd& operator=(const RectangleNd&);

    friend bool operator==(RectangleNd&, RectangleNd&);

    friend bool operator!=(RectangleNd&, RectangleNd&);

    friend std::ostream& operator<<(std::ostream&, const RectangleNd&);

    friend std::istream& operator>>(std::istream&, RectangleNd&);
};