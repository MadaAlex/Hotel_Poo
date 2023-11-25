#ifndef ETAJ_H
#define ETAJ_H

#include <iostream>
#include "../Cladire/Cladire.h"

class Etaj
{
protected:
    int id;
    Cladire* cld;
    int nr;
    bool lift;

public:
    Etaj();
    Etaj(int idd, Cladire* cldd, int nmr, bool lift_s);
    Etaj(const Etaj &etj);
    ~Etaj();

    [[nodiscard]] int getId() const;
    void setId(int x);
    [[nodiscard]] int getNr() const;
    void setNr(int x);
    [[nodiscard]] bool getLift() const;
    void setLift(bool x);


    friend std::ostream &operator<<(std::ostream &os, const Etaj &etj);
    Etaj &operator=(const Etaj &etj);
};

#endif // ETAJ_H
