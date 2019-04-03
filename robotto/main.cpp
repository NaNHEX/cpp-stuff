#include <iostream>
#include <random>
#include <chrono>
#include "grid.hpp"

int main() {
    srand(time(NULL));

    Grid grid(50, 50);

    std::cout << grid << '\n';
    return 0;
}