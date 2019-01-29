#include "etudiant.hpp"

Etudiant::Etudiant(){
    m_nom = "Toto";
    m_prenom = "Tutu";
    m_numero = 0;
}

Etudiant::Etudiant(const std::string &nom, const std::string &prenom, const unsigned &numero) {
    m_nom = nom;
    m_prenom = prenom;
    m_numero = numero;
}

const std::string& Etudiant::getNom() const {
    return m_nom;
}

void Etudiant::setNom(const std::string &nom) {
    m_nom = nom;
}

const std::string& Etudiant::getPrenom()const {
    return m_prenom;
}

void Etudiant::setPrenom(const std::string &prenom) {
    m_prenom = prenom;
}

const unsigned& Etudiant::getNumero() const {
    return m_numero;
}

void Etudiant::setNumero(const unsigned &numero) {
    m_numero = numero;
}

std::ostream& operator<<(std::ostream &out, const Etudiant &etudiant) {
    out << "[ "
        << etudiant.m_nom
        << ", "
        << etudiant.m_prenom
        << ", "
        << etudiant.m_numero << " ]";
        return out;
}

std::istream& operator>>(std::istream &in, Etudiant &etudiant) {
    std::cout << "Nom : ";
    in >> etudiant.m_nom;
    std::cout << "Prenom : ";
    in >> etudiant.m_prenom;
    std::cout << "Numero : ";
    in >> etudiant.m_numero;
    return in;
}

bool operator<(const Etudiant letudiant, const Etudiant retudiant) {
    return (letudiant.getNumero() < retudiant.getNumero());
}