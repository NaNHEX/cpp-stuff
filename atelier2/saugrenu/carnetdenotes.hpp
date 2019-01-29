#pragma once
#include "etudiant.hpp"
#include "module.hpp"
#include <map>
#include <list>

class Carnet {
private:
    std::list<int> m_notes;
    std::map<Module, int> m_notes_map;
    Etudiant m_etudiant;

public:
    Carnet();

    Carnet(const std::list<int> &notes, const Etudiant &etudiant);

    Carnet(const std::map<Module, int> &notes, const Etudiant &etudiant);

    const Etudiant& getEtudiant();

    void setEtudiant(const Etudiant &etudiant);

    const std::list<int>& getNotes();

    void setNotes(const std::list<int> &notes);
};