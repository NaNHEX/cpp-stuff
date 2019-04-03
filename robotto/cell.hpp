#pragma once
#include <iostream>

class Cell {
private:
    int m_x;
    int m_y;
    bool m_isWall = false;
    Cell() {}

public:
    Cell(const int &x, const int &y, const bool isWall = false);

    const int& getX() const;

    const int& getY() const;

    bool isWall() const;

    void setX(const int &x);

    void setY(const int &y);

    void setWall();

    void unsetWall();

    friend std::ostream& operator<<(std::ostream &out, const Cell *cell);
};