#pragma once
#include "salaires.hpp"

class Technicien : public Employe {
private:
    unsigned m_unites_produites;

public:
    Technicien();

    Technicien(const std::string &prenom,
               const std::string &nom,
               const std::string &date,
               const bool &a_risque,
               const unsigned &unites_produites);

    virtual float calculer_salaire() const override;

    virtual std::string getNom() const;
};