#pragma once
#include <string>
#include "personnel.hpp"


class Vendeur : public Employe {
private:
    float m_chiffre_daffaire;

public:
    Vendeur();

    Vendeur(const std::string &prenom,
            const std::string &nom,
            const std::string &date,
            const bool &a_risque,
            const float &chiffre_daffaire);

    virtual float calculer_salaire() const override;

    virtual std::string getNom() const;
};