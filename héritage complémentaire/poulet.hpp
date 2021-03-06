#pragma once
#include "volaille.hpp"


class Poulet : public Volaille {
public:
    Poulet();

    Poulet(const unsigned &id, const unsigned &masse, const unsigned &prix);

    virtual const std::string getType() const override;
};