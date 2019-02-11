#pragma once
#include "volaille.hpp"


class Canard : public Volaille {
public:
    Canard();

    Canard(const unsigned &id, const unsigned &masse, const unsigned &prix);

    virtual const std::string getType() const override;
};