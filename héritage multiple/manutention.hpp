#pragma once
#include "salaires.hpp"


class Manutentionnaire : public Employe {
private:
    unsigned m_nb_heures;

public:
    Manutentionnaire();

    Manutentionnaire(const std::string &prenom,
                     const std::string &nom,
                     const std::string &date,
                     const bool &a_risque,
                     const unsigned &nb_heures);

    virtual float calculer_salaire() const override;

    virtual std::string getNom() const;
};