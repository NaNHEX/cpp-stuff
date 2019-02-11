#include "fermier.hpp"

Fermier::Fermier() {}

Fermier::Fermier(const std::vector<Volaille*> &volailles) {
    m_volailles = volailles;
}

void Fermier::setVolailles(const std::vector<Volaille*> &volailles) {
    m_volailles = volailles;
}

const std::vector<Volaille*>& Fermier::getVolailles() const {
    return m_volailles;
}

size_t Fermier::getNbVolailles() const {
    return m_volailles.size();
}

const std::string Fermier::getTypeVolaille(unsigned index) const {
    if(index < m_volailles.size()) {
        return m_volailles[index]->getType();
    }
    else {
        return "error";
    }
}

float Fermier::getPrixTotal() const {
    float total = 0;
    for(const auto &volaille : m_volailles) {
        total += volaille->getPrix() * volaille->getMasse();
    }
    return total;
}