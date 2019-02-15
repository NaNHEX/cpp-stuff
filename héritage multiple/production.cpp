#include "production.hpp"

Technicien::Technicien() : Employe() {
    m_unites_produites = 0;
}

Technicien::Technicien(const std::string &prenom,
                       const std::string &nom,
                       const std::string &date,
                       const bool &a_risque,
                       const unsigned &unites_produites)
                       : Employe(prenom, nom, date, a_risque) {
    m_unites_produites = unites_produites;
}

float Technicien::calculer_salaire() const {
    float salaire = m_unites_produites * 5;
    if(m_a_risque) { return salaire + 100; }
    else { return salaire ; }
}

std::string Technicien::getNom() const {
    return "Le technicien " + m_prenom + " " + m_nom;
}