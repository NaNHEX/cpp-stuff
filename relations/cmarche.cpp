#pragma once
#include <iostream>
#include "cmarche.hpp"

cmarche::cmarche() {}

cmarche::~cmarche() {}

const csac& cmarche::getSac() {
    return m_sac;
}

void cmarche::setSac(const csac &sac) {
    m_sac = sac;
}

void cmarche::affiche() {
    std::cout << "marché ";
}