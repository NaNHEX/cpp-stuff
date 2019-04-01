#ifndef CMARCHE_HPP_
#define CMARCHE_HPP_
#include "csac.hpp"

class cmarche
{
private:
    csac m_sac;

public:
    cmarche();

    ~cmarche();

    const csac& getSac();

    void setSac(const csac&);

    void affiche();
};
#endif
