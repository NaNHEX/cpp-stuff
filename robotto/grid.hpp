#pragma once
#include <iostream>
#include <random>
#include "cell.hpp"

class Grid {
private:
    std::vector<Cell *> m_grid;
    size_t m_lines = 10;
    size_t m_columns = 10;
    size_t MAX_LINES = 50;
    size_t MAX_COLUMNS = 50;

public:
    Grid();

    Grid(const size_t &x, const size_t &y);

    ~Grid();

    Cell* operator[](const size_t index);

    Cell* operator[](const size_t index) const;

    friend std::ostream& operator<<(std::ostream &out, const Grid &grid);
};
