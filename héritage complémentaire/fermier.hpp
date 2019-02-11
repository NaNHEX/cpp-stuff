#pragma once
#include <vector>
#include <string>
#include "volaille.hpp"


class Fermier {
private:
    std::vector<Volaille*> m_volailles;

public:
    Fermier();

    Fermier(const std::vector<Volaille*> &volailles);

    void setVolailles(const std::vector<Volaille*> &volailles);

    const std::vector<Volaille*>& getVolailles() const;

    size_t getNbVolailles() const;

    const std::string getTypeVolaille(unsigned i) const;

    float getPrixTotal() const;
};