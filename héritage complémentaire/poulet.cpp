#include "poulet.hpp"

Poulet::Poulet() : Volaille() {}

Poulet::Poulet(const unsigned &id, const unsigned &masse, const unsigned &prix)
                : Volaille(id, masse, prix) {}

const std::string Poulet::getType() const {
    return "poulet";
}