#include "module.hpp"
#include <cassert>

Module::Module() {
    m_numero = 0;
    m_etudiants.clear();
    m_etudiants.push_back(Etudiant());
}

Module::Module(const unsigned &numero, const std::vector<Etudiant> &etudiants) {
    m_numero = numero;

    m_etudiants.clear();
    for(const auto &element : etudiants) {
        m_etudiants.push_back(element);
    }
}

const unsigned& Module::getNumero() {
    return m_numero;
}

void Module::setNumero(const unsigned &numero) {
    m_numero = numero;
}

const Etudiant& Module::getEtudiant(size_t n) {
    assert(n < m_etudiants.size());
    return m_etudiants[n];
}

void Module::setEtudiant(size_t n, const Etudiant &etudiant) {
    assert(n < m_etudiants.size());
    m_etudiants[n] = etudiant;
}

std::ostream& operator<<(std::ostream &out, const Module &module) {
    out << "{ " << module.m_numero << ", ";
    for(const auto &element : module.m_etudiants) {
        out << element << " ; ";
    }
    out << " }";
    return out;
}

std::istream& operator>>(std::istream &in, Module &module) {
    std::cout << "Numero : ";
    in >> module.m_numero;

    std::cout << "Nombre d'étudiants : ";
    size_t n;
    in >> n;

    Etudiant etudiant;
    for(size_t i = 0; i < n; ++i) {
        in >> etudiant;
        module.m_etudiants.push_back(etudiant);
    }
    return in;
}