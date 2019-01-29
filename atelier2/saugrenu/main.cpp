#include "promotion.hpp"

int main() {
    std::list<Etudiant> etudiants;
    etudiants.push_back(Etudiant("Wolf", "Einstein", 0));
    etudiants.push_back(Etudiant("Border", "Lands", 1));
    etudiants.push_back(Etudiant("Do", "Om", 2));

    //Default constructor test
    Promotion snap("SNAP", etudiants);
    for(const auto &etudiant : snap.getEtudiantList()) {
        std::cout << etudiant << '\n';
    }
    std::cout << snap.getNom() << '\n';

    //setEtudiant test
    etudiants.push_back(Etudiant("Stack", "Overflow", 3));
    etudiants.push_back(Etudiant("Cross", "Site", 4));
    snap.setEtudiantList(etudiants);
    for(const auto &etudiant : snap.getEtudiantList()) {
        std::cout << etudiant << '\n';
    }
    std::cout << '\n';

    //Copy constructor test
    Promotion snap2;
    for(const auto &etudiant : snap2.getEtudiantList()) {
        std::cout << etudiant << '\n';
    }

    snap2 = snap;
    for(const auto &etudiant : snap2.getEtudiantList()) {
        std::cout << etudiant << '\n';
    }
    std::cout << snap2.getNom() << '\n';
/*     Promotion test;
    for(const auto &etudiant : test.getEtudiantSet()) {
        std::cout << etudiant << '\n';
    } */
    return 0;
}