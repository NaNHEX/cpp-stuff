#include "manutention.hpp"

Manutentionnaire::Manutentionnaire() : Employe() {

}

Manutentionnaire::Manutentionnaire(const std::string &prenom,
                                   const std::string &nom,
                                   const std::string &date,
                                   const bool &a_risque,
                                   const unsigned &nb_heures)
                                : Employe(prenom, nom, date, a_risque) {
    m_nb_heures = nb_heures;
}

float Manutentionnaire::calculer_salaire() const {
    float salaire = m_nb_heures * 65;
    if(m_a_risque) { return salaire + 100; }
    else { return salaire ; }
}

std::string Manutentionnaire::getNom() const {
    return "Le manutentionnaire " + m_prenom + " " + m_nom;
}