#pragma once
#include <vector>
#include <cassert>
#include <iostream>

class PointNd {
private:
    std::vector<float> m_coord;
    size_t m_dimension;

public:
    PointNd();

    PointNd(const float &defaultValue, const size_t &dimension);

    size_t getDimension() const;

    void addCoord(const float &element);

    void removeCoord(const size_t &index);

    float operator[](const size_t &index) const;

    float& operator[](const size_t &index);

    PointNd& operator=(const PointNd&);

    friend bool operator==(const PointNd &point1, const PointNd &point2);

    friend bool operator!=(const PointNd &point1, const PointNd &point2);

    friend std::ostream& operator<<(std::ostream &out, const PointNd &point);

    friend std::istream& operator>>(std::istream &in, PointNd &point);
};