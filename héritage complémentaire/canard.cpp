#include "canard.hpp"

Canard::Canard() : Volaille() {}

Canard::Canard(const unsigned &id = 0, const unsigned &masse = 0, const unsigned &prix = 0)
                : Volaille(id, masse, prix) {}

const std::string Canard::getType() const {
    return "canard";
}