#pragma once
#include <string>


class Volaille {
protected:
    unsigned m_id;
    float m_masse;
    float m_prix;

public:
    Volaille();

    Volaille(const unsigned &id, const unsigned &masse, const unsigned &prix);

    virtual ~Volaille();

    void setId(const unsigned &id);

    void setMasse(const float &masse);

    void setPrix(const float &prix);

    const unsigned& getId() const;

    const float& getMasse() const;

    const float& getPrix() const;

    virtual const std::string getType() const = 0;
};