#include "csac.hpp"
#include "cpoigne.hpp"
#include "cpoire.hpp"
#include "cmarche.hpp"

int main() {
    csac sac;
    cpoigne* poigne = new cpoigne;
    sac.setPoigne(poigne);
    sac.afficheMembre();
    return 0;
}