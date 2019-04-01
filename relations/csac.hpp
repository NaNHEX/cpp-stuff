#pragma once
#include "cpoigne.hpp"
#include "cpoire.hpp"

class cmarche;

class csac
{
private:
    cmarche m_marche;
    cpoire m_poire;
    cpoigne *m_poigne;

public:
    csac();

    ~csac();

    const cmarche& getMarche() const;

    const cpoire& getPoire() const;

    const cpoigne* const getPoigne() const;

    void setMarche(const cmarche&);

    void setPoire(const cpoire&);

    void setPoigne(cpoigne*);

    void afficheMembre();
};
