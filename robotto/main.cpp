#include <iostream>
#include <random>
#include <chrono>

enum Colors {
    RED,
    YELLOW,
    BLUE,
    GREEN,
    WHITE,
    BLACK,
    PINK,
    PURPLE,
    ORANGE
};

class Cell {
private:
    int m_x;
    int m_y;
    bool m_collision = false;

public:
    Cell() {
    }

    Cell(const int &x, const int &y, const bool collision = false)
        : m_x(x), m_y(y), m_collision(collision) {}

    const int& getX() const {
        return m_x;
    }

    void setX(const int &x) {
        m_x = x;
    }

    const int& getY() const {
        return m_y;
    }

    void setY(const int &y) {
        m_y = y;
    }

    const bool hasCollision() const {
        return m_collision;
    }

    void setCollision(const bool collision) {
        m_collision = collision;
    }
};

class Grid {
private:
    std::vector<Cell> grid;

public:
    Grid() {
    }

    Grid(const size_t &x, const size_t &y) {
        grid.clear();
        for(size_t i = 0; i < x; ++i) {
            for(size_t j = 0; j < y; ++i) {
                grid.push_back(Cell(i, j));
            }
        }


    }
};

class Robot {
public:
    virtual ~Robot () {}

    virtual void move () = 0;

    virtual std::ostream& print (std::ostream &out) const = 0;

    friend std::ostream& operator<< (std::ostream &out, const Robot &bot) {
        return bot.print(out);
    }
};

class Randbot : public Robot {
private:
    int m_x;
    int m_y;

public:
    Randbot (int x, int y)
        : m_x(x), m_y(y)
    {
    }

    virtual void move () override {

    }

    virtual std::ostream& print (std::ostream &out) const override {
        out << '(' << m_x << ", " << m_y << ')';
        return out;
    }
};

class Leftbot : public Robot {
private:
    int m_x;
    int m_y;

public:
    Leftbot (int x, int y)
        : m_x(x), m_y(y)
    {
    }

    virtual void move () override {

    }

    virtual std::ostream& print (std::ostream &out) const override {
        out << '(' << m_x << ", " << m_y << ')';
        return out;
    }
};

int main () {
    srand(time(NULL));


    Randbot bot(0, 0);
    for (int i(0); i < 200; ++i) {
        bot.move();
        std::cout << bot << '\n';
    }

    return 0;
}