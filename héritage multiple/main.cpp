#include <iostream>
#include "personnel.hpp"
#include "vendeur.hpp"
#include "representation.hpp"
#include "production.hpp"
#include "manutention.hpp"

int main() {
    Personnel p;
    p.ajouter_employe(new Vendeur("Pierre", "Business", "1995", false, 30000));
    p.ajouter_employe(new Representant("Léon", "Vendtout", "2001", false, 20000));
    p.ajouter_employe(new Technicien("Yves", "Bosseur", "1998", false, 1000));
    p.ajouter_employe(new Manutentionnaire("Jeanne", "Stocketout", "1998", false, 45));
    p.ajouter_employe(new Technicien("Jean", "Flippe", "2000", true, 1000));
    p.ajouter_employe(new Manutentionnaire("Al", "Abordage", "2001", true, 45));
    p.afficher_salaires();
    std::cout << "Le salaire moyen dans l’entreprise est de " << p.salaire_moyen() << " euros.\n";
    // libération mémoire
    p.licencie();
    return 0;
}