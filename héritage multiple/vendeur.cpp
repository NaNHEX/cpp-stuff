#include "vendeur.hpp"

Vendeur::Vendeur() : Employe() {
    m_chiffre_daffaire = 0;
}

Vendeur::Vendeur(const std::string &prenom,
                 const std::string &nom,
                 const std::string &date,
                 const bool &a_risque,
                 const float &chiffre_daffaire)
                 : Employe(prenom, nom, date, a_risque) {
    m_chiffre_daffaire = chiffre_daffaire;
}

float Vendeur::calculer_salaire() const {
    float salaire = 0.2 * m_chiffre_daffaire + 400;
    if(m_a_risque) { return salaire + 100; }
    else { return salaire; }
}

std::string Vendeur::getNom() const {
    return "Le vendeur " + m_prenom + " " + m_nom;
}