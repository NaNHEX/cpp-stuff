#pragma once
#include <iostream>
#include <string>

class Etudiant {
private:
    std::string m_nom;
    std::string m_prenom;
    unsigned m_numero;

public:
    Etudiant();

    Etudiant(const std::string &nom, const std::string &prenom, const unsigned &numero);

    const std::string& getNom() const;

    void setNom(const std::string &nom);

    const std::string& getPrenom() const;

    void setPrenom(const std::string &prenom);

    const unsigned& getNumero() const;

    void setNumero(const unsigned &numero);

    friend std::ostream& operator<<(std::ostream &out, const Etudiant &etudiant);

    friend std::istream& operator>>(std::istream &in, Etudiant &etudiant);
};