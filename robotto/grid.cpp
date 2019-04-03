#include "grid.hpp"

Grid::Grid() {
    m_grid.clear();

    for(size_t i = 0; i < m_lines; ++i) {
        for(size_t j = 0; j < m_columns; ++j) {
            m_grid.push_back(new Cell(i, j));
        }
    }
}

Grid::Grid(const size_t &x, const size_t &y) {
    m_grid.clear();
    if(x <= MAX_LINES)
        m_lines = x;
    if(y <= MAX_COLUMNS)
        m_columns = y;

    for(size_t i = 0; i < m_lines; ++i) {
        for(size_t j = 0; j < m_columns; ++j) {
            if(rand() % 2 == 1) {
                m_grid.push_back(new Cell(i, j, true));
            }
            else {
                m_grid.push_back(new Cell(i, j));
            }
        }
    }
}

Grid::~Grid() {
    for(const auto &cell : m_grid) {
        delete(cell);
    }
}

Cell* Grid::operator[](const size_t index) {
    if(index > m_grid.size()) {
        throw std::runtime_error("Error : out of bounds access to grid\n");
    }
    return m_grid[index];
}

Cell* Grid::operator[](const size_t index) const {
    if(index > m_grid.size()) {
        throw std::runtime_error("Error : out of bounds access to grid\n");
    }
    return m_grid[index];
}

std::ostream& operator<<(std::ostream &out, const Grid &grid) {
    for(size_t i = 0; i < grid.m_grid.size(); ++i) {
            if(i % grid.m_columns == 0) {
                    out << '\n';
            }
            out << grid[i];
    }
    return out;
}