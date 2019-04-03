#include "cell.hpp"

Cell::Cell(const int &x, const int &y, const bool isWall)
        : m_x(x), m_y(y), m_isWall(isWall) {}

const int& Cell::getX() const {
    return m_x;
}

    const int& Cell::getY() const {
    return m_y;
}

bool Cell::isWall() const {
    return m_isWall;
}

void Cell::setWall() {
    m_isWall = true;
}

void Cell::unsetWall() {
    m_isWall = false;
}

std::ostream& operator<<(std::ostream &out, const Cell *cell) {
    if(cell->isWall())
        out << " | ";
    else
        out << "   ";
    return out;
}