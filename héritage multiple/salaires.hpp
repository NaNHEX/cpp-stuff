#pragma once
#include <string>


class Employe {
protected:
    std::string m_prenom;
    std::string m_nom;
    std::string m_date;
    bool m_a_risque;

public:
    Employe();

    Employe(const std::string &prenom, const std::string &nom, const std::string &date, const bool &a_risque);

    virtual ~Employe();

    virtual float calculer_salaire() const = 0;

    virtual std::string getNom() const;
};