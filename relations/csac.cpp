#include "csac.hpp"

csac::csac() {
    m_poigne = new cpoigne;
}

csac::~csac() {
    delete m_poigne;
}
const cmarche& csac::getMarche() const {
    return m_marche;
}

const cpoire& csac::getPoire() const {
    return m_poire;
}

const cpoigne* const csac::getPoigne() const {
    return m_poigne;
}

void csac::setMarche(const cmarche &marche) {
    m_marche = marche;
}

void csac::setPoire(const cpoire &poire) {
    m_poire = poire;
}

void csac::setPoigne(cpoigne* poigne) {
    delete m_poigne;
    m_poigne = poigne;
}

void csac::afficheMembre() {
    m_marche.affiche();
    m_poire.affiche();
    m_poigne->affiche();
}