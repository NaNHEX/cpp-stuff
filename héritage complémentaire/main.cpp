#include <iostream>
#include "fermier.hpp"
#include "poulet.hpp"
#include "canard.hpp"


int main() {
    std::vector<Volaille *> volailles;
    volailles.push_back(new Poulet(1, 1.5, 12));
    volailles.push_back(new Canard(5, 1.2, 25));

    Fermier fredon(volailles);
    std::cout << "La volaille numéro 1 est de type " << fredon.getTypeVolaille(0) << '\n';
    std::cout << "La volaille numéro 2 est de type " << fredon.getTypeVolaille(1) << '\n';
    std::cout << "Le prix total des volailles est de " << fredon.getPrixTotal() << " euros.\n";

    for(const auto &volaille : volailles) {
        volaille->setId(42);
        volaille->setMasse(4.2);
        volaille->setPrix(42);
        std::cout << volaille->getId() << " " << volaille->getMasse() << " " << volaille->getPrix() << "\n";
        delete volaille;
    }
    return 0;
}