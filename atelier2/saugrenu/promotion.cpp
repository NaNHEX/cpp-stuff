#include "promotion.hpp"

Promotion::Promotion() {
    m_nom = "default";
    m_list_etudiants.push_back(Etudiant());
    m_set_etudiants.insert(Etudiant());
}

Promotion::Promotion(const std::string &nom, const std::list<Etudiant> &etudiants) {
    m_nom = nom;
    m_list_etudiants = etudiants;
}

Promotion::Promotion(const std::string &nom, const std::set<Etudiant> &etudiants) {
    m_nom = nom;
    m_set_etudiants = etudiants;
}

const std::string& Promotion::getNom() const {
    return m_nom;
}

void Promotion::setNom(std::string &nom) {
    m_nom = nom;
}

const std::list<Etudiant>& Promotion::getEtudiantList() const {
    return m_list_etudiants;
}

void Promotion::setEtudiantList(const std::list<Etudiant> &etudiants) {
    m_list_etudiants = etudiants;
}

const std::set<Etudiant>& Promotion::getEtudiantSet() const {
    return m_set_etudiants;
}

void Promotion::setEtudiantSet(const std::set<Etudiant> &etudiants) {
    m_set_etudiants = etudiants;
}