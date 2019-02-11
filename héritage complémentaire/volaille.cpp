#include "volaille.hpp"

Volaille::Volaille() {
    m_id = 0;
    m_masse = 0;
    m_prix = 0;
}

Volaille::Volaille(const unsigned &id, const unsigned &masse, const unsigned &prix) {
    m_id = id;
    m_masse = masse;
    m_prix = prix;
}

Volaille::~Volaille() {}

void Volaille::setId(const unsigned &id) {
    m_id = id;
}

void Volaille::setMasse(const float &masse) {
    m_masse = masse;
}

void Volaille::setPrix(const float &prix) {
    m_prix = prix;
}

const unsigned& Volaille::getId() const {
    return m_id;
}

const float& Volaille::getMasse() const {
    return m_masse;
}

const float& Volaille::getPrix() const {
    return m_prix;
}