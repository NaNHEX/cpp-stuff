#pragma once
#include <vector>
#include <iostream>
#include "salaires.hpp"


class Personnel {
protected:
    std::vector<Employe*> m_personnel;

public:
    Personnel();

    Personnel(std::vector<Employe*> &personnel);

    void ajouter_employe(Employe* employe);

    void afficher_salaires() const;

    float salaire_moyen() const;

    void licencie();
};