#include "carnetdenotes.hpp"

Carnet::Carnet() {

}

Carnet::Carnet(const std::list<int> &notes, const Etudiant &etudiant) {
    m_notes = notes;
    m_etudiant = etudiant;
}

Carnet::Carnet(const std::map<Module, int> &notes, const Etudiant &etudiant) {
    m_notes_map = notes;
    m_etudiant = etudiant;
}

const Etudiant& Carnet::getEtudiant() {
    return m_etudiant;
}

void Carnet::setEtudiant(const Etudiant &etudiant) {
    m_etudiant = etudiant;
}

const std::list<int>& Carnet::getNotes() {
    return m_notes;
}

void Carnet::setNotes(const std::list<int> &notes) {
    m_notes = notes;
}