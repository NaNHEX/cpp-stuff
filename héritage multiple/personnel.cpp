#include "personnel.hpp"

Personnel::Personnel() {}

Personnel::Personnel(std::vector<Employe*> &personnel) {
    m_personnel = personnel;
    personnel.clear();
}

void Personnel::ajouter_employe(Employe* employe) {
    m_personnel.push_back(employe);
}

void Personnel::afficher_salaires() const {
    for(const auto &employe : m_personnel) {
        std::cout << employe->getNom() << " gagne " << employe->calculer_salaire() << " euros.\n";
    }
}

float Personnel::salaire_moyen() const {
    float salaire_moyen = 0;
    for(const auto &employe : m_personnel) {
        salaire_moyen += employe->calculer_salaire();
    }
    salaire_moyen /= m_personnel.size();
    return salaire_moyen;
}

void Personnel::licencie() {
    for(const auto &employe : m_personnel) {
        delete employe;
    }
}