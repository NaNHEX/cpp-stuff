#include "salaires.hpp"

Employe::Employe() {
    m_prenom = "Default";
    m_nom = "Default";
    m_date = "Default";
    m_a_risque = false;
}

Employe::Employe(const std::string &prenom, const std::string &nom, const std::string &date, const bool &a_risque) {
    m_prenom = prenom;
    m_nom = nom;
    m_date = date;
    m_a_risque = a_risque;
}

Employe::~Employe() {}

std::string Employe::getNom() const {
    return "L'employé " + m_prenom + " " + m_nom;
}