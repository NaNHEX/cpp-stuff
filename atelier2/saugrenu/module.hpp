#pragma once
#include "etudiant.hpp"
#include <vector>

class Module {
private:
    unsigned m_numero;
    std::vector<Etudiant> m_etudiants;

public:
    Module();

    Module(const unsigned &numero, const std::vector<Etudiant> &etudiants);

    const unsigned& getNumero();

    void setNumero(const unsigned &numero);

    const Etudiant& getEtudiant(size_t n);

    void setEtudiant(size_t n, const Etudiant &etudiant);

    friend std::ostream& operator<<(std::ostream &out, const Module &module);

    friend std::istream& operator>>(std::istream &in, Module &module);
};