#pragma once
#include "etudiant.hpp"
#include <list>
#include <set>

class Promotion {
private:
    std::string m_nom;
    std::list<Etudiant> m_list_etudiants;
    std::set<Etudiant> m_set_etudiants;

public:
    Promotion();

    Promotion(const std::string &nom, const std::list<Etudiant> &etudiants);

    Promotion(const std::string &nom, const std::set<Etudiant> &etudiants);

    const std::string& getNom() const;

    void setNom(std::string &nom);

    const std::list<Etudiant>& getEtudiantList() const;

    void setEtudiantList(const std::list<Etudiant> &etudiants);

    const std::set<Etudiant>& getEtudiantSet() const;

    void setEtudiantSet(const std::set<Etudiant> &etudiants);
};